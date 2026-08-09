#!/bin/bash

main_menu() {
    while true; do
        draw_header "Main Menu"
        printf '%s\n' "$main_menu_list"
        read -rsn 1 -p "$choose" choice
        case "${choice,,}" in
            [1-9])
                if [ "$choice" -le "${#platforms[@]}" ]; then
                    selected_platform="${platforms[$((choice - 1))]}"
                    platform_menu "$selected_platform"
                    continue
                fi
                ;;
            r) command_type="command_report"; main_command_all ;;
            c) command_type="command_copy"; main_command_all ;;
            m) command_type="command_move"; main_command_all ;;
            q) printf '%s' "$quit"; sleep 1; clear && exit ;;
            "") printf '%s' "$empty_choice"; sleep 1 ;;
            *) printf '%s' "$invalid_choice $choice"; sleep 1 ;;
        esac
    done
}

platform_menu() {
    platform="${1}"
    platform_lower="${platform,,}"
    current_platform="$platform" 
    systems_ref="${platform_lower}_systems[@]"
    current_systems=("${!systems_ref}")
    max_choice="${#current_systems[@]}"
    vars_ref="${platform_lower}_system_vars[@]"
    current_vars=("${!vars_ref}")
    while true; do
        draw_header "$platform"
		list_ref="${platform_lower}_menu_list"
        printf '%s\n' "${!list_ref}" 
		read -rsn 1 -p "$choose" choice
        case "${choice,,}" in
            [0-9]*)
                if [ "$choice" -ge 1 ] && [ "$choice" -le "$max_choice" ]; then
                    idx=$((choice - 1))
                    system_prefix="${current_vars[$idx]}"
                    previous_menu="platform_menu"
                    system_menu "$platform_lower" "$system_prefix" "$idx"
					continue
                fi
                ;;
            r) command_type="command_report"; system_command_all "$platform_lower" ;;
            c) command_type="command_copy";   system_command_all "$platform_lower" ;;
            m) command_type="command_move";   system_command_all "$platform_lower" ;;
            t) main_menu ;;
            *) menu_quit_invalid "$choice" ;;
        esac
    done
}

system_menu() {
    clear
    platform_lower="${1}"
    system_prefix="${2}"
	current_system_idx="${3}"
    clean_name="${system_prefix//_/}"
    current_menu_header="${platform_lower}_${clean_name}_menu_header"
    system=("${cmd_vars[@]/#/\$${system_prefix}}")
    command_set
}

command_menu() {
    active_platform="${1:-$current_platform}"
    platform_lower="${active_platform,,}"
    
    while true; do
        clear
        disp_platform="${active_platform^}"
        sys_array_ref="${platform_lower}_systems[$current_system_idx]"
        disp_system="${!sys_array_ref}"
        full_title="$disp_platform $disp_system"
        draw_header "$full_title"
        printf '%s' "$command_menu_list"
        read -rsn 1 -p "$choose" choice
        case "${choice,,}" in
            r) command_type="command_report"; break ;;
            c) command_type="command_copy"; break ;;
            m) command_type="command_move"; break ;;
            b) if [ "$previous_menu" = "platform_menu" ]; then 
				   "$previous_menu" "$active_platform"
			   else
			   	   "$previous_menu"
			   fi
			   ;;
            t) main_menu ;;
            *) menu_quit_invalid "$choice" ;;
        esac
    done
}
