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
        R|r)
			command_report
            break
            ;;
        C|c)
			command_copy
            break
            ;;
        M|m)
			command_move
            break
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


#			### System Specific Menus

#===# Atari #===#

	atari_2600_menu() {
		clear
		current_menu="atari_2600_menu"
		current_menu_header="$atari_2600_menu_header"
		system=("${cmd_vars[@]/#/\$_2600_}")
		command_set
	}
	atari_5200_menu() {
		clear
		current_menu="atari_5200_menu"
		current_menu_header="$atari_5200_menu_header"
		system=("${cmd_vars[@]/#/\$_5200_}")
		command_set
	}
	atari_7800_menu() {
		clear
		current_menu="atari_7800_menu"
		current_menu_header="$atari_7800_menu_header"
		system=("${cmd_vars[@]/#/\$_7800_}")
		command_set
	}
	atari_jaguar_menu() {
		clear
		current_menu="atari_jaguar_menu"
		current_menu_header="$atari_jaguar_menu_header"
		system=("${cmd_vars[@]/#/\$jaguar_}")
		command_set
	}
	atari_lynx_menu() {
		clear
		current_menu="atari_lynx_menu"
		current_menu_header="$atari_lynx_menu_header"
		system=("${cmd_vars[@]/#/\$lynx_}")
		command_set
	}

#===# NEC #===#

	nec_tg16_menu() {
		clear
		current_menu="nec_tg16_menu"
		current_menu_header="$nec_tg16_menu_header"
		system=("${cmd_vars[@]/#/\$tg16_}")
		command_set
	}

#===# Nintendo #===#

	nintendo_3ds_menu() {
		clear
		current_menu="nintendo_3ds_menu"
		current_menu_header="$nintendo_3ds_menu_header"
		system=("${cmd_vars[@]/#/\$_3ds_}")
		command_set
	}
	nintendo_64_menu() {
		clear
		current_menu="nintendo_64_menu"
		current_menu_header="$nintendo_64_menu_header"
		system=("${cmd_vars[@]/#/\$_64_}")
		command_set
	}
	nintendo_ds_menu() {
		clear
		current_menu="nintendo_ds_menu"
		current_menu_header="$nintendo_ds_menu_header"
		system=("${cmd_vars[@]/#/\$ds_}")
		command_set
	}
	nintendo_gb_menu() {
		clear
		current_menu="nintendo_gb_menu"
		current_menu_header="$nintendo_gb_menu_header"
		system=("${cmd_vars[@]/#/\$gb_}")
		command_set
	}
	nintendo_gba_menu() {
		clear
		current_menu="nintendo_gba_menu"
		current_menu_header="$nintendo_gba_menu_header"
		system=("${cmd_vars[@]/#/\$gba_}")
		command_set
	}
	nintendo_gbc_menu() {
		clear
		current_menu="nintendo_gbc_menu"
		current_menu_header="$nintendo_gbc_menu_header"
		system=("${cmd_vars[@]/#/\$gbc_}")
		command_set
	}
	nintendo_nes_menu() {
		clear
		current_menu="nintendo_nes_menu"
		current_menu_header="$nintendo_nes_menu_header"
		system=("${cmd_vars[@]/#/\$nes_}")
		command_set
	}
	nintendo_snes_menu() {
		clear
		current_menu="nintendo_snes_menu"
		current_menu_header="$nintendo_snes_menu_header"
		system=("${cmd_vars[@]/#/\$snes_}")
		command_set
	}
	nintendo_vb_menu() {
		clear
		current_menu="nintendo_vb_menu"
		current_menu_header="$nintendo_vb_menu_header"
		system=("${cmd_vars[@]/#/\$vb_}")
		command_set
	}
			
#===# SEGA #===#

	sega_32x_menu() {
		clear
		current_menu="sega_32x_menu"
		current_menu_header="$sega_32x_menu_header"
		system=("${cmd_vars[@]/#/\$_32x_}")
		command_set
	}
	sega_gg_menu() {
		clear
		current_menu="sega_gg_menu"
		current_menu_header="$sega_gg_menu_header"
		system=("${cmd_vars[@]/#/\$gg_}")
		command_set
	}
	sega_gen_menu() {
		clear
		current_menu="sega_gen_menu"
		current_menu_header="$sega_gen_menu_header"
		system=("${cmd_vars[@]/#/\$gen_}")
		command_set
	}
	sega_ms_menu() {
		clear
		current_menu="sega_ms_menu"
		current_menu_header="$sega_ms_menu_header"
		system=("${cmd_vars[@]/#/\$ms_}")
		command_set
	}

#===# SNK #===#

	snk_ngpc_menu() {
		clear
		current_menu="snk_ngpc_menu"
		current_menu_header="$snk_ngpc_menu_header"
		system=("${cmd_vars[@]/#/\$ngpc_}")
		command_set
	}
