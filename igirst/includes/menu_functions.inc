#!/bin/bash

#			### Common menu functions

# Create DAT filename Variable
create_dat_filename() {
	dat_path_strip="${dat##*/}"
	dat_filename="${dat_path_strip%.*}"
	dat_filename_nop="${dat_filename//\(*\)}"
	dat_filename_no_parentheses="${dat_filename_nop% }"
	source "igirst.cfg"
	system_vars
}

# Checks if `clean` is set without `--clean-backup` and warns
backup_check() {
	if [[ "$command_add" == *"clean"* ]]; then
		if [[ "$command_add" != *"--clean-backup"* ]]; then
			clear
			printf '%s' "${!current_menu_header} $backup_prompt"
			read -rsn 1 -p "$backup_continue" key
			if [[ $key == "y" || $key == "Y" ]]; then
				return 0
			else
				command_menu
				return 1
			fi
		fi
	fi
}

# Adds any Additional Commands in `igirst.cfg` for a system
command_add_check() {
	if [[ -n "$command_add" ]]; then
    	command+="$command_add "
	else
		:
	fi
}

command_copy() {
	command="copy "
	command_add_check
	command+="report"
	output="$output_copy"
	backup_check
}

command_menu_set() {
	while true; do
		command_menu
		$command_type
		clear
		7z_handler
		clear
		command_igir
	done
}

command_move() {
	command="move "
	command_add_check
	command+="report"
	output="$output_move"
	backup_check
}

command_report() {
	command="report"
	output="$input"
}

# Sets up system specifics for the command menu and Final IGIR Command
command_set() {
	system_vars
	var_check
	create_dat_filename
	command_menu_set
}

# Final IGIR command
command_igir() {
	./"$igir_binary" $command --dat "${dat}" --input "$input" --output "$output" $options -X "$exclude" --report-output "$report"
	printf "\n"
	read -rsn 1 -p "$continue"
}

menu_header_choice() {
    clear
    parent_menu="${FUNCNAME[1]}"
    if [ "$parent_menu" = "platform_menu" ] && [ -n "$platform_lower" ]; then
        eval "printf '%s\n' \"\$${platform_lower}_menu_header \$${platform_lower}_menu_list\""
    else
        eval "printf '%s\n' \"\$${parent_menu}_menu_header \$${parent_menu}_menu_list\""
    fi
    read -rsn 1 -p "$choose" choice
}

menu_quit_invalid() {
    case "$1" in
		q)     printf '%s' "$quit"; sleep 1; clear && exit ;;
		"")    printf '%s' "$empty_choice"; sleep 1 ;;
		*)     printf '%s' "$invalid_choice $choice"; sleep 1 ;;
    esac
}

# Sets the variables used in Final IGIR Command to system specific ones
cmd_vars=(command_add dat input output_copy output_move options exclude report)
system_vars() {
	for ((i=0; i<${#cmd_vars[@]}; i++)); do
    	eval "${cmd_vars[i]}=${system[i]}"
	done
}

# Checks that Mandatory Variables in `igirst.cfg` are set for the system being used
var_check() {
    missing=0
    vars=(dat:"DAT" input:"INPUT" output_copy:"OUTPUT COPY" output_move:"OUTPUT MOVE" report:"REPORT")
    for item in "${vars[@]}"; do
        var_name="${item%%:*}"
        display_name="${item#*:}"
		if [ -z "${!var_name}" ]; then
			printf '%s\n\n' "$display_name $var_missing"
			missing=1
		fi
    done
    if [ "$missing" -eq 1 ]; then
        read -rsn 1 -p "$continue"
        "$previous_menu"
    fi
}


#			### Manufacturer/Platform Functions to Process all Systems at once

	# Process all Systems for IGIR REPORT, COPY or MOVE commands
	# Iterates through all system variables instead of using each systems menu function, cuts out printing menu headers and commmand menu
	# Mandatory variable checks are skipped, any system with an unset variable will silently fail without issue
	# Skips past Continue normally shown after Final IGIR Command completes and returns to Atari Menu when finished

	command_all_common() {
		system_vars
		create_dat_filename
		$command_type
		clear
		7z_handler
		clear
		command_igir <<< 1
	}

	main_command_all() {
    for platform in "${platforms[@]}"; do
        platform_lower="${platform,,}"
        system_command_all "$platform_lower"
    done
	}

	system_command_all() {
    platform_lower="${1}"
    systems_ref="${platform_lower}_systems[@]"
    current_systems=("${!systems_ref}")
	vars_ref="${platform_lower}_system_vars[@]"
    current_vars=("${!vars_ref}")
    for i in "${!current_systems[@]}"; do
        cmd_var="${current_systems[i]}"
        system_prefix="${current_vars[i]}"
        system=("${cmd_vars[@]/#/\$${system_prefix}}")
        command_all_common
    done
	}	
