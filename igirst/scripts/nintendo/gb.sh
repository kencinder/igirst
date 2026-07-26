#!/bin/bash

clear

source "./igirst.cfg"
source "./scripts/includes/messages.inc"
source "./scripts/includes/menu_vars.inc"

dat="$gb_dat"
input="$gb_input"
output="$gb_output"
backup="$gb_backup"
report="$gb_report"
regions="$gb_regions"
options="$gb_options"
exclude="$gb_exclude"

current_menu="./scripts/nintendo/gb.sh"
current_menu_header="$nintendo_gb_menu_header"
previous_menu="./scripts/nintendo.sh"

    printf "$current_menu_header"

#Check required variables are set
env_check=$(<./scripts/includes/env_check.inc)
eval "$env_check"

#Load main IGIR command script
source "./scripts/includes/commands.inc"

exec "$0" "$@"
