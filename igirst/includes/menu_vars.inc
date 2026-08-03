#!/bin/bash

			# Common menu variables


choose="Choose a Platform"

menu_top="			****************************************************
			*                                                  *
			*                 IGIR SHELL TOOLS                 *
			*                                                  *"

menu_bottom="			*                                                  *
			****************************************************"


			# Menu headers and lists


	# Command Menu #

command_menu_list="Choose a command (0-5):

1: Generate Report Only
2: Scan and Copy Roms + Generate Report
3: Scan and Move Roms + Generate Report
B: Previous Menu
M: Main Menu
Q: Quit

"

	# Main Menu #

main_menu_header="
$menu_top
			*                    Main Menu                     *
$menu_bottom

"

main_menu_list="$choose or Manufacturer(0-5):

1: Atari
2: NEC
3: Nintendo
4: Sega
5: SNK
Q: Quit

"

	# Atari Menu #

atari_menu_header="
$menu_top
			*                      Atari                       *
$menu_bottom

"

atari_menu_list="$choose(0-6):

1: 2600
2: 5200
3: 7800
4: Jaguar
5: Lynx
M: Main Menu
Q: Quit

"

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
	# NEC Menu #


nec_menu_header="
$menu_top
			*                      NEC                         *
$menu_bottom

"

nec_menu_list="$choose(0-2):

1: TurboGrafx 16\PC Engine
M: Main Menu
Q: Quit

"

nec_tg16_menu_header="
$menu_top
			*               NEC - TurboGrafx-16                *
$menu_bottom
            
"

	# Nintendo Menu #

nintendo_menu_header="
$menu_top
			*                    Nintendo                      *
$menu_bottom

"

nintendo_menu_list="$choose(0-10):

1: 3DS
2: 64
3: DS
4: Game Boy
5: Game Boy Advance
6: Game Boy Color
7: Nintendo Entertainment System
8: Super Nintendo Entertainment System
9: Virtual Boy
M: Main Menu
Q: Quit

"

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

	# SEGA Menu #

sega_menu_header="
$menu_top
			*                       SEGA                       *
$menu_bottom

"

sega_menu_list="$choose(0-5):

1: 32X
2: Game Gear
3: Genesis\Mega Drive
4: Master System
M: Main Menu
Q: Quit

"

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

	# SNK Menu #

snk_menu_header="
$menu_top
			*                      SNK                         *
$menu_bottom

"

snk_menu_list="$choose(0-2):

1: Neo Geo Pocket Color
M: Main Menu
Q: Quit

"

snk_ngpc_menu_header="
$menu_top
			*            SNK - Neo Geo Pocket Color            *
$menu_bottom
            
"
