#!/bin/bash

#			### Common menu variables

choose="Choose an option:"

command_all_menu_common="R: Generate Report for all Systems
C: Copy Roms + Generate Report for all Systems
M: Move Roms + Generate Report for all Systems"

menu_top="			****************************************************
			*                                                  *
			*                 IGIR SHELL TOOLS                 *
			*                                                  *"

menu_bottom="			*                                                  *
			****************************************************"

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

#			### Menu headers and lists

#===# Command Menu #===#

command_menu_list="$choose

R: Generate Report
C: Copy Roms + Generate Report
M: Move Roms + Generate Report
B: Previous Menu
$menu_main_quit

"

#===# Main Menu #===#

main_menu_header="
$menu_top
			*                    Main Menu                     *
$menu_bottom

"

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

#===# Atari Menu #===#

atari_menu_header="
$menu_top
			*                      Atari                       *
$menu_bottom

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

#===# Atari System Menus #===#

atari_2600_menu_header="
$menu_top
			*                   Atari - 2600                   *
$menu_bottom
            
"

atari_5200_menu_header="
$menu_top
			*                   Atari - 5200                   *
$menu_bottom
            
"

atari_7800_menu_header="
$menu_top
			*                   Atari - 7800                   *
$menu_bottom
            
"

atari_jaguar_menu_header="
$menu_top
			*                  Atari - Jaguar                  *
$menu_bottom
            
"

atari_lynx_menu_header="
$menu_top
			*                   Atari - Lynx                   *
$menu_bottom
            
"
#===# NEC Menu #===#

nec_menu_header="
$menu_top
			*                      NEC                         *
$menu_bottom

"

nec_menu_list="$choose

1: TurboGrafx 16\PC Engine
$command_all_menu_common
$menu_main_quit

"

#===# NEC System Menus #===#

nec_tg16_menu_header="
$menu_top
			*               NEC - TurboGrafx-16                *
$menu_bottom
            
"

#===# Nintendo Menu #===#

nintendo_menu_header="
$menu_top
			*                    Nintendo                      *
$menu_bottom

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

#===# Nintendo System Menus #===#

nintendo_3ds_menu_header="
$menu_top
			*                  Nintendo - 3DS                  *
$menu_bottom
            
"

nintendo_64_menu_header="
$menu_top
			*                  Nintendo - 64                   *
$menu_bottom
            
"

nintendo_ds_menu_header="
$menu_top
			*                  Nintendo - DS                   *
$menu_bottom
            
"

nintendo_gb_menu_header="
$menu_top
			*                Nintendo - Game Boy               *
$menu_bottom
            
"

nintendo_gbc_menu_header="
$menu_top
			*             Nintendo - Game Boy Color            *
$menu_bottom
            
"

nintendo_gba_menu_header="
$menu_top
			*            Nintendo - Game Boy Advance           *
$menu_bottom
            
"

nintendo_nes_menu_header="
$menu_top
			*     Nintendo - Nintendo Entertainment System     *
$menu_bottom
            
"

nintendo_snes_menu_header="
$menu_top
			*  Nintendo - Super Nintendo Entertainment System  *
$menu_bottom
            
"

nintendo_vb_menu_header="
$menu_top
			*              Nintendo - Virtual Boy              *
$menu_bottom
            
"

#===# SEGA Menu #===#

sega_menu_header="
$menu_top
			*                       SEGA                       *
$menu_bottom

"

sega_menu_list="$choose

1: 32X
2: Game Gear
3: Genesis\Mega Drive
4: Master System
$command_all_menu_common
$menu_main_quit

"

#===# SEGA System Menus #===#

sega_32x_menu_header="
$menu_top
			*                    SEGA - 32X                    *
$menu_bottom
            
"

sega_gg_menu_header="
$menu_top
			*                 SEGA - Game Gear                 *
$menu_bottom
            
"

sega_gen_menu_header="
$menu_top
			*             SEGA - Genesis\Mega Drive            *
$menu_bottom
            
"

sega_ms_menu_header="
$menu_top
			*               SEGA - Master System               *
$menu_bottom
            
"

#===# SNK Menu #===#

snk_menu_header="
$menu_top
			*                      SNK                         *
$menu_bottom

"

snk_menu_list="$choose

1: Neo Geo Pocket Color
$command_all_menu_common
$menu_main_quit

"

#===# SNK System Menus #===#

snk_ngpc_menu_header="
$menu_top
			*            SNK - Neo Geo Pocket Color            *
$menu_bottom
            
"

#===# Sony Menu #===#

sony_menu_header="
$menu_top
			*                       Sony                       *
$menu_bottom

"

sony_menu_list="$choose

1: PlayStation
2: PlayStation 2
3: PlayStation 3
4: PlayStation Portable
$command_all_menu_common
$menu_main_quit

"

#===# Sony System Menus #===#

sony_ps1_menu_header="
$menu_top
			*                Sony - PlayStation                *
$menu_bottom
            
"

sony_ps2_menu_header="
$menu_top
			*               Sony - PlayStation 2               *
$menu_bottom
            
"

sony_ps3_menu_header="
$menu_top
			*               Sony - PlayStation  3              *
$menu_bottom
            
"

sony_psp_menu_header="
$menu_top
			*            Sony - PlayStation Portable           *
$menu_bottom
            
"
