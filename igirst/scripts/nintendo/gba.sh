#!/bin/bash

clear

source "./igirst.cfg"
source "./scripts/includes/messages.inc"
source "./scripts/includes/menu_vars.inc"

dat="$gba_dat"
input="$gba_input"
output="$gba_output"
backup="$gba_backup"
report="$gba_report"
regions="$gba_regions"
options="$gba_options"
exclude="$gba_exclude"

current_menu="./scripts/nintendo/gba.sh"
current_menu_header="$nintendo_gba_menu_header"
previous_menu="./scripts/nintendo.sh"

    printf "$current_menu_header"

#Check required variables are set
env_check=$(<./scripts/includes/env_check.inc)
eval "$env_check"

#Load main IGIR command script
source "./scripts/includes/commands.inc"

exec "$0" "$@"
