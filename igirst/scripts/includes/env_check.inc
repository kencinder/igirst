if [ -z "$dat" ]; then
    printf "DAT $env_missing $var\n\n"
fi

if [ -z "$input" ]; then
    printf "INPUT $env_missing $var\n\n"
fi

if [ -z "$output" ]; then
    printf "OUPUT $env_missing $var\n\n"
fi

if [ -z "$backup" ]; then
    printf "BACKUP $env_missing $var\n\n"
fi

if [ -z "$report" ]; then
    printf "REPORT $env_missing $var\n\n"
fi

if [[ -z "$dat" || -z "$input" || -z "$output" || -z "$backup" || -z "$report" ]]; then
    read -n 1 -s -r -p "$continue"
    exec $previous_menu
fi