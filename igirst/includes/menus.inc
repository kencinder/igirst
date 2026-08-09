#!/bin/bash

main_menu() {
    while true; do
        clear
        printf '%s\n' "$main_menu_header $main_menu_list"
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
        menu_header_choice
        case "${choice,,}" in
            [0-9]*)
                if [ "$choice" -ge 1 ] && [ "$choice" -le "$max_choice" ]; then
                    idx=$((choice - 1))
                    system_prefix="${current_vars[$idx]}"
                    previous_menu="platform_menu"
                    system_menu "$platform_lower" "$system_prefix"
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
    clean_name="${system_prefix//_/}"
    current_menu_header="${platform_lower}_${clean_name}_menu_header"
    system=("${cmd_vars[@]/#/\$${system_prefix}}")
    command_set
}

command_menu() {
    active_platform="${1:-$current_platform}"
    while true; do
        clear
        printf '%s' "${!current_menu_header} $command_menu_list"
        read -rsn 1 -p "$choose" choice
        case "${choice,,}" in
            r) command_type="command_report"; break ;;
            c) command_type="command_copy"; break ;;
            m) command_type="command_move"; break ;;
            b) 
                if [ "$previous_menu" = "platform_menu" ]; then
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
