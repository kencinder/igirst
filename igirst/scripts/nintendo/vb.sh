#!/bin/bash

clear

source "./igirst.cfg"
source "./scripts/includes/messages.inc"
source "./scripts/includes/menu_vars.inc"

dat="$vb_dat"
input="$vb_input"
output="$vb_output"
backup="$vb_backup"
report="$vb_report"
regions="$vb_regions"
options="$vb_options"
exclude="$vb_exclude"

current_menu="./scripts/nintendo/vb.sh"
current_menu_header="$nintendo_vb_menu_header"
previous_menu="./scripts/nintendo.sh"

    printf "$current_menu_header"

#Check required variables are set
env_check=$(<./scripts/includes/env_check.inc)
eval "$env_check"

#Load main IGIR command script
source "./scripts/includes/commands.inc"

exec "$0" "$@"
