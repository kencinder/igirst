#!/bin/bash
#This file is for IGIR Commands and must be sourced

clear

./igir $command "$backup" --dat "$dat" --input "$input" --output "$output" -R $regions -X "$exclude" $options --report-output "$report"

printf "\n"
read -n 1 -s -r -p "Press any key to continue..."