#!/bin/bash

clear

source "./variables/includes/messages.inc"
source "./variables/includes/menus.inc"
source "./variables/nintendo/nes.env"

var="./variables/nintendo/nes.env"
menu_header="$nintendo_nes_menu_header"
current_menu="./scripts/nintendo/nes.sh"
previous_menu="./scripts/nintendo.sh"

    printf "$menu_header"

#Check required variables are set
env_check=$(<./scripts/includes/env_check.inc)
eval "$env_check"

#Load main IGIR command script
source "./scripts/includes/commands.inc"

exec "$0" "$@"
