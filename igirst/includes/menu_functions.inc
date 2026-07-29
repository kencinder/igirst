#!/bin/bash

# Common menu functions

backup_choice() {
clear
command_yes_no
if [[ "$yes_no" == "yes" ]]; then
	command+=" clean --clean-backup "
	clear
	printf '%s' "$current_menu_header"
	printf '%s' "$backups_on"
		while true; do
			read -n 1 -s -r -p "$backup_continue" key
				if [[ $key == "y" || $key == "Y" ]]; then
					break
				else
					eval "$current_menu"
				fi
		done
elif [[ "$yes_no" == "no" ]]; then
	backup=""
	clear
	printf '%s' "$current_menu_header"
	printf '%s' "$backups_off"
		while true; do
			read -n 1 -s -r -p "$backup_continue" key
				if [[ $key == "y" || $key == "Y" ]]; then
					break
				else
					eval "$current_menu"
				fi
		done
else
	eval "$current_menu"
fi
}

command_igir() {
./"$igir_binary" $command"$backup" --dat "$dat" --input "$input" --output "$output" $options -R $regions -r $regions -X "$exclude" --report-output "$report"

printf "\n"
read -n 1 -s -r -p "$continue"
}

command_set() {
system_vars
	printf '%s' "$current_menu_header"
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
    printf '%s\n\n' "DAT $var_missing igirst.cfg"
fi

if [ -z "$input" ]; then
    printf '%s\n\n' "INPUT $var_missing igirst.cfg"
fi

if [ -z "$output" ]; then
    printf '%s\n\n' "OUPUT $var_missing igirst.cfg"
fi

if [ -z "$backup" ]; then
    printf '%s\n\n' "BACKUP $var_missing igirst.cfg"
fi

if [ -z "$report" ]; then
    printf '%s\n\n' "REPORT $var_missing igirst.cfg"
fi

if [[ -z "$dat" || -z "$input" || -z "$output" || -z "$backup" || -z "$report" ]]; then
    read -n 1 -s -r -p "$continue"
    eval $previous_menu
fi
}

# Atari #

atari_2600_menu() {
	clear
		current_menu="atari_2600_menu"
		current_menu_header="$atari_2600_menu_header"
	eval "$var"
		system=("${vars[@]/#/\$_2600_}")
	eval "command_set"
		atari_2600_menu
}
atari_5200_menu() {
	clear
		current_menu="atari_5200_menu"
		current_menu_header="$atari_5200_menu_header"
	eval "$var"
		system=("${vars[@]/#/\$_5200_}")
	eval "command_set"
		atari_5200_menu
}
atari_7800_menu() {
	clear
		current_menu="atari_7800_menu"
		current_menu_header="$atari_7800_menu_header"
	eval "$var"
		system=("${vars[@]/#/\$_7800_}")
	eval "command_set"
		atari_7800_menu
}
atari_jaguar_menu() {
	clear
		current_menu="atari_jaguar_menu"
		current_menu_header="$atari_jaguar_menu_header"
	eval "$var"
		system=("${vars[@]/#/\$jaguar_}")
	eval "command_set"
		atari_jaguar_menu
}
atari_lynx_menu() {
	clear
		current_menu="atari_lynx_menu"
		current_menu_header="$atari_lynx_menu_header"
	eval "$var"
		system=("${vars[@]/#/\$lynx_}")
	eval "command_set"
		atari_lynx_menu
}

# NEC #

nec_tg16_menu() {
	clear
		current_menu="nec_tg16_menu"
		current_menu_header="$nec_tg16_menu_header"
	eval "$var"
		system=("${vars[@]/#/\$tg16_}")
	eval "command_set"
		nec_tg16_menu
}

# Nintendo #

nintendo_3ds_menu() {
	clear
		current_menu="nintendo_3ds_menu"
		current_menu_header="$nintendo_3ds_menu_header"
	eval "$var"
		system=("${vars[@]/#/\$_3ds_}")
	eval "command_set"
		nintendo_3ds_menu
}

nintendo_64_menu() {
	clear
		current_menu="nintendo_64_menu"
		current_menu_header="$nintendo_64_menu_header"
	eval "$var"
		system=("${vars[@]/#/\$_64_}")
	eval "command_set"
		nintendo_64_menu
}

nintendo_ds_menu() {
	clear
		current_menu="nintendo_ds_menu"
		current_menu_header="$nintendo_ds_menu_header"
	eval "$var"
		system=("${vars[@]/#/\$ds_}")
	eval "command_set"
		nintendo_ds_menu
}

nintendo_gb_menu() {
	clear
		current_menu="nintendo_gb_menu"
		current_menu_header="$nintendo_gb_menu_header"
	eval "$var"
		system=("${vars[@]/#/\$gb_}")
	eval "command_set"
		nintendo_gb_menu
}

nintendo_gba_menu() {
	clear
		current_menu="nintendo_gba_menu"
		current_menu_header="$nintendo_gba_menu_header"
	eval "$var"
		system=("${vars[@]/#/\$gba_}")
	eval "command_set"
		nintendo_gba_menu
}

nintendo_gbc_menu() {
	clear
		current_menu="nintendo_gbc_menu"
		current_menu_header="$nintendo_gbc_menu_header"
	eval "$var"
		system=("${vars[@]/#/\$gbc_}")
	eval "command_set"
		nintendo_gbc_menu
}

nintendo_nes_menu() {
	clear
		current_menu="nintendo_nes_menu"
		current_menu_header="$nintendo_nes_menu_header"
	eval "$var"
		system=("${vars[@]/#/\$nes_}")
	eval "command_set"
		nintendo_nes_menu
}

nintendo_snes_menu() {
	clear
		current_menu="nintendo_snes_menu"
		current_menu_header="$nintendo_snes_menu_header"
	eval "$var"
		system=("${vars[@]/#/\$snes_}")
	eval "command_set"
		nintendo_snes_menu
}

nintendo_vb_menu() {
	clear
		current_menu="nintendo_vb_menu"
		current_menu_header="$nintendo_vb_menu_header"
	eval "$var"
		system=("${vars[@]/#/\$vb_}")
	eval "command_set"
		nintendo_vb_menu
}
			
# SEGA #

sega_32x_menu() {
	clear
		current_menu="sega_32x_menu"
		current_menu_header="$sega_32x_menu_header"
	eval "$var"
		system=("${vars[@]/#/\$_32x_}")
	eval "command_set"
		sega_32x_menu
}
sega_gg_menu() {
	clear
		current_menu="sega_gg_menu"
		current_menu_header="$sega_gg_menu_header"
	eval "$var"
		system=("${vars[@]/#/\$gg_}")
	eval "command_set"
		sega_gg_menu
}
sega_gen_menu() {
	clear
		current_menu="sega_gen_menu"
		current_menu_header="$sega_gen_menu_header"
	eval "$var"
		system=("${vars[@]/#/\$gen_}")
	eval "command_set"
		sega_gen_menu
}
sega_ms_menu() {
	clear
		current_menu="sega_ms_menu"
		current_menu_header="$sega_ms_menu_header"
	eval "$var"
		system=("${vars[@]/#/\$ms_}")
	eval "command_set"
		sega_ms_menu
}

# SNK #

snk_ngpc_menu() {
	clear
		current_menu="snk_ngpc_menu"
		current_menu_header="$snk_ngpc_menu_header"
	eval "$var"
		system=("${vars[@]/#/\$ngpc_}")
	eval "command_set"
		snk_ngpc_menu
}
