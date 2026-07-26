#!/bin/bash

clear

source "./variables/includes/messages.inc"
source "./variables/includes/menus.inc"
source "./variables/nintendo/snes.env"

var="./variables/nintendo/snes.env"
menu_header="$nintendo_snes_menu_header"
current_menu="./scripts/nintendo/snes.sh"
previous_menu="./scripts/nintendo.sh"

    printf "$menu_header"

#Check required variables are set
env_check=$(<./scripts/includes/env_check.inc)
eval "$env_check"

#Load main IGIR command script
source "./scripts/includes/commands.inc"

exec "$0" "$@"
