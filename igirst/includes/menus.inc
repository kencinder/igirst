#!/bin/bash

main_menu() {
while true; do
    clear
    printf '%s' "$main_menu_header"
    printf '%s' "$main_menu_list"
    read -r -p "Select an option: " choice

    if [ -z "$choice" ]; then
        choice=""
    fi

    case $choice in
        1)
            atari_menu
            ;;
        2)
            nec_menu
            ;;
        3)
            nintendo_menu
            ;;
        4)
            sega_menu
            ;;
        5)
            snk_menu
            ;;
        0)
            printf '%s' "$quit"
            sleep 1
            clear && exit
            ;;
        "")
            printf '%s' "$empty_choice"
            sleep 1
            ;;
        *)
            printf '%s' "$invalid_choice $choice"
            sleep 1
            ;;
        esac
    done
}

command_menu() {
while true; do
    clear
    printf '%s' "$current_menu_header"
    printf '%s' "$command_menu_list"
    read -r -p "Select an option: " choice

    if [ -z "$choice" ]; then
        choice=""
    fi

    case $choice in
        1)
            backup=""
            command="report"
            break
            ;;
        2)
            command="copy report"
			eval backup_choice
            break
            ;;
        3)
            command="move report"
			eval backup_choice
            break
            ;;
        4)
            eval "$previous_menu"
            ;;
        5)
            main_menu
            ;;
        0)
            printf '%s' "$quit"
            sleep 1
            clear && exit
            ;;
        "")
            printf '%s' "$empty_choice"
            sleep 1
            ;;
        *)
            printf '%s' "$invalid_choice $choice"
            sleep 1
            ;;
        esac
    done
}

command_yes_no() {
while true; do
    clear
    printf '%s' "$current_menu_header"
    printf '%s' "$backup_prompt $command_yes_no_list"
    read -r -p "Select an option: " choice

    if [ -z "$choice" ]; then
        choice=""
    fi

    case $choice in
        1)
            yes_no="yes"
            break
            ;;
        2)
            yes_no="no"
            break
            ;;
        3)
            eval "$current_menu"
            break
            ;;
		4)
			main_menu
			;;
		0)
			printf '%s' "$quit"
			sleep 1
			clear && exit
			;;
		"")
			printf '%s' "$empty_choice"
			sleep 1
			;;
		*)
			printf '%s' "$invalid_choice $choice"
			sleep 1
			;;
        esac
    done
}

atari_menu() {
while true; do
    clear
	previous_menu="atari_menu"
    printf '%s' "$atari_menu_header"
    printf '%s' "$atari_menu_list"
    read -r -p "Select an option: " choice

    if [ -z "$choice" ]; then
        choice=""
    fi

    case $choice in
        1)
            atari_2600_menu
            ;;
        2)
            atari_5200_menu
            ;;
        3)
            atari_7800_menu
            ;;
        4)
            atari_jaguar_menu
            ;;
        5)
            atari_lynx_menu
            ;;
        6)
            main_menu
            ;;
        0)
            printf '%s' "$quit"
            sleep 1
            clear && exit
            ;;
        "")
            printf '%s' "$empty_choice"
            sleep 1
            ;;
        *)
            printf '%s' "$invalid_choice $choice"
            sleep 1
            ;;
        esac
    done
}

nec_menu() {
while true; do
    clear
	previous_menu="nec_menu"
    printf '%s' "$nec_menu_header"
    printf '%s' "$nec_menu_list"
    read -r -p "Select an option: " choice

    if [ -z "$choice" ]; then
        choice=""
    fi

    case $choice in
        1)
            nec_tg16_menu
            ;;
        2)
            main_menu
            ;;
        0)
            printf '%s' "$quit"
            sleep 1
            clear && exit
            ;;
        "")
            printf '%s' "$empty_choice"
            sleep 1
            ;;
        *)
            printf '%s' "$invalid_choice $choice"
            sleep 1
            ;;
        esac
    done
}

nintendo_menu() {
while true; do
    clear
	previous_menu="nintendo_menu"
    printf '%s' "$nintendo_menu_header"
    printf '%s' "$nintendo_menu_list"
    read -r -p "Select an option: " choice

    if [ -z "$choice" ]; then
        choice=""
    fi

    case $choice in
        1)
            nintendo_3ds_menu
            ;;
        2)
            nintendo_64_menu
            ;;
        3)
            nintendo_ds_menu
            ;;
        4)
            nintendo_gb_menu
            ;;
        5)
            nintendo_gba_menu
            ;;
        6)
            nintendo_gbc_menu
            ;;
        7)
            nintendo_nes_menu
            ;;
        8)
            nintendo_snes_menu
            ;;
        9)
			nintendo_vb_menu
            ;;
        10)
            main_menu
            ;;
        0)
            printf '%s' "$quit"
            sleep 1
            clear && exit
            ;;
        "")
            printf '%s' "$empty_choice"
            sleep 1
            ;;
        *)
            printf '%s' "$invalid_choice $choice"
            sleep 1
            ;;
        esac
    done
}

sega_menu() {
while true; do
    clear
	previous_menu="sega_menu"
    printf '%s' "$sega_menu_header"
    printf '%s' "$sega_menu_list"
    read -r -p "Select an option: " choice

    if [ -z "$choice" ]; then
        choice=""
    fi

    case $choice in
        1)
            sega_32x_menu
            ;;
        2)
            sega_gg_menu
            ;;
        3)
            sega_gen_menu
            ;;
        4)
            sega_ms_menu
            ;;
        5)
            main_menu
            ;;
        0)
            printf '%s' "$quit"
            sleep 1
            clear && exit
            ;;
        "")
            printf '%s' "$empty_choice"
            sleep 1
            ;;
        *)
            printf '%s' "$invalid_choice $choice"
            sleep 1
            ;;
        esac
    done
}

snk_menu() {
while true; do
    clear
	previous_menu="snk_menu"
    printf '%s' "$snk_menu_header"
    printf '%s' "$snk_menu_list"
    read -r -p "Select an option: " choice

    if [ -z "$choice" ]; then
        choice=""
    fi

    case $choice in
        1)
            snk_ngpc_menu
            ;;
        2)
            main_menu
            ;;
        0)
            printf '%s' "$quit"
            sleep 1
            clear && exit
            ;;
        "")
            printf '%s' "$empty_choice"
            sleep 1
            ;;
        *)
            printf '%s' "$invalid_choice $choice"
            sleep 1
            ;;
        esac
    done
}
