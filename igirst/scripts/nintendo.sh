#!/bin/bash

clear

echo "****************************************************"
echo "*                                                  *"
echo "*                IGIR SHELL TOOLS                  *"
echo "*                                                  *"
echo "*                    Nintendo                      *"
echo "*                                                  *"
echo "****************************************************"
echo

# Commands Menu
PS3="Choose a Platform(1-12): "

# Define the commands
commands=("3DS" "DS" "Game Boy" "Game Boy Advance" "Game Boy Color" "GameCube" "64" "Nintendo Entertainment System" "Super Nintendo Entertainment System" "Virtual Boy" "Main Menu" "Quit")

# Run the select loop
COLUMNS=1
select cmd in "${commands[@]}"
do
    case $cmd in
        "3DS")
            ./scripts/nintendo/3ds.sh
            break
            ;;
        "DS")
            ./scripts/nintendo/ds.sh
            break
            ;;
        "Game Boy")
            source ./scripts/nintendo/gb.sh
            break
            ;;
        "Game Boy Advance")
            ./scripts/nintendo/gba.sh
            break
            ;;
        "Game Boy Color")
            ./scripts/nintendo/gbc.sh
            break
            ;;
        "GameCube")
            ./scripts/nintendo/gc.sh
            break
            ;;
        "64")
            ./scripts/nintendo/64.sh
            break
            ;;
        "Nintendo Entertainment System")
            clear
            source ./scripts/nintendo/nes.sh
            break
            ;;
        "Super Nintendo Entertainment System")
            ./scripts/nintendo/snes.sh
            break
            ;;
        "Virtual Boy")
            ./scripts/nintendo/vb.sh
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