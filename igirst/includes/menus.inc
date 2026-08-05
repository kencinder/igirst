#!/bin/bash

main_menu() {
while true; do
    clear
    printf '%s' "$main_menu_header $main_menu_list"
    read -rsn 1 -p "Select an option: " choice

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
        R|r)
			command_type="command_report"
            command_all_main
            ;;
        C|c)
			command_type="command_copy"
            command_all_main
            ;;
        M|m)
			command_type="command_move"
            command_all_main
            ;;
        Q|q)
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
    printf '%s' "$current_menu_header $command_menu_list"
    read -rsn 1 -p "Select an option: " choice

    if [ -z "$choice" ]; then
        choice=""
    fi

    case $choice in
        R)
			command_report
            break
            ;;
        C)
			command_copy
            break
            ;;
        M)
			command_move
            ;;
        B|b)
            "$previous_menu"
            ;;
        T|t)
            main_menu
            ;;
        Q|q)
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
    printf '%s' "$atari_menu_header $atari_menu_list"
    read -rsn 1 -p "Select an option: " choice

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
        R|r)
			command_type="command_report"
            atari_command_all
            ;;
        C|c)
			command_type="command_copy"
            atari_command_all
            ;;
        M|m)
			command_type="command_move"
            atari_command_all
            ;;
        T|t)
            main_menu
            ;;
        Q|q)
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
    printf '%s' "$nec_menu_header $nec_menu_list"
    read -rsn 1 -p "Select an option: " choice

    if [ -z "$choice" ]; then
        choice=""
    fi

    case $choice in
        1)
            nec_tg16_menu
            ;;
        R|r)
			command_type="command_report"
            nec_command_all
            ;;
        C|c)
			command_type="command_copy"
            enc_command_all
            ;;
        M|m)
			command_type="command_move"
            nec_command_all
            ;;
        T|t)
            main_menu
            ;;
        Q|q)
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
    printf '%s' "$nintendo_menu_header $nintendo_menu_list"
    read -rsn 1 -p "Select an option: " choice

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
        R|r)
			command_type="command_report"
            nintendo_command_all
            ;;
        C|c)
			command_type="command_copy"
            nintendo_command_all
            ;;
        M|m)
			command_type="command_move"
            nintendo_command_all
            ;;
        T|t)
            main_menu
            ;;
        Q|q)
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
    printf '%s' "$sega_menu_header $sega_menu_list"
    read -rsn 1 -p "Select an option: " choice

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
        R|r)
			command_type="command_report"
            sega_command_all
            ;;
        C|c)
			command_type="command_copy"
            sega_command_all
            ;;
        M|m)
			command_type="command_move"
            sega_command_all
            ;;
        T|t)
            main_menu
            ;;
        Q|q)
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
    printf '%s' "$snk_menu_header $snk_menu_list"
    read -rsn 1 -p "Select an option: " choice

    if [ -z "$choice" ]; then
        choice=""
    fi

    case $choice in
        1)
            snk_ngpc_menu
            ;;
        R|r)
			command_type="command_report"
            snk_command_all
            ;;
        C|c)
			command_type="command_copy"
            snk_command_all
            ;;
        M|m)
			command_type="command_move"
            snk_command_all
            ;;
        T|t)
            main_menu
            ;;
        Q|q)
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
