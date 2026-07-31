# IGIR Shell Tools

<table>
        <tr><td><a href="README.md#Features">Supported Features</a></td><td><a href="README.md#Sytems">Supported Systems</a></td><td><a href="https://github.com/kencinder/igirst/archive/refs/heads/master.zip">Download</a></td></tr>
</table>

A Linux shell script I have put together to make using [IGIR](https://github.com/emmercm/igir) easier

Menu driven selection of Manufacturer and Systems, and the IGIR command to use\
IGIR options and flags can be set on a per system basis in `igirst.cfg`

<img width="300" height="200" alt="image" src="https://github.com/user-attachments/assets/cb8e7a5d-f18e-4979-adcd-8fd5f525e049" /><img width="300" height="200" alt="image" src="https://github.com/user-attachments/assets/83cfeaf8-d77b-4824-931b-359b596bad16" /><img width="300" height="200" alt="image" src="https://github.com/user-attachments/assets/f2c9523b-84d4-471a-88db-8ffd7f75e80b" /><img width="300" height="200" alt="image" src="https://github.com/user-attachments/assets/4f5843b5-fe25-4734-9661-df8f85ec638e" /><img width="300" height="200" alt="image" src="https://github.com/user-attachments/assets/cfe8a17a-13a5-40df-a6c5-a06b5bd67e1e" /><img width="300" height="200" alt="image" src="https://github.com/user-attachments/assets/aa3a4b3c-6eb5-47f1-b571-c50f55c70a8b" />

<sub>Archive support is planned using IGIR's native ZIP and external 7zip</sub>

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
        <tr><td>Backup</td><td>:white_check_mark:</td></tr>
        <tr><td>Recycle</td><td><a href="README.md#recycle">See</a></td></tr>
        <tr><td>Zip</td><td>:construction:</td></tr>
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

### <sub>Recycle</sub>
I do not plan to implement the use of IGIR's `Recycle` with the `Clean` flag\
Without backups this can be destructive on systems without a Recycle/Trash as it permanently deletes files\
Answering `No` when asked to back up, leaves files in place. `Yes` means Unused backups can be deleted if you wish.
