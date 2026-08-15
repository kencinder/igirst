#!/bin/bash

main_menu() {
    while true; do
        draw_header "Main Menu"
        local display_platforms=()
        for platform in "${platforms[@]}"; do
            display_platforms+=("${platform//_/ }")
        done
        generate_menu_list display_platforms "$command_all_menu_common\nX: Reload Config\nQ: Quit"
        read -rsn 1 -p "$choose" choice
			case "${choice,,}" in
            [1-9])
                if [ "$choice" -le "${#platforms[@]}" ]; then
                    selected_platform="${platforms[$((choice - 1))]}"
                    platform_menu "$selected_platform"
                    if [ $? -eq 5 ]; then
                        system_menu "${selected_platform,,}"
                    fi
                fi
                ;;
            r) main_command_all "command_report" ;;
            c) main_command_all "command_copy" ;;
            m) main_command_all "command_move" ;;
			x) printf "\n\nReloading IGIR Shell Tools Config\n" && sleep 1
            	exec env -i TERM="$TERM" "$BASH" "$igirst_dir/igirst.sh"
                ;;
            *) menu_quit_invalid "$choice" ;;
        esac
    done
}

platform_menu() {
    platform="${1}"
    platform_lower="${platform,,}"
    current_platform="$platform"
systems_ref="${platform_lower}_systems[@]"
current_systems=("${!systems_ref}")
vars_ref="${platform_lower}_system_vars[@]"
current_vars=("${!vars_ref}")
max_choice="${#current_systems[@]}"
    while true; do
		if [ "$menu_target" = "main" ]; then
            return 10
        fi
        draw_header "$platform"
        current_systems_arr_name="${platform_lower}_systems"
        generate_menu_list "$current_systems_arr_name" "$command_all_menu_common\n$menu_main_quit"
        read -rsn 1 -p "$choose" choice
        case "${choice,,}" in
			[0-9]*)
                if [ "$choice" -ge 1 ] && [ "$choice" -le "$max_choice" ]; then
                    idx=$((choice - 1))
                    system_prefix="${current_vars[$idx]}"
                    current_system_idx="$idx"
                    previous_menu="platform_menu"
                    return 5 
                fi
                ;;
            r) system_command_all "$platform_lower" "command_report" ;;
            c) system_command_all "$platform_lower" "command_copy" ;;
            m) system_command_all "$platform_lower" "command_move" ;;
            t) return 10 ;;
            *) menu_quit_invalid "$choice" ;;
        esac
    done
}

system_menu() {
    clear
    local platform_lower="${1}"
    command_menu_set
    return $?
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
        printf '%b\n%s\n\n' "$command_menu_list" "$menu_main_quit"
        read -rsn 1 -p "$choose" choice
        case "${choice,,}" in
            r) command_type "command_report"; break ;;
            c) command_type "command_copy"; break ;;
            m) command_type "command_move"
                [ $? -eq 1 ] && continue
                break 
                ;;
            b) if [ "$previous_menu" = "platform_menu" ]; then
                   "$previous_menu" "$active_platform"
               else
                   "$previous_menu"
               fi ;;
            t) export menu_target="main" && return 10 ;;
            *) menu_quit_invalid "$choice" ;;
        esac
    done
}
