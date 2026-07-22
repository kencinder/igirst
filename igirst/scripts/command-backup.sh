#!/bin/bash

clear

./igir $command "$backup" --dat "$dat" --input "$input" --output "$output" -R $regions -L $lang -X "$exclude" $options --report-output "$report"

printf "\n"
read -n 1 -s -r -p "Press any key to continue..."