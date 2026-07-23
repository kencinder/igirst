#!/bin/bash

clear

source "./variables/includes/messages.inc"
source "./variables/includes/menus.inc"
source "./variables/nintendo/3ds.env"

var="./variables/nintendo/3ds.env"
previous_menu="./scripts/nintendo.sh"

    printf "$nintendo_3ds_menu_header"

#Check required variables are set
env_check=$(<./scripts/includes/env_check.inc)
eval "$env_check"

#Load main IGIR command script
source "./scripts/includes/commands.inc"

exec "$0" "$@"
