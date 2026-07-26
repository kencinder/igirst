#!/bin/bash
#This file is for IGIR Commands and must be sourced

source "./variables/includes/files.inc"
source "./variables/includes/messages.inc"
source "./variables/includes/menus.inc"
source "./scripts/includes/menus.inc"

command_menu

clear

"$igir_binary" $command --dat "$dat" --input "$input" --output "$output" $regions -X "$exclude" $options --report-output "$report"

printf "\n"
read -n 1 -s -r -p "$continue"
