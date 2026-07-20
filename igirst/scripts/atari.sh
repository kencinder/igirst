#!/bin/bash

clear

echo "****************************************************"
echo "*                                                  *"
echo "*                IGIR SHELL TOOLS                  *"
echo "*                                                  *"
echo "*                     Atari                        *"
echo "*                                                  *"
echo "****************************************************"
echo

# Commands Menu
PS3="Choose a Platform(1-7): "

# Define the commands
commands=("2600" "5200" "7800" "Jaguar" "Lynx" "Main Menu" "Quit")

# Run the select loop
COLUMNS=1
select cmd in "${commands[@]}"
do
    case $cmd in
        "2600")
            ./scripts/atari/2600.sh
            break
            ;;
        "5200")
            ./scripts/atari/5200.sh
            break
            ;;
        "7800")
            source ./scripts/atari/7800.sh
            break
            ;;
        "Jaguar")
            ./scripts/atari/jaguar.sh
            break
            ;;
        "Lynx")
            ./scripts/atari/lynx.sh
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