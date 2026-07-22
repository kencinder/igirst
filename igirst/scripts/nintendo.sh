#!/bin/bash

clear

source "./variables/messages.env"
source "./variables/menus.env"

    printf "$nintendo_menu_header"

# Commands Menu
    printf "$nintendo_menu_list"

while true; do
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
            clear
            printf "$quit"
            sleep 1
            clear && exit
            ;;
        "")
            printf "$empty_choice"
            sleep 1 && exec "$0" "$@"
            ;;
        *)
            printf "$invalid_choice $choice"
            sleep 1 && exec "$0" "$@"
            ;;
        esac
    done