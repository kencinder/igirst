#!/bin/bash

source "./variables/messages.env"
source "./variables/menus.env"

clear

# Check for IGIR Binary
FILE="igir"

if [ -f "$FILE" ]; then
    printf "$main_menu_header"
else
    printf "$no_igir"
    read -n 1 -s -r -p "Press any key to exit..." && clear
    exit
fi

# Main Menu
    printf "$main_menu_list"

while true; do
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