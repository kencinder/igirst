#!/bin/bash

clear

source "./igirst.cfg"
source "./scripts/includes/messages.inc"
source "./scripts/includes/menu_vars.inc"

dat="$nes_dat"
input="$nes_input"
output="$nes_output"
backup="$nes_backup"
report="$nes_report"
regions="$nes_regions"
options="$nes_options"
exclude="$nes_exclude"

current_menu="./scripts/nintendo/nes.sh"
current_menu_header="$nintendo_nes_menu_header"
previous_menu="./scripts/nintendo.sh"

    printf "$current_menu_header"

#Check required variables are set
env_check=$(<./scripts/includes/env_check.inc)
eval "$env_check"

#Load main IGIR command script
source "./scripts/includes/commands.inc"

exec "$0" "$@"
