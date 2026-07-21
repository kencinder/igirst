#!/bin/bash

clear

./igir $command "$backup" --dat "$dat" --input "$input" --output "$output" -R $regions -L $lang -X "$exclude" $options --report-output "$report"

echo
read -n 1 -s -r -p "Press any key to continue..."
echo