# Commands Menu
PS3="Choose a command (1-9): "

# Define the commands
commands=("Generate Report Only" "Scan and Copy Roms" "Scan and Move Roms" "Scan and Copy Roms(Backup Unused)" "Scan and Move Roms(Backup Unused)" "Scan and Copy Roms(Recycle Unused)" "Scan and Move Roms(Recycle Unused)" "Main Menu" "Quit")

# Run the select loop
COLUMNS=1
select cmd in "${commands[@]}"
do
    case $cmd in
        "Generate Report Only")
            command="report"
            source "./scripts/commands.sh"
            break
            ;;
        "Scan and Copy Roms")
            command="copy report"
            source "./scripts/command.sh"
            break
            ;;
        "Scan and Move Roms")
            command="move report"
            source "./scripts/command.sh"
            break
            ;;
        "Scan and Copy Roms(Backup Unused)")
            command="copy clean report --clean-backup"
            source "./scripts/command-backup.sh"
            break
            ;;
        "Scan and Move Roms(Backup Unused)")
            command="move clean report --clean-backup"
            source "./scripts/command-backup.sh"
            break
            ;;
        "Scan and Copy Roms(Recycle Unused)")
            command="copy clean report"
            source "./scripts/commands.sh"
            break
            ;;
        "Scan and Move Roms(Recycle Unused)")
            command="move clean report"
            source "./scripts/commands.sh"
            break
            ;;
        "Main Menu")
            ./igirst.sh && exit
            ;;
        "Quit")
            clear
            echo "Exiting IGIR Shell Tools..."
            sleep 2
            clear
            exit
            ;;
        *)
            echo "Invalid option $REPLY"
            ;;
        esac
    done