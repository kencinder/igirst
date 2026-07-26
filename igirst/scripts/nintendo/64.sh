#!/bin/bash

clear

source "./variables/includes/messages.inc"
source "./variables/includes/menus.inc"
source "./variables/nintendo/64.env"

var="./variables/nintendo/64.env"
menu_header="$nintendo_64_menu_header"
current_menu="./scripts/nintendo/64.sh"
previous_menu="./scripts/nintendo.sh"

    printf "$menu_header"

#Check required variables are set
env_check=$(<./scripts/includes/env_check.inc)
eval "$env_check"

#Load main IGIR command script
source "./scripts/includes/commands.inc"

exec "$0" "$@"
