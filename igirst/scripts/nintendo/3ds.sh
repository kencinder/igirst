#!/bin/bash

clear

source "./igirst.cfg"
source "./scripts/includes/messages.inc"
source "./scripts/includes/menu_vars.inc"

dat="$_3ds_dat"
input="$_3ds_input"
output="$_3ds_output"
backup="$_3ds_backup"
report="$_3ds_report"
regions="$_3ds_regions"
options="$_3ds_options"
exclude="$_3ds_exclude"

current_menu="./scripts/nintendo/3ds.sh"
current_menu_header="$nintendo_3ds_menu_header"
previous_menu="./scripts/nintendo.sh"

    printf "$current_menu_header"

#Check required variables are set
env_check=$(<./scripts/includes/env_check.inc)
eval "$env_check"

#Load main IGIR command script
source "./scripts/includes/commands.inc"

exec "$0" "$@"
