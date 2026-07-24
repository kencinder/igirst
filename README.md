# IGIR Shell Tools


**Currently `WIP` - Issues and Pull Requests not currently accepted.\
I am working on finishing up initial systems and fine tuning for public use.\
\
Everything is currently in a functioning state, except for systems under a manufacturer who's scripts are not present.\
I recommend running a report only first, and using the options with backup or having your own backups beforehand. Use what is here at your own risk!**
\
\
\
Clone this repository or download the latest files [here](https://github.com/kencinder/igirst/archive/refs/heads/master.zip)
\
\
\
A collection of Linux shell scripts I have put together to make using [IGIR](https://github.com/emmercm/igir) easier.

Currently only does scanning, with copy/move with/without backup/recycling and report generation of cart based systems.

My collection is entirely in 7zip form and IGIR does not support creating archives in 7z format at the time of this writing.

I plan to add support for extracting/adding zip archives when time permits, and a poissibly a way to unpack and scan/repack to 7z.

The `IGIR` binary location can be set in `variables/includes/files.env` and defaults to `./igir` but should work from anywhere.

`DAT` files go in the `dats` directory, under the platform/manufacturer name,  and can be zipped or unzipped, env files default to using a systems No-Intro Parent-Clone XML DAT.

`.env` files for each system are in `variables` and will need modified to suit your setup, but have defaults present for everything but your ROMs that work out of the box.
