#!/bin/bash

clear

source "./igirst.cfg"
source "./scripts/includes/messages.inc"
source "./scripts/includes/menu_vars.inc"

dat="$snes_dat"
input="$snes_input"
output="$snes_output"
backup="$snes_backup"
report="$snes_report"
regions="$snes_regions"
options="$snes_options"
exclude="$snes_exclude"

current_menu="./scripts/nintendo/snes.sh"
current_menu_header="$nintendo_snes_menu_header"
previous_menu="./scripts/nintendo.sh"

    printf "$current_menu_header"

#Check required variables are set
env_check=$(<./scripts/includes/env_check.inc)
eval "$env_check"

#Load main IGIR command script
source "./scripts/includes/commands.inc"

exec "$0" "$@"
