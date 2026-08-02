# IGIR Shell Tools

<table>
        <tr><td><a href="https://github.com/kencinder/igirst#features">Supported Features</a></td><td><a href="https://github.com/kencinder/igirst#systems">Supported Systems</a></td><td><a href="https://github.com/kencinder/igirst/archive/refs/heads/master.zip">Download</a></td></tr>
</table>

A Linux shell script I have put together to make using [IGIR](https://github.com/emmercm/igir) easier

Menu driven selection of Manufacturer and Systems, and the IGIR command to use\
IGIR options and flags can be set on a per system basis in `igirst.cfg`

<img width="260" height="180" alt="image" src="https://github.com/user-attachments/assets/cb8e7a5d-f18e-4979-adcd-8fd5f525e049" /><img width="260" height="180" alt="image" src="https://github.com/user-attachments/assets/83cfeaf8-d77b-4824-931b-359b596bad16" /><img width="260" height="180" alt="image" src="https://github.com/user-attachments/assets/f2c9523b-84d4-471a-88db-8ffd7f75e80b" />

<sub>7z Archive support is planned using external 7zip</sub>

<sub>Windows users can run the script with WSL and the IGIR Linux binary</sub>\
<sub>MacOS users can change `#!/bin/bash` to `#!/usr/bin/env bash` in the script and included files</sub>

<br>
<br>

> Configuration for everything is in `igirst.cfg`
> 
> Defaults set for everything mandatory except your ROM input path
<br>

### Features
<table>
        <tr><th>Feature</th><th>Status</th></tr>
        <tr><td>Report</td><td>:white_check_mark:</td></tr>
        <tr><td>Copy</td><td>:white_check_mark:</td></tr>
        <tr><td>Move</td><td>:white_check_mark:</td></tr>
        <tr><td>Clean+Backup</td><td>:white_check_mark: <a href="https://github.com/kencinder/igirst#cleanbackup">See</a></td></tr>
        <tr><td>Zip</td><td>:white_check_mark: <a href="https://github.com/kencinder/igirst#zip">See</a></td></tr>
        <tr><td>7z</td><td>:construction:</td></tr>
</table>

### Systems

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
Clean and backups are configured in `igirst.cfg` using the Additional IGIR Commands section\
by adding `clean` with `--clean-backup` and optionally using the defined Backup Variables for clean section

### <sub>Zip</sub>
Using [IGIR's ZIP](https://igir.io/output/writing-archives/) feature is as simple as adding `zip` to a systems options in `igirst.cfg`
I may expand on this further in the future with some ideas I have, but for now this works how it works with IGIR directly

### <sub>Recycle</sub>
I do not plan to implement the use of IGIR's `Recycle` with the `Clean` flag\
Without backups this can be destructive on systems without a Recycle/Trash as it permanently deletes files\
Answering `No` when asked to back up, leaves files in place. `Yes` means Unused backups can be deleted if you wish.
