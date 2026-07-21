# IGIR Shell Tools


### Very much `WIP` Issues and PRs are not accepted at this time as I am still working on finishing up initial systems and fine tuning for public use. Use what is here at your own risk!
\
\
A collection of Linux shell scripts I have put together to make using [IGIR](https://github.com/emmercm/igir) easier.

Currently only does scanning, with copy/move with/without backup/recycling and report generation of cart based systems.

My collection is entirely in 7zip form and IGIR does not support creating archives in 7z format at the time of this writing.

I may add support for extracting/adding zip archives when time permits and/or a way to unpack and repack to 7z from files move to backup.

You will need IGIR at the root of the files you find here, every script is written with that in mind, changing the location of it in `igirst.sh` would likely break all functionality.

`DAT` files go in `dats/<platform>` by system and can be zipped or unzipped, env files default to using a systems Parent-Clone XML DAT but can be changed.

`.env` files for each system are in `variables/<platform>` and will need modified to suit your setup, but have defaults present for everything but your ROMs that work out of the box.
