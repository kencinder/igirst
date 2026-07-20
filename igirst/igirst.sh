#!/bin/bash

clear

FILE="igir"

if [ -f "$FILE" ]; then
echo "****************************************************"
echo "*                                                  *"
echo "*                IGIR SHELL TOOLS                  *"
echo "*                                                  *"
echo "*                    Main Menu                     *"
echo "*                                                  *"
echo "****************************************************"
echo
else
    echo "***IGIR not found!***"
    echo
    echo "This script MUST be run in the same directory as the IGIR Binary."
    echo
    read -n 1 -s -r -p "Press any key to exit..."
    echo
    exit
fi

# Commands Menu
PS3="Choose a Platform or Manufacturer(1-6): "

# Define the commands
commands=("Atari" "NEC" "Nintendo" "Sega" "SNK" "Quit")

# Run the select loop
COLUMNS=1
select cmd in "${commands[@]}"
do
    case $cmd in
        "Atari")
            ./scripts/atari.sh
            break
            ;;
        "NEC")
            ./scripts/nec.sh
            break
            ;;
        "Nintendo")
            ./scripts/nintendo.sh
            break
            ;;
        "Sega")
            ./scripts/sega.sh
            break
            ;;
        "SNK")
            ./scripts/snk.sh
            break
            ;;
        "Quit")
            clear
            echo "Exiting IGIR Shell Tools..."
            sleep 2
            clear
            exit
            ;;
        *)
            echo "Invalid option $REPLY"
            ;;
    esac
done