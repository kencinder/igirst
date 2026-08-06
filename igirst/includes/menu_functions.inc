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
    		printf '%s' "$current_menu_header $backup_prompt"
			while true; do
				read -rsn 1 -p "$backup_continue" key
				if [[ $key == "y" || $key == "Y" ]]; then
					break
				else
					$current_menu
				fi
			done
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
	printf '%s' "$current_menu_header"
	var_check
	create_dat_filename
	command_menu
	clear
	7z_handler
	clear
	command_igir
	$current_menu
}

# Final IGIR command
command_igir() {
	./"$igir_binary" $command --dat "${dat}" --input "$input" --output "$output" $options -X "$exclude" --report-output "$report"
	printf "\n"
	read -rsn 1 -p "$continue"
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
		$current_menu
	}
	command_all_main() {
		atari_command_all
		nec_command_all
		nintendo_command_all
		sega_command_all
		snk_command_all
	}
	atari_command_all() {
		atari_systems=(2600 5200 7800 jaguar lynx)
		atari_cmd_vars=(_2600_ _5200_ _7800_ jaguar_ lynx_)
		for i in "${!atari_systems[@]}"; do
			cmd_var="${atari_systems[i]}"
			system=("${cmd_vars[@]/#/\$${atari_cmd_vars[i]}}")
			command_all_common
		done
	}
	nec_command_all() {
		nec_systems=(TG16)
		nec_cmd_vars=(tg16_)
		for i in "${!nec_systems[@]}"; do
			cmd_var="${nec_systems[i]}"
			system=("${cmd_vars[@]/#/\$${nec_cmd_vars[i]}}")
			command_all_common
		done
	}
	nintendo_command_all() {
		nintendo_systems=(3DS 64 DS GB GBA GBC NES SNES VB)
		nintendo_cmd_vars=(_3ds_ _64_ ds_ gb_ gba_ gbc_ nes_ snes_ vb_)
		for i in "${!nintendo_systems[@]}"; do
			cmd_var="${nintendo_systems[i]}"
			system=("${cmd_vars[@]/#/\$${nintendo_cmd_vars[i]}}")
			command_all_common
		done
	}
	sega_command_all() {
		sega_systems=(32X GG GEN MS)
		sega_cmd_vars=(_32x_ gg_ gen_ ms_)
		for i in "${!sega_systems[@]}"; do
			cmd_var="${sega_systems[i]}"
			system=("${cmd_vars[@]/#/\$${sega_cmd_vars[i]}}")
			command_all_common
		done
	}
	snk_command_all() {
		snk_systems=(NGPC)
		snk_cmd_vars=(ngpc_)
		for i in "${!snk_systems[@]}"; do
			cmd_var="${snk_systems[i]}"
			system=("${cmd_vars[@]/#/\$${snk_cmd_vars[i]}}")
			command_all_common
		done
	}
