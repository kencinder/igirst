#!/bin/bash

clear

source "./igirst.cfg"
source "./scripts/includes/messages.inc"
source "./scripts/includes/menu_vars.inc"

dat="$gbc_dat"
input="$gbc_input"
output="$gbc_output"
backup="$gbc_backup"
report="$gbc_report"
regions="$gbc_regions"
options="$gbc_options"
exclude="$gbc_exclude"

current_menu="./scripts/nintendo/gbc.sh"
current_menu_header="$nintendo_gbc_menu_header"
previous_menu="./scripts/nintendo.sh"

    printf "$current_menu_header"

#Check required variables are set
env_check=$(<./scripts/includes/env_check.inc)
eval "$env_check"

#Load main IGIR command script
source "./scripts/includes/commands.inc"

exec "$0" "$@"
