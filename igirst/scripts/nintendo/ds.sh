#!/bin/bash

clear

source "./igirst.cfg"
source "./scripts/includes/messages.inc"
source "./scripts/includes/menu_vars.inc"

dat="$ds_dat"
input="$ds_input"
output="$ds_output"
backup="$ds_backup"
report="$ds_report"
regions="$ds_regions"
options="$ds_options"
exclude="$ds_exclude"

current_menu="./scripts/nintendo/ds.sh"
current_menu_header="$nintendo_ds_menu_header"
previous_menu="./scripts/nintendo.sh"

    printf "$current_menu_header"

#Check required variables are set
env_check=$(<./scripts/includes/env_check.inc)
eval "$env_check"

#Load main IGIR command script
source "./scripts/includes/commands.inc"

exec "$0" "$@"
