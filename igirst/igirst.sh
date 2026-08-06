#!/bin/bash

set -a
source "igirst.cfg"
source "includes/7z_functions.inc"
source "includes/menus.inc"
source "includes/messages.inc"
source "includes/menu_functions.inc"
source "includes/menu_vars.inc"
set +a

# Check for IGIR Binary
FILE="$igir_binary"

if [ -f "$FILE" ]; then
	main_menu
else
    printf '%s' "$no_igir"
    read -n 1 -s -r -p "Press any key to exit..." && clear
    exit
fi
