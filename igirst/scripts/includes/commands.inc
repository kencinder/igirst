#!/bin/bash
#This file is for IGIR Commands and must be sourced

source "./scripts/includes/messages.inc"
source "./scripts/includes/menu_vars.inc"
source "./scripts/includes/menus.inc"

command_menu

clear

"$igir_binary" $command"$backup" --dat "$dat" --input "$input" --output "$output" $options -R $regions -r $regions -X "$exclude" --report-output "$report"

printf "\n"
read -n 1 -s -r -p "$continue"
