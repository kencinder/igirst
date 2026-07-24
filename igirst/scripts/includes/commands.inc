#!/bin/bash
#This file is for IGIR Commands and must be sourced

source "./variables/includes/files.inc"
source "./variables/includes/messages.inc"
source "./variables/includes/menus.inc"

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
            source "./scripts/includes/command.inc"
            break
            ;;
        2)
            command="copy report"
            source "./scripts/includes/command.inc"
            break
            ;;
        3)
            command="move report"
            source "./scripts/includes/command.inc"
            break
            ;;
        4)
            command="copy clean report --clean-backup"
            source "./scripts/includes/command-backup.inc"
            break
            ;;
        5)
            command="move clean report --clean-backup"
            source "./scripts/includes/command-backup.inc"
            break
            ;;
        6)
            command="copy clean report"
            source "./scripts/includes/command.inc"
            break
            ;;
        7)
            command="move clean report"
            source "./scripts/includes/command.inc"
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
    