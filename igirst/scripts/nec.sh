#!/bin/bash

clear

echo "****************************************************"
echo "*                                                  *"
echo "*                IGIR SHELL TOOLS                  *"
echo "*                                                  *"
echo "*                      NEC                         *"
echo "*                                                  *"
echo "****************************************************"
echo

# Commands Menu
PS3="Choose a Platform(1-3): "

# Define the commands
commands=("TurboGrafx 16\PC Engine" "Main Menu" "Quit")

# Run the select loop
COLUMNS=1
select cmd in "${commands[@]}"
do
    case $cmd in
        "TurboGrafx 16\PC Engine")
            ./scripts/nec/tg16.sh
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
