#!/bin/bash

clear

echo "****************************************************"
echo "*                                                  *"
echo "*                IGIR SHELL TOOLS                  *"
echo "*                                                  *"
echo "*                      SNK                         *"
echo "*                                                  *"
echo "****************************************************"
echo

# Commands Menu
PS3="Choose a Platform(1-3): "

# Define the commands
commands=("Neo Geo Pocket Color" "Main Menu" "Quit")

# Run the select loop
COLUMNS=1
select cmd in "${commands[@]}"
do
    case $cmd in
        "Neo Geo Pocket Color")
            ./scripts/snk/ngpc.sh
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
