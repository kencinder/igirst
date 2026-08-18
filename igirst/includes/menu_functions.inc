#!/bin/bash

#			### Common menu functions

load_system_vars() {
    local dynamic_input="${system_prefix}_input"
    input="${!dynamic_input}"
    local dynamic_dat="${system_prefix}_dat"
    dat="${!dynamic_dat}"
    local dynamic_options="${system_prefix}_options"
    options="${!dynamic_options}"
    local dynamic_exclude="${system_prefix}_exclude"
    exclude="${!dynamic_exclude}"
    local dynamic_report="${system_prefix}_report"
    report="${!dynamic_report}"
    local dynamic_copy="${system_prefix}_output_copy"
    output_copy="${!dynamic_copy}"
    local dynamic_move="${system_prefix}_output_move"
    output_move="${!dynamic_move}"
}

# Create DAT filename Variable
create_dat_filename() {
    dat="${1}"
    dat_path_strip="${dat##*/}"
    dat_filename="${dat_path_strip%.*}"
    dat_filename_nop="${dat_filename//\(*\)}"
    dat_filename_no_parentheses="${dat_filename_nop% }"
	local var_report="${system_prefix}_report"
    eval "$var_report=\"${!var_report}\""
}

# Checks if `clean` is set without `--clean-backup` and warns
backup_check() {
    local target_add="${system_prefix}_command_add"
    local direct_add="${!target_add}"

    if [[ "$direct_add" == *"clean"* ]] && [[ "$direct_add" != *"--clean-backup"* ]]; then
        clear
        printf '%s\n' "$backup_prompt"
        read -rsn 1 -p "$backup_continue" key
        if [[ $key == "y" || $key == "Y" ]]; then
            return 0
        else
            command_menu
            return 1
        fi
    fi
}

# Adds any Additional Commands in `igirst.cfg` for a system
command_add_check() {
    if [[ -z "$direct_add" && -n "$command_add" ]]; then
        direct_add="$command_add"
    elif [[ -z "$direct_add" ]]; then
        local target_add="${system_prefix}_command_add"
        direct_add="${!target_add}"
    fi
    if [[ -n "$direct_add" ]]; then
        command+=" $direct_add"
    else
        :
    fi
}

command_type() {
    local action="${1}"
	command="" 
    runtime_output=""
    declare -g command
    declare -g runtime_output
    local check_action
    check_action=$(echo "$action" | tr -d '[:space:]')
    case "${check_action,,}" in
        "command_report"|"r")
            command="report"
            local input_var="${system_prefix}_input"
            local out_move_var="${system_prefix}_output_move"
            runtime_output="${!out_move_var}"
            ;;
        "command_copy"|"c"|*"copy"*)
            command="copy"
            local out_copy_var="${system_prefix}_output_copy"
            runtime_output="${!out_copy_var}" 
            backup_check
            command_add_check
            command+=" report"
            ;;
        "command_move"|"m"|*"move"*)
            command="move"
            local out_move_var="${system_prefix}_output_move"
            runtime_output="${!out_move_var}"
            backup_check
            command_add_check
            command+=" report"
            ;;
    esac
}

command_menu_set() {
    local var_dat="${system_prefix}_dat"
    local var_input="${system_prefix}_input"
    local var_copy="${system_prefix}_output_copy"
    local var_move="${system_prefix}_output_move"
    local var_report="${system_prefix}_report"
    local dat="${!var_dat}"
	create_dat_filename "$dat"
    local input="${!var_input}"
    local output_copy="${!var_copy}"
    local output_move="${!var_move}"
    local report="${!var_report}"
    var_check || return 1
    while true; do
        command_menu
		local code=$?
        if [ $code -eq 5 ] || [ $code -eq 10 ]; then
            return $code
        fi
        clear
        7z_handler
        clear
		create_dat_filename "$dat"
        command_igir
    done
}

command_igir() {
    local var_dat="${system_prefix}_dat"
    local var_input="${system_prefix}_input"
    local var_options="${system_prefix}_options"
    local var_exclude="${system_prefix}_exclude"
    local var_report="${system_prefix}_report"
    local dat="${!var_dat}"
    local input="${!var_input}"
    local options="${!var_options}"
    local exclude="${!var_exclude}"
    local report="${!var_report}"
    local extra_input=""
    if [[ -n "$input" && -n "$runtime_output" && "$input" != "$runtime_output" ]]; then
        extra_input="--input $runtime_output"
    fi
    ./"$igir_binary" $command --dat "$dat" --input "$input" $extra_input --output "$runtime_output" $options -X "$exclude" --report-output "$report"
    printf "\n"
    if [[ "$batch_mode" != "true" ]]; then
        read -rsn 1 -p "$continue"
    fi
}

draw_header() {
    title="${1}"
    line="****************************************************"
    width=${#line}
    inner_width=$((width - 4))
    pad_left="            "
    brand="IGIR SHELL TOOLS"
    brand_pad=$(( (inner_width - ${#brand}) / 2 ))
    brand_rem=$(( inner_width - brand_pad ))
    title_pad=$(( (inner_width - ${#title}) / 2 ))
    title_rem=$(( inner_width - title_pad ))
    clear
    printf '%s%s\n' "$pad_left" "$line"
    printf "%s* %-${inner_width}s *\n" "$pad_left" ""
    printf "%s* %${brand_pad}s%-${brand_rem}s *\n" "$pad_left" "" "$brand"
    printf "%s* %-${inner_width}s *\n" "$pad_left" ""
    printf "%s* %${title_pad}s%-${title_rem}s *\n" "$pad_left" "" "$title"
    printf "%s* %-${inner_width}s *\n" "$pad_left" ""
    printf '%s%s\n\n' "$pad_left" "$line"
}

generate_menu_list() {
    declare -n items=$1
    common_options=$2
    output=""
    for i in "${!items[@]}"; do
        output+="$((i + 1)): ${items[i]}\n"
    done
    output+="$common_options"
    printf "%b\n\n" "$output"
}

menu_quit_invalid() {
    case "$1" in
		q)     printf '\n\n%s' "Exiting IGIR Shell Tools..."; sleep 1; clear && exit ;;
		"")    printf '\n\n%s' "No choice entered"; sleep 1 ;;
		*)     printf '\n\n%s' "Invalid option: $choice"; sleep 1 ;;
    esac
}

var_check() {
    local missing=0
    local vars=(
        "dat:DAT"
        "input:INPUT"
        "output_copy:OUTPUT COPY"
        "output_move:OUTPUT MOVE"
        "report:REPORT"
    )
    local item
    for item in "${vars[@]}"; do
        local base_var_name="${item%%:*}"
        local display_name="${item#*:}"
        if [ -z "${!base_var_name}" ]; then
            printf '%s\n\n' "$display_name $var_missing"
            missing=1
        fi
    done
    if [ "$missing" -eq 1 ]; then
        read -rsn 1 -p "$continue"
        return 1
    fi
    return 0
}


#			### Manufacturer/Platform Functions to Process all Systems at once

	# Process all Systems for IGIR REPORT, COPY or MOVE commands
	# Iterates through all system variables instead of using each systems menu function, cuts out printing menu headers and commmand menu
	# Mandatory variable checks are skipped, any system with an unset variable will silently fail without issue
	# Skips past Continue normally shown after Final IGIR Command completes and returns to Atari Menu when finished


command_all_common() {
    local action_mode="${1}"
    local var_dat="${system_prefix}_dat"
    local var_input="${system_prefix}_input"
    local var_copy="${system_prefix}_output_copy"
    local var_move="${system_prefix}_output_move"
    local var_report="${system_prefix}_report"
    dat="${!var_dat}"
    input="${!var_input}"
    output_copy="${!var_copy}"
    output_move="${!var_move}"
    report="${!var_report}"
    declare -g direct_add
    eval "direct_add=\"\${${system_prefix}_command_add}\""
    declare -g runtime_output
    if [[ "$action_mode" == *"copy"* || "$action_mode" == "c" ]]; then
        runtime_output="$output_copy"
    elif [[ "$action_mode" == *"move"* || "$action_mode" == "m" ]]; then
        runtime_output="$output_move"
    else
        runtime_output="$input"
    fi
    create_dat_filename "$dat"
    command_type "$action_mode"
    clear
    7z_handler
    clear
    command_igir
}

main_command_all() {
    local action_mode="${1}"
    declare -g batch_mode="true"
    unset system_prefix current_system_idx
    local platform
    for platform in "${platforms[@]}"; do
        system_command_all "${platform,,}" "$action_mode"
    done
    unset batch_mode system_prefix current_system_idx
}

system_command_all() {
    local platform_lower="${1}"
    local action_mode="${2}"
    local sys_batch_ref="${platform_lower}_systems[@]"
    local current_systems=("${!sys_batch_ref}")
    local sys_batch_vars="${platform_lower}_system_vars[@]"
    local current_vars=("${!sys_batch_vars}")
    local idx_batch
    for idx_batch in "${!current_systems[@]}"; do
        system_prefix="${current_vars[idx_batch]}"
        current_system_idx="$idx_batch"
        command_all_common "$action_mode"
    done
}
