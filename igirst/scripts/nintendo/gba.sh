#!/bin/bash

clear

echo "****************************************************"
echo "*                                                  *"
echo "*                IGIR SHELL TOOLS                  *"
echo "*                                                  *"
echo "*           Nintendo - Game Boy Advance            *"
echo "*                                                  *"
echo "****************************************************"
echo

#Load variables
source "./variables/nintendo/gba.env"
previous_menu="./scripts/nintendo.sh"

#Check required variables are set
if [ -z "$dat" ]; then
   echo "DAT variable is empty in /variables/nintendo/gba.env, please set and run IGIR Shell Tools again"
   echo
   read -n 1 -s -r -p "Press any key to continue..."
   clear
   echo "Exiting IGIR Shell Tools..."
   sleep 2
   clear
   exit
fi
if [ -z "$input" ]; then
   echo "INPUT variable is empty in /variables/nintendo/gba.env, please set and run IGIR Shell Tools again"
   echo
   read -n 1 -s -r -p "Press any key to continue..."
   clear
   echo "Exiting IGIR Shell Tools..."
   sleep 2
   clear
   exit
fi
if [ -z "$output" ]; then
   echo "OUPUT variable is empty in /variables/nintendo/gba.env, please set and run IGIR Shell Tools again"
   echo
   read -n 1 -s -r -p "Press any key to continue..."
   clear
   echo "Exiting IGIR Shell Tools..."
   sleep 2
   clear
   exit
fi
if [ -z "$backup" ]; then
   echo "BACKUP variable is empty in /variables/nintendo/gba.env, please set and run IGIR Shell Tools again"
   echo
   read -n 1 -s -r -p "Press any key to continue..."
   clear
   echo "Exiting IGIR Shell Tools..."
   sleep 2
   clear
   exit
fi
if [ -z "$report" ]; then
   echo "REPORT variable is empty in /variables/nintendo/gba.env, please set and run IGIR Shell Tools again"
   echo
   read -n 1 -s -r -p "Press any key to continue..."
   clear
   echo "Exiting IGIR Shell Tools..."
   sleep 2
   clear
   exit
fi

#Load main IGIR command script
source "./scripts/commands.sh"

exec "$0" "$@"