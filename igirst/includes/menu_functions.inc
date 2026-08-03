#!/bin/bash

# Common menu functions

create_dat_filename() {
#Create DAT filename Variable
	dat_path_strip="${dat##*/}"
	dat_filename="${dat_path_strip%.*}"
	dat_filename_nop="${dat_filename//\(*\)}"
	dat_filename_no_parentheses="${dat_filename_nop% }"
	source "igirst.cfg"
	system_vars
}

backup_check() {
	clear
    printf '%s' "$current_menu_header $backup_prompt"
	if [[ "$command_add" == *"clean"* ]]; then
    	if [[ "$command_add" != *"--clean-backup"* ]]; then
			clear
    		printf '%s' "$current_menu_header $backup_prompt"
				while true; do
					read -rsn 1 -p "$backup_continue" key
				if [[ $key == "y" || $key == "Y" ]]; then
					break
				else
					"$current_menu"
				fi
		done
		fi
	fi
}

command_add_check() {
	if [[ -n "$command_add" ]]; then
    	command+="$command_add "
	else
		:
	fi
}

command_igir() {
	./"$igir_binary" $command --dat "${dat}" --input "$input" --output "$output" $options -X "$exclude" --report-output "$report"
	printf "\n"
	read -rsn 1 -p "$continue"
}

command_set() {
	system_vars
	printf '%s' "$current_menu_header"
#Check required variables are set
	var_check
	create_dat_filename
#Load command menu and IGIR command script
	command_menu
	clear
	command_igir
#Return to previous menu
	"$current_menu"
}

cmd_vars=(command_add dat input output_copy output_move options exclude report)
system_vars() {
	for ((i=0; i<${#cmd_vars[@]}; i++)); do
    	eval "${cmd_vars[i]}=${system[i]}"
	done
}

var_check() {
if [ -z "$dat" ]; then
    printf '%s\n\n' "DAT $var_missing"
fi

if [ -z "$input" ]; then
    printf '%s\n\n' "INPUT $var_missing"
fi

if [ -z "$output_copy" ]; then
    printf '%s\n\n' "OUTPUT COPY $var_missing"
fi

if [ -z "$output_move" ]; then
    printf '%s\n\n' "OUTPUT MOVE $var_missing"
fi

if [ -z "$report" ]; then
    printf '%s\n\n' "REPORT $var_missing"
fi

if [[ -z "$dat" || -z "$input" || -z "$output_copy" || -z "$output_move" || -z "$report" ]]; then
    read -rsn 1 -p "$continue"
    $previous_menu
fi
}

# Atari #

atari_2600_menu() {
	clear
		current_menu="atari_2600_menu"
		current_menu_header="$atari_2600_menu_header"
		system=("${cmd_vars[@]/#/\$_2600_}")
	command_set
}
atari_5200_menu() {
	clear
		current_menu="atari_5200_menu"
		current_menu_header="$atari_5200_menu_header"
	eval "$var"
		system=("${cmd_vars[@]/#/\$_5200_}")
	command_set
}
atari_7800_menu() {
	clear
		current_menu="atari_7800_menu"
		current_menu_header="$atari_7800_menu_header"
	eval "$var"
		system=("${cmd_vars[@]/#/\$_7800_}")
	command_set
}
atari_jaguar_menu() {
	clear
		current_menu="atari_jaguar_menu"
		current_menu_header="$atari_jaguar_menu_header"
	eval "$var"
		system=("${cmd_vars[@]/#/\$jaguar_}")
	command_set
}
atari_lynx_menu() {
	clear
		current_menu="atari_lynx_menu"
		current_menu_header="$atari_lynx_menu_header"
	eval "$var"
		system=("${cmd_vars[@]/#/\$lynx_}")
	command_set
}

# NEC #

nec_tg16_menu() {
	clear
		current_menu="nec_tg16_menu"
		current_menu_header="$nec_tg16_menu_header"
	eval "$var"
		system=("${cmd_vars[@]/#/\$tg16_}")
	command_set
}

# Nintendo #

nintendo_3ds_menu() {
	clear
		current_menu="nintendo_3ds_menu"
		current_menu_header="$nintendo_3ds_menu_header"
	eval "$var"
		system=("${cmd_vars[@]/#/\$_3ds_}")
	command_set
}

nintendo_64_menu() {
	clear
		current_menu="nintendo_64_menu"
		current_menu_header="$nintendo_64_menu_header"
	eval "$var"
		system=("${cmd_vars[@]/#/\$_64_}")
	command_set
}

nintendo_ds_menu() {
	clear
		current_menu="nintendo_ds_menu"
		current_menu_header="$nintendo_ds_menu_header"
	eval "$var"
		system=("${cmd_vars[@]/#/\$ds_}")
	command_set
}

nintendo_gb_menu() {
	clear
		current_menu="nintendo_gb_menu"
		current_menu_header="$nintendo_gb_menu_header"
	eval "$var"
		system=("${cmd_vars[@]/#/\$gb_}")
	command_set
}

nintendo_gba_menu() {
	clear
		current_menu="nintendo_gba_menu"
		current_menu_header="$nintendo_gba_menu_header"
	eval "$var"
		system=("${cmd_vars[@]/#/\$gba_}")
	command_set
}

nintendo_gbc_menu() {
	clear
		current_menu="nintendo_gbc_menu"
		current_menu_header="$nintendo_gbc_menu_header"
	eval "$var"
		system=("${cmd_vars[@]/#/\$gbc_}")
	command_set
}

nintendo_nes_menu() {
	clear
		current_menu="nintendo_nes_menu"
		current_menu_header="$nintendo_nes_menu_header"
	eval "$var"
		system=("${cmd_vars[@]/#/\$nes_}")
	command_set
}

nintendo_snes_menu() {
	clear
		current_menu="nintendo_snes_menu"
		current_menu_header="$nintendo_snes_menu_header"
	eval "$var"
		system=("${cmd_vars[@]/#/\$snes_}")
	command_set
}

nintendo_vb_menu() {
	clear
		current_menu="nintendo_vb_menu"
		current_menu_header="$nintendo_vb_menu_header"
	eval "$var"
		system=("${cmd_vars[@]/#/\$vb_}")
	command_set
}
			
# SEGA #

sega_32x_menu() {
	clear
		current_menu="sega_32x_menu"
		current_menu_header="$sega_32x_menu_header"
	eval "$var"
		system=("${cmd_vars[@]/#/\$_32x_}")
	command_set
}
sega_gg_menu() {
	clear
		current_menu="sega_gg_menu"
		current_menu_header="$sega_gg_menu_header"
	eval "$var"
		system=("${cmd_vars[@]/#/\$gg_}")
	command_set
}
sega_gen_menu() {
	clear
		current_menu="sega_gen_menu"
		current_menu_header="$sega_gen_menu_header"
	eval "$var"
		system=("${cmd_vars[@]/#/\$gen_}")
	command_set
}
sega_ms_menu() {
	clear
		current_menu="sega_ms_menu"
		current_menu_header="$sega_ms_menu_header"
	eval "$var"
		system=("${cmd_vars[@]/#/\$ms_}")
	command_set
}

# SNK #

snk_ngpc_menu() {
	clear
		current_menu="snk_ngpc_menu"
		current_menu_header="$snk_ngpc_menu_header"
	eval "$var"
		system=("${cmd_vars[@]/#/\$ngpc_}")
	command_set
}
