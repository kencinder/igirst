#!/bin/bash

clear

source "./variables/messages.env"
source "./variables/menus.env"
source "./variables/nintendo/ds.env"

var="./variables/nintendo/ds.env"
previous_menu="./scripts/nintendo.sh"

    printf "$nintendo_ds_menu_header"

#Check required variables are set
env_check=$(<./scripts/includes/env_check.inc)
eval "$env_check"

#Load main IGIR command script
source "./scripts/includes/commands.inc"

exec "$0" "$@"