#!/bin/bash

#			### Common menu variables

choose="Choose an option:"

command_all_menu_common="R: Generate Report for all Systems
C: Copy Roms + Generate Report for all Systems
M: Move Roms + Generate Report for all Systems"

menu_main_quit="T: Main Menu
Q: Quit"

platforms=("Atari" "NEC" "Nintendo" "Sega" "SNK" "Sony")

atari_systems=("2600" "5200" "7800" "Jaguar" "Lynx")
nec_systems=("Turbografx-16")
nintendo_systems=("3DS" "64" "DS" "Game Boy" "Game Boy Advance" "Game Boy Color" "Nintendo Entertainment System" "Super Nintendo Entertainment System" "Virtual Boy")
sega_systems=("32X" "Game Gear" "Genesis\Mega Drive" "Master System")
snk_systems=("Neo Geo Pocket Color")
sony_systems=("PlayStation" "PlayStation 2" "PlayStation 3" "PlayStation Portable")

atari_system_vars=("_2600_" "_5200_" "_7800_" "jaguar_" "lynx_")
nec_system_vars=("tg16_")
nintendo_system_vars=("_3ds_" "_64_" "ds_" "gb_" "gba_" "gbc_" "nes_" "snes_" "vb_")
sega_system_vars=("_32x_" "gg_" "gen_" "ms_")
snk_system_vars=("ngpc_")
sony_system_vars=("ps1_" "ps2_" "ps3_" "psp_")

#			### Menu lists

main_menu_list="$choose

1: Atari
2: NEC
3: Nintendo
4: Sega
5: SNK
6: Sony
$command_all_menu_common
Q: Quit

"

command_menu_list="$choose

R: Generate Report
C: Copy Roms + Generate Report
M: Move Roms + Generate Report
B: Previous Menu
$menu_main_quit

"

atari_menu_list="$choose

1: 2600
2: 5200
3: 7800
4: Jaguar
5: Lynx
$command_all_menu_common
$menu_main_quit

"

nec_menu_list="$choose

1: TurboGrafx 16\PC Engine
$command_all_menu_common
$menu_main_quit

"

nintendo_menu_list="$choose

1: 3DS
2: 64
3: DS
4: Game Boy
5: Game Boy Advance
6: Game Boy Color
7: Nintendo Entertainment System
8: Super Nintendo Entertainment System
9: Virtual Boy
$command_all_menu_common
$menu_main_quit

"

sega_menu_list="$choose

1: 32X
2: Game Gear
3: Genesis\Mega Drive
4: Master System
$command_all_menu_common
$menu_main_quit

"

snk_menu_list="$choose

1: Neo Geo Pocket Color
$command_all_menu_common
$menu_main_quit

"

sony_menu_list="$choose

1: PlayStation
2: PlayStation 2
3: PlayStation 3
4: PlayStation Portable
$command_all_menu_common
$menu_main_quit

"
