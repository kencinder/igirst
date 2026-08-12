#!/bin/bash

igirst_dir="$PWD"
set -a
source "igirst.cfg"
source "includes/7z_functions.inc"
source "includes/menus.inc"
source "includes/menu_functions.inc"
source "includes/menu_vars.inc"
set +a

# Check for IGIR Binary
FILE="$igir_binary"

if [ -f "$FILE" ]; then
	main_menu
else
    clear && printf '\n%b\n\n' "$no_igir"
    read -rsn 1 -p "Press any key to exit..." && clear
    exit
fi
