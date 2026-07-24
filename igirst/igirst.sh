#!/bin/bash

source "./scripts/includes/menus.inc"
source "./variables/includes/files.inc"
source "./variables/includes/messages.inc"
source "./variables/includes/menus.inc"

clear

# Check for IGIR Binary
FILE="$igir_binary"

if [ -f "$FILE" ]; then
    printf "$main_menu_header"
else
    printf "$no_igir"
    read -n 1 -s -r -p "Press any key to exit..." && clear
    exit
fi

# Main Menu
    printf "$main_menu_list"
    
main_menu
