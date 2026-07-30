# IGIR Shell Tools

<table>
        <tr><td><a href="README.md#Features">Supported Features</a></td><td><a href="README.md#Sytems">Supported Systems</a></td><td><a href="https://github.com/kencinder/igirst/archive/refs/heads/master.zip">Download</a></td></tr>
</table>

A Linux shell script I have put together to make using [IGIR](https://github.com/emmercm/igir) easier, with an interactive text Menu\
for selecting Copy\Move with option for Backup and Reports generated matching the DAT used\
<sub>Archive support is planned using IGIR's native ZIP and external 7zip</sub>

<sub>Windows users can run the script with WSL and the IGIR Linux binary</sub>\
<sub>MacOS users can change `#!/bin/bash` to `#!/usr/bin/env bash` in the script and included files</sub>

`WIP` - Issues and Pull Requests not currently accepted
<br>
<br>
> Configuration for each system is in `igirst.cfg` and may need modified to suit your preferences\
> Defaults are present for everything mandatory but your ROM input path, that should work out of the box
> 
> The `IGIR` binary location can be set in `igirst.cfg` and defaults to `./igir` but should work from any path
>
>`DAT` files can go in the `dats` directory, under the platform/manufacturer, or set the location in `igirst.cfg`
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
