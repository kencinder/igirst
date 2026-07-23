main_menu() {
while true; do
    read -p "Select an option: " choice

    if [ -z "$choice" ]; then
        choice=""
    fi

    case $choice in
        1)
            exec ./scripts/atari.sh
            ;;
        2)
            exec ./scripts/nec.sh
            ;;
        3)
            exec ./scripts/nintendo.sh
            ;;
        4)
            exec ./scripts/sega.sh
            ;;
        5)
            exec ./scripts/snk.sh
            ;;
        0)
            clear
            printf "$quit"
            sleep 1
            clear && exit
            ;;
        "")
            printf "$empty_choice"
            sleep 1 && exec "$0" "$@"
            ;;
        *)
            printf "$invalid_choice $choice"
            sleep 1 && exec "$0" "$@"
            ;;
    esac
done
}

atari_menu() {
while true; do
    read -p "Select an option: " choice

    if [ -z "$choice" ]; then
        choice=""
    fi

    case $choice in
        1)
            exec ./scripts/atari/2600.sh
            ;;
        2)
            exec ./scripts/atari/5200.sh
            ;;
        3)
            exec ./scripts/atari/7800.sh
            ;;
        4)
            exec ./scripts/atari/Jaguar.sh
            ;;
        5)
            exec ./scripts/atari/Lynx.sh
            ;;
        6)
            exec ./igirst.sh
            ;;
        0)
            clear
            printf "$quit"
            sleep 1
            clear && exit
            ;;
        "")
            printf "$empty_choice"
            sleep 1 && exec "$0" "$@"
            ;;
        *)
            printf "$invalid_choice $choice"
            sleep 1 && exec "$0" "$@"
            ;;
        esac
    done
}

nec_menu() {
while true; do
    read -p "Select an option: " choice

    if [ -z "$choice" ]; then
        choice=""
    fi

    case $choice in
        1)
            exec ./scripts/nec/tg16.sh
            ;;
        2)
            exec ./igirst.sh
            ;;
        0)
            clear
            printf "$quit"
            sleep 1
            clear && exit
            ;;
        "")
            printf "$empty_choice"
            sleep 1 && exec "$0" "$@"
            ;;
        *)
            printf "$invalid_choice $choice"
            sleep 1 && exec "$0" "$@"
            ;;
        esac
    done
}

nintendo_menu() {
while true; do
    read -p "Select an option: " choice

    if [ -z "$choice" ]; then
        choice=""
    fi

    case $choice in
        1)
            exec ./scripts/nintendo/3ds.sh
            ;;
        2)
            exec ./scripts/nintendo/64.sh
            ;;
        3)
            exec ./scripts/nintendo/ds.sh
            ;;
        4)
            exec ./scripts/nintendo/gb.sh
            ;;
        5)
            exec ./scripts/nintendo/gba.sh
            ;;
        6)
            exec ./scripts/nintendo/gbc.sh
            ;;
        7)
            exec ./scripts/nintendo/nes.sh
            ;;
        8)
            exec ./scripts/nintendo/snes.sh
            ;;
        9)
            exec ./scripts/nintendo/vb.sh
            ;;
        10)
            exec ./igirst.sh
            ;;
        0)
            clear
            printf "$quit"
            sleep 1
            clear && exit
            ;;
        "")
            printf "$empty_choice"
            sleep 1 && exec "$0" "$@"
            ;;
        *)
            printf "$invalid_choice $choice"
            sleep 1 && exec "$0" "$@"
            ;;
        esac
    done
}

sega_menu() {
while true; do
    read -p "Select an option: " choice

    if [ -z "$choice" ]; then
        choice=""
    fi

    case $choice in
        1)
            exec ./scripts/sega/32x.sh
            ;;
        2)
            exec ./scripts/sega/gg.sh
            ;;
        3)
            exec ./scripts/sega/gen.sh
            ;;
        4)
            exec ./scripts/sega/ms.sh
            ;;
        5)
            exec ./igirst.sh
            ;;
        0)
            clear
            printf "$quit"
            sleep 1
            clear && exit
            ;;
        "")
            printf "$empty_choice"
            sleep 1 && exec "$0" "$@"
            ;;
        *)
            printf "$invalid_choice $choice"
            sleep 1 && exec "$0" "$@"
            ;;
        esac
    done
}

snk_menu() {
while true; do
    read -p "Select an option: " choice

    if [ -z "$choice" ]; then
        choice=""
    fi

    case $choice in
        1)
            exec ./scripts/snk/ngpc.sh
            ;;
        2)
            exec ./igirst.sh
            ;;
        0)
            clear
            printf "$quit"
            sleep 1
            clear && exit
            ;;
        "")
            printf "$empty_choice"
            sleep 1 && exec "$0" "$@"
            ;;
        *)
            printf "$invalid_choice $choice"
            sleep 1 && exec "$0" "$@"
            ;;
        esac
    done
}
