main_menu() {
while true; do
    clear
    printf "$main_menu_header"
    printf "$main_menu_list"
    read -p "Select an option: " choice

    if [ -z "$choice" ]; then
        choice=""
    fi

    case $choice in
        1)
            exec ./scripts/atari.sh
            ;;
        2)
            exec ./scripts/nec.sh
            ;;
        3)
            exec ./scripts/nintendo.sh
            ;;
        4)
            exec ./scripts/sega.sh
            ;;
        5)
            exec ./scripts/snk.sh
            ;;
        0)
            printf "$quit"
            sleep 1
            clear && exit
            ;;
        "")
            printf "$empty_choice"
            sleep 1
            ;;
        *)
            printf "$invalid_choice $choice"
            sleep 1
            ;;
        esac
    done
}

command_menu() {
while true; do
    clear
    printf "$menu_header"
    printf "$command_menu_list"
    read -p "Select an option: " choice

    if [ -z "$choice" ]; then
        choice=""
    fi

    case $choice in
        1)
            command="report"
            break
            ;;
        2)
            command="copy report"
            yes_no_prompt="$backup_prompt"
            clear
            command_yes_no
            if [[ "$yes_no" == "yes" ]]; then
                command+=" clean --clean-backup $backup"
                clear
                printf "$menu_header"
                printf "$backups_on"
                    while true; do
                        read -n 1 -s -r -p "$backup_continue" key
                            if [[ $key == "y" || $key == "Y" ]]; then
                                break
                            else
                                exec "$current_menu"
                            fi
                    done
            elif [[ "$yes_no" == "no" ]]; then
                command+=""
                clear
                printf "$menu_header"
                printf "$backups_off"
                    while true; do
                        read -n 1 -s -r -p "$backup_continue" key
                            if [[ $key == "y" || $key == "Y" ]]; then
                                break
                            else
                                exec "$current_menu"
                            fi
                    done
            else
                exec "$current_menu"
            fi
            break
            ;;
        3)
            command="move report"
            yes_no_prompt="$backup_prompt"
            clear
            command_yes_no
            if [[ "$yes_no" == "yes" ]]; then
                command+=" clean --clean-backup $backup"
                clear
                printf "$menu_header"
                printf "$backups_on"
                    while true; do
                        read -n 1 -s -r -p "$backup_continue" key
                            if [[ $key == "y" || $key == "Y" ]]; then
                                break
                            else
                                exec "$current_menu"
                            fi
                    done
            elif [[ "$yes_no" == "no" ]]; then
                command+=""
                clear
                printf "$menu_header"
                printf "$backups_off"
                    while true; do
                        read -n 1 -s -r -p "$backup_continue" key
                            if [[ $key == "y" || $key == "Y" ]]; then
                                break
                            else
                                exec "$current_menu"
                            fi
                    done
            else
                exec "$current_menu"
            fi
            break
            ;;
        4)
            exec $previous_menu
            ;;
        5)
            exec ./igirst.sh
            ;;
        0)
            printf "$quit"
            sleep 1
            clear && exit
            ;;
        "")
            printf "$empty_choice"
            sleep 1
            ;;
        *)
            printf "$invalid_choice $choice"
            sleep 1
            ;;
        esac
    done
}

command_yes_no() {
while true; do
    clear
    printf "$menu_header"
    printf "$yes_no_prompt $command_yes_no_list"
    read -p "Select an option: " choice

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
            :
            break
            ;;
        4)
            exec ./igirst.sh
            ;;
        0)
            printf "$quit"
            sleep 1
            clear && exit
            ;;
        "")
            printf "$empty_choice"
            sleep 1
            ;;
        *)
            printf "$invalid_choice $choice"
            sleep 1
            ;;
        esac
    done
}

atari_menu() {
while true; do
    clear
    printf "$atari_menu_header"
    printf "$atari_menu_list"
    read -p "Select an option: " choice

    if [ -z "$choice" ]; then
        choice=""
    fi

    case $choice in
        1)
            exec ./scripts/atari/2600.sh
            ;;
        2)
            exec ./scripts/atari/5200.sh
            ;;
        3)
            exec ./scripts/atari/7800.sh
            ;;
        4)
            exec ./scripts/atari/Jaguar.sh
            ;;
        5)
            exec ./scripts/atari/Lynx.sh
            ;;
        6)
            exec ./igirst.sh
            ;;
        0)
            printf "$quit"
            sleep 1
            clear && exit
            ;;
        "")
            printf "$empty_choice"
            sleep 1
            ;;
        *)
            printf "$invalid_choice $choice"
            sleep 1
            ;;
        esac
    done
}

nec_menu() {
while true; do
    clear
    printf "$nec_menu_header"
    printf "$nec_menu_list"
    read -p "Select an option: " choice

    if [ -z "$choice" ]; then
        choice=""
    fi

    case $choice in
        1)
            exec ./scripts/nec/tg16.sh
            ;;
        2)
            exec ./igirst.sh
            ;;
        0)
            printf "$quit"
            sleep 1
            clear && exit
            ;;
        "")
            printf "$empty_choice"
            sleep 1
            ;;
        *)
            printf "$invalid_choice $choice"
            sleep 1
            ;;
        esac
    done
}

nintendo_menu() {
while true; do
    clear
    printf "$nintendo_menu_header"
    printf "$nintendo_menu_list"
    read -p "Select an option: " choice

    if [ -z "$choice" ]; then
        choice=""
    fi

    case $choice in
        1)
            exec ./scripts/nintendo/3ds.sh
            ;;
        2)
            exec ./scripts/nintendo/64.sh
            ;;
        3)
            exec ./scripts/nintendo/ds.sh
            ;;
        4)
            exec ./scripts/nintendo/gb.sh
            ;;
        5)
            exec ./scripts/nintendo/gba.sh
            ;;
        6)
            exec ./scripts/nintendo/gbc.sh
            ;;
        7)
            exec ./scripts/nintendo/nes.sh
            ;;
        8)
            exec ./scripts/nintendo/snes.sh
            ;;
        9)
            exec ./scripts/nintendo/vb.sh
            ;;
        10)
            exec ./igirst.sh
            ;;
        0)
            printf "$quit"
            sleep 1
            clear && exit
            ;;
        "")
            printf "$empty_choice"
            sleep 1
            ;;
        *)
            printf "$invalid_choice $choice"
            sleep 1
            ;;
        esac
    done
}

sega_menu() {
while true; do
    clear
    printf "$sega_menu_header"
    printf "$sega_menu_list"
    read -p "Select an option: " choice

    if [ -z "$choice" ]; then
        choice=""
    fi

    case $choice in
        1)
            exec ./scripts/sega/32x.sh
            ;;
        2)
            exec ./scripts/sega/gg.sh
            ;;
        3)
            exec ./scripts/sega/gen.sh
            ;;
        4)
            exec ./scripts/sega/ms.sh
            ;;
        5)
            exec ./igirst.sh
            ;;
        0)
            printf "$quit"
            sleep 1
            clear && exit
            ;;
        "")
            printf "$empty_choice"
            sleep 1
            ;;
        *)
            printf "$invalid_choice $choice"
            sleep 1
            ;;
        esac
    done
}

snk_menu() {
while true; do
    clear
    printf "$snk_menu_header"
    printf "$snk_menu_list"
    read -p "Select an option: " choice

    if [ -z "$choice" ]; then
        choice=""
    fi

    case $choice in
        1)
            exec ./scripts/snk/ngpc.sh
            ;;
        2)
            exec ./igirst.sh
            ;;
        0)
            printf "$quit"
            sleep 1
            clear && exit
            ;;
        "")
            printf "$empty_choice"
            sleep 1
            ;;
        *)
            printf "$invalid_choice $choice"
            sleep 1
            ;;
        esac
    done
}
