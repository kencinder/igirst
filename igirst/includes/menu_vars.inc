#!/bin/bash

#			### Common menu variables

_7z_process="
Processing 7z Files...
"

backup_prompt="
 *** WARNING! *** Clean is enabled but backups are not. Are you sure you want to continue?
"

backup_continue="
 Press Y to continue or any other key to return to the previous menu
"

choose="Choose an option:"

command_all_menu_common="R: Generate Report for all Systems\nC: Copy Roms + Generate Report for all Systems\nM: Move Roms + Generate Report for all Systems"

command_menu_list="R: Generate Report\nC: Copy Roms + Generate Report\nM: Move Roms + Generate Report\nB: Previous Menu"

continue=$'\n\nPress any key to continue...'

menu_main_quit="T: Main Menu
Q: Quit"

no_igir="$(printf "%52s" "*** IGIR not found! ***")\n\n *** IGIR required in $PWD or set \"igir_binary\" in igirst.cfg ***"

var_missing="location not set in igirst.cfg"

cmd_vars=(command_add dat input output_copy output_move options exclude report)

platforms=("Atari" "NEC" "Nintendo" "Microsoft" "Sega" "SNK" "Sony")

atari_systems=("2600" "5200" "7800" "Jaguar" "Lynx" "ST")
nec_systems=("Turbografx-16\PC Engine" "TurboGrafx CD\PC Engine CD")
nintendo_systems=("3DS" "64" "DS" "Game Boy" "Game Boy Advance" "Game Boy Color" "Nintendo Entertainment System" "Super Nintendo Entertainment System" "Virtual Boy")
microsoft_systems=("Xbox" "Xbox 360")
sega_systems=("32X" "Dreamcast" "Game Gear" "Genesis\Mega Drive" "Master System" "Saturn" "Sega CD\Mega CD")
snk_systems=("Neo Geo Pocket Color")
sony_systems=("PlayStation" "PlayStation 2" "PlayStation 3" "PlayStation Portable")

atari_system_vars=("atari_2600" "atari_5200" "atari_7800" "atari_jaguar" "atari_lynx" "atari_st")
nec_system_vars=("nec_tg16" "nec_tg16cd")
nintendo_system_vars=("nintendo_3ds" "nintendo_64" "nintendo_ds" "nintendo_gb" "nintendo_gba" "nintendo_gbc" "nintendo_nes" "nintendo_snes" "nintendo_vb")
microsoft_system_vars=("microsoft_xbox" "microsoft_360")
sega_system_vars=("sega_32x" "sega_dc" "sega_gg" "sega_gen" "sega_ms" "sega_sat" "sega_scd")
snk_system_vars=("snk_ngpc")
sony_system_vars=("sony_ps1" "sony_ps2" "sony_ps3" "sony_psp")
