#!/bin/bash

if [ -z "$_7z_args" ]; then
    _7z_args="-t7z"
fi

shopt -s extglob nullglob
7z_input_is_output() {
	local i
    local d_input="${system_prefix}_input"
    local input="${!d_input}"
    ./"$igir_binary" $command --dat "$dat" --input "$input" --output "$runtime_output" $options -X "$exclude" <<< 1 >/dev/null 2>&1
    [[ -z "$backup_path" || -z "$input" || -z "$igirst_dir" ]] && return 1
    files=("$backup_path"/*.7z)
    if (( ${#files[@]} == 0 )); then
        shopt -u extglob nullglob
        return 1
    fi
    printf '%s' "$_7z_process"
    cd "$backup_path" || { shopt -u extglob nullglob >/dev/null 2>&1; return 1; }
    for i in *.7z; do
        [[ -f "$i" ]] || continue
        "$_7z_command" x "$i" -aou -o"$igirst_dir/$input" >/dev/null 2>&1 && rm -- "$i"
    done
    cd "$igirst_dir" || { shopt -u extglob nullglob >/dev/null 2>&1; return 1; }
    ./"$igir_binary" $command --dat "$dat" --input "$input" --output "$runtime_output" $options -X "$exclude" <<< 1 >/dev/null 2>&1
    cd "$input" || { shopt -u extglob nullglob >/dev/null 2>&1; return 1; }
    for i in *.!(7z*|zip*); do
        [[ -f "$i" ]] || continue
        "$_7z_command" a $_7z_args "${i%.*}.7z" "$i" >/dev/null 2>&1 && rm -- "$i"
    done
    shopt -u extglob nullglob
    cd "$igirst_dir" >/dev/null 2>&1 || { shopt -u extglob nullglob >/dev/null 2>&1; return 1; }
}

7z_input_not_output() {
	local i
    local d_input="${system_prefix}_input"
    local input="${!d_input}"
    local target_dest="$runtime_output"
    command_igir <<< 1 >/dev/null 2>&1
    [[ -z "$input" || -z "$target_dest" || -z "$igirst_dir" ]] && return 1
    files=("$input"/*.7z)
    if (( ${#files[@]} == 0 )); then
        shopt -u extglob nullglob
        return 1
    fi
    printf '%s' "$_7z_process"
    cd "$input" || { shopt -u extglob nullglob >/dev/null 2>&1; return 1; }
    for i in *.7z; do
        [[ -f "$i" ]] || continue
        "$_7z_command" x "$i" -aou -o"." >/dev/null 2>&1 && rm -- "$i"
    done
    cd "$igirst_dir" || { shopt -u extglob nullglob >/dev/null 2>&1; return 1; }
    command_igir <<< 1 >/dev/null 2>&1
    cd "$target_dest" || { shopt -u extglob nullglob >/dev/null 2>&1; return 1; }
    for i in *.!(7z*|zip*); do
        [[ -f "$i" ]] || continue
        "$_7z_command" a $_7z_args "${i%.*}.7z" "$i" >/dev/null 2>&1 && rm -- "$i"
    done
    shopt -u extglob nullglob
    cd "$igirst_dir" >/dev/null 2>&1 || { shopt -u extglob nullglob >/dev/null 2>&1; return 1; }
}

7z_handler() {
    if [ -z "$_7z_command" ]; then
        return 1
    fi
    if command -v "$_7z_command" &> /dev/null; then
        :
    elif [ -x "$_7z_command" ]; then
        :
    else
        return 1
    fi
    if [[ "$command" == "report" ]]; then
        return 0
    elif [[ "$command" == *"copy"* ]]; then
        return 0
    elif [[ "$command" == *"move"* ]]; then
        local target_add="${system_prefix}_command_add"
        local direct_add="${!target_add}"
        local target_input="${system_prefix}_input"
        local literal_input="${!target_input}"
        if [[ "$direct_add" == *"clean --clean-backup"* ]]; then
            if [[ "$direct_add" =~ --clean-backup[[:space:]]+([^[:space:]]+) ]]; then
                backup_path="${BASH_REMATCH[1]}"
            fi
            if [[ "$literal_input" == "$runtime_output" ]]; then
                7z_input_is_output
                return 0
            else
                7z_input_not_output
                return 0
            fi
        else
            if [[ "$literal_input" == "$runtime_output" ]]; then
                return 0
            else
                7z_input_not_output
                return 0
            fi
        fi
    fi
}
