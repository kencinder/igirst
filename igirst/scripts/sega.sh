#!/bin/bash

clear

FILE="igir"

if [ -f "$FILE" ]; then
echo "****************************************************"
echo "*                                                  *"
echo "*                IGIR SHELL TOOLS                  *"
echo "*                                                  *"
echo "*                      SEGA                        *"
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
PS3="Choose a Platform(1-6): "

# Define the commands
commands=("32X" "Game Gear" "Genesis\Mega Drive" "Master System" "Main Menu" "Quit")

# Run the select loop
COLUMNS=1
select cmd in "${commands[@]}"
do
    case $cmd in
        "32X")
            ./scripts/sega/32x.sh
            break
            ;;
        "NEC")
            ./scripts/sega/gg.sh
            break
            ;;
        "Nintendo")
            ./scripts/sega/gen.sh
            break
            ;;
        "Sega")
            ./scripts/sega/ms.sh
            break
            ;;
        "Main Menu")
            ./igirst.sh
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