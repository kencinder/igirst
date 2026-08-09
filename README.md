# IGIR Shell Tools

<table>
        <tr><td><a href="https://github.com/kencinder/igirst#systems-currently-with-menu-support">Supported Systems</a></td><td><a href="https://github.com/kencinder/igirst/archive/refs/heads/master.zip">Download</a></td><td><a href="https://github.com/kencinder/igirst/wiki">Wiki</a></td></tr>
</table>

A Linux shell script to make using [IGIR](https://github.com/emmercm/igir) easier

Menu driven selection of Platform and Systems, using the IGIR COPY or MOVE command with Reports\
Individual Systems can be selected, or commands can be run for an entire Manufacturer/Platform

7z Archive support using external 7z - See config for details

All of [IGIR](https://github.com/emmercm/igir)'s commands and options can be set in [the config](https://github.com/kencinder/igirst/blob/master/igirst/igirst.cfg) per system

<img width="260" height="180" alt="image" src="https://github.com/user-attachments/assets/c773e072-37c3-4900-a86a-8c0e849c91d6" /><img width="260" height="180" alt="image" src="https://github.com/user-attachments/assets/30a30b2a-8fe9-40de-a1e8-d954771ee9fb" /><img width="260" height="180" alt="image" src="https://github.com/user-attachments/assets/548afffa-f049-465c-b19c-6fa5900b854c" />

<sub>Windows users can run the script with WSL and the IGIR Linux binary</sub>\
<sub>MacOS users can change `#!/bin/bash` to `#!/usr/bin/env bash` in the script and included files</sub>

<br>

> Configuration for everything is in `igirst.cfg`
> 
> Defaults are set for everything mandatory except your ROM input path

### Systems currently with Menu Support

<table>
        <tr><th>System</th><th>Status</th></tr>
        <tr><td>Atari - 2600</td><td>:white_check_mark:</td></tr>
        <tr><td>Atari - 5200</td><td>:white_check_mark:</td></tr>
        <tr><td>Atari - 7800</td><td>:white_check_mark:</td></tr>
        <tr><td>Atari - Jaguar</td><td>:white_check_mark:</td></tr>
        <tr><td>Atari - Lynx</td><td>:white_check_mark:</td></tr>
        <tr><td>NEC - PC Engine\TurboGrafx-16</td><td>:white_check_mark:</td></tr>
        <tr><td>Nintendo - 3DS</td><td>:white_check_mark:</td></tr>
        <tr><td>Nintendo - 64</td><td>:white_check_mark:</td></tr>
        <tr><td>Nintendo - DS</td><td>:white_check_mark:</td></tr>
        <tr><td>Nintendo - Game Boy</td><td>:white_check_mark:</td></tr>
        <tr><td>Nintendo - Game Boy Advance</td><td>:white_check_mark:</td></tr>
        <tr><td>Nintendo - Game Boy Color</td><td>:white_check_mark:</td></tr>
        <tr><td>Nintendo - NES</td><td>:white_check_mark:</td></tr>
        <tr><td>Nintendo - SNES</td><td>:white_check_mark:</td></tr>
        <tr><td>Nintendo - Virtual Boy</td><td>:white_check_mark:</td></tr>
        <tr><td>Sega - 32X</td><td>:white_check_mark:</td></tr>
        <tr><td>Sega - Game Gear</td><td>:white_check_mark:</td></tr>
        <tr><td>Sega - Genesis\Mega Drive</td><td>:white_check_mark:</td></tr>
        <tr><td>Sega - Master System</td><td>:white_check_mark:</td></tr>
        <tr><td>SNK - Neo Geo Pocket Color</td><td>:white_check_mark:</td></tr>
</table>

### <sub>Clean/Backup</sub>
A safety check is done for `clean` that requires confirmation if `--clean-backup` isn't also present\
Clean & backups configured in `igirst.cfg` using Additional IGIR Commands by adding `clean` with `--clean-backup`
