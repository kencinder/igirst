#!/bin/bash

source "./variables/messages.env"
source "./variables/menus.env"

# Commands Menu
    printf "$command_menu_list"

while true; do
    read -p "Select an option: " choice

    if [ -z "$choice" ]; then
        choice=""
    fi

    case $choice in
        1)
            command="report"
            source "./scripts/command.sh"
            break
            ;;
        2)
            command="copy report"
            source "./scripts/command.sh"
            break
            ;;
        3)
            command="move report"
            source "./scripts/command.sh"
            break
            ;;
        4)
            command="copy clean report --clean-backup"
            source "./scripts/command-backup.sh"
            break
            ;;
        5)
            command="move clean report --clean-backup"
            source "./scripts/command-backup.sh"
            break
            ;;
        6)
            command="copy clean report"
            source "./scripts/command.sh"
            break
            ;;
        7)
            command="move clean report"
            source "./scripts/command.sh"
            break
            ;;
        8)
            exec $previous_menu
            ;;
        9)
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