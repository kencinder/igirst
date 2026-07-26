#!/bin/bash

clear

source "./variables/includes/messages.inc"
source "./variables/includes/menus.inc"
source "./variables/nintendo/gba.env"

var="./variables/nintendo/gba.env"
menu_header="$nintendo_gba_menu_header"
current_menu="./scripts/nintendo/gba.sh"
previous_menu="./scripts/nintendo.sh"

    printf "$menu_header"

#Check required variables are set
env_check=$(<./scripts/includes/env_check.inc)
eval "$env_check"

#Load main IGIR command script
source "./scripts/includes/commands.inc"

exec "$0" "$@"
