#!/bin/bash

clear

source "./igirst.cfg"
source "./scripts/includes/messages.inc"
source "./scripts/includes/menu_vars.inc"

dat="$_64_dat"
input="$_64_input"
output="$_64_output"
backup="$_64_backup"
report="$_64_report"
regions="$_64_regions"
options="$_64_options"
exclude="$_64_exclude"

current_menu="./scripts/nintendo/64.sh"
current_menu_header="$nintendo_64_menu_header"
previous_menu="./scripts/nintendo.sh"

    printf "$current_menu_header"

#Check required variables are set
env_check=$(<./scripts/includes/env_check.inc)
eval "$env_check"

#Load main IGIR command script
source "./scripts/includes/commands.inc"

exec "$0" "$@"
