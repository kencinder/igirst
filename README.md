# IGIR Shell Tools


**Currently `WIP` - Issues and Pull Requests not currently accepted\
I am working on finishing up initial systems and fine tuning for public use\
\
Everything is currently in a functioning state, except for systems under a manufacturer who's scripts are not present\
I recommend running a report only first, and using the options with backup or having your own backups beforehand\
Use what is here at your own risk!**
\
\
\
Clone this repository or download the latest files [here](https://github.com/kencinder/igirst/archive/refs/heads/master.zip)
\
\
\
A collection of Linux shell scripts I have put together to make using [IGIR](https://github.com/emmercm/igir) easier

Currently only does scanning, with copy/move, selectable backup and report generation of cart based systems

The `IGIR` binary location can be set in `igirst.cfg` and defaults to `./igir` but should work from anywhere

`DAT` files go in the `dats` directory, under the platform/manufacturer name, or the location of your choice\
They can be zipped or unzipped, the config defaults to using a systems No-Intro Parent-Clone XML DAT

Configuration for each system is in `igirst.cfg` and may need modified to suit your preferences\
Defaults are present for everything but your ROMs that should work out of the box
\
\
My collection is entirely in 7zip form and IGIR does not support creating archives in 7z format at the time of this writing.

I plan to add support for extracting/adding zip archives when time permits, and a possibly a way to unpack and scan/repack to 7z.