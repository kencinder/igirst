#!/bin/bash

# Common menu functions

command_igir() {
./"$igir_binary" $command"$backup" --dat "$dat" --input "$input" --output "$output" $options -R $regions -r $regions -X "$exclude" --report-output "$report"

printf "\n"
read -n 1 -s -r -p "$continue"
}

command_set() {
system_vars
	printf "$current_menu_header"
#Check required variables are set
	var_check
#Load command menu and IGIR command script
	command_menu
	clear
	command_igir
#Return to previous menu
}

system_vars() {
for ((i=0; i<${#vars[@]}; i++)); do
    eval "${vars[i]}=\"${system[i]}\""
done
}

var_check() {
if [ -z "$dat" ]; then
    printf "DAT $var_missing igirst.cfg\n\n"
fi

if [ -z "$input" ]; then
    printf "INPUT $var_missing igirst.cfg\n\n"
fi

if [ -z "$output" ]; then
    printf "OUPUT $var_missing igirst.cfg\n\n"
fi

if [ -z "$backup" ]; then
    printf "BACKUP $var_missing igirst.cfg\n\n"
fi

if [ -z "$report" ]; then
    printf "REPORT $var_missing igirst.cfg\n\n"
fi

if [[ -z "$dat" || -z "$input" || -z "$output" || -z "$backup" || -z "$report" ]]; then
    read -n 1 -s -r -p "$continue"
    exec $previous_menu
fi
}

# Atari #



# NEC #
    
    

# Nintendo #

nintendo_3ds_menu() {
	clear
		current_menu="nintendo_3ds_menu"
		current_menu_header="$nintendo_3ds_menu_header"
		previous_menu="nintendo_menu"
	eval "$var"
		system=("${vars[@]/#/\$_3ds_}")
	eval "command_set"
		nintendo_3ds_menu
}

nintendo_64_menu() {
	clear
		current_menu="nintendo_64_menu"
		current_menu_header="$nintendo_64_menu_header"
		previous_menu="nintendo_menu"
	eval "$var"
		system=("${vars[@]/#/\$_64_}")
	eval "command_set"
		nintendo_64_menu
}

nintendo_ds_menu() {
	clear
		current_menu="nintendo_ds_menu"
		current_menu_header="$nintendo_ds_menu_header"
		previous_menu="nintendo_menu"
	eval "$var"
		system=("${vars[@]/#/\$ds_}")
	eval "command_set"
		nintendo_ds_menu
}

nintendo_gb_menu() {
	clear
		current_menu="nintendo_gb_menu"
		current_menu_header="$nintendo_gb_menu_header"
		previous_menu="nintendo_menu"
	eval "$var"
		system=("${vars[@]/#/\$gb_}")
	eval "command_set"
		nintendo_gb_menu
}

nintendo_gba_menu() {
	clear
		current_menu="nintendo_gba_menu"
		current_menu_header="$nintendo_gba_menu_header"
		previous_menu="nintendo_menu"
	eval "$var"
		system=("${vars[@]/#/\$gba_}")
	eval "command_set"
		nintendo_gba_menu
}

nintendo_gbc_menu() {
	clear
		current_menu="nintendo_gbc_menu"
		current_menu_header="$nintendo_gbc_menu_header"
		previous_menu="nintendo_menu"
	eval "$var"
		system=("${vars[@]/#/\$gbc_}")
	eval "command_set"
		nintendo_gbc_menu
}

nintendo_nes_menu() {
	clear
		current_menu="nintendo_nes_menu"
		current_menu_header="$nintendo_nes_menu_header"
		previous_menu="nintendo_menu"
	eval "$var"
		system=("${vars[@]/#/\$nes_}")
	eval "command_set"
		nintendo_nes_menu
}

nintendo_snes_menu() {
	clear
		current_menu="nintendo_snes_menu"
		current_menu_header="$nintendo_snes_menu_header"
		previous_menu="nintendo_menu"
	eval "$var"
		system=("${vars[@]/#/\$snes_}")
	eval "command_set"
		nintendo_snes_menu
}

nintendo_vb_menu() {
	clear
		current_menu="nintendo_vb_menu"
		current_menu_header="$nintendo_vb_menu_header"
		previous_menu="nintendo_menu"
	eval "$var"
		system=("${vars[@]/#/\$vb_}")
	eval "command_set"
		nintendo_vb_menu
}
			
# SEGA #
    
    

# SNK #
    


