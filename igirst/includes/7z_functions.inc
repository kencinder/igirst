#!/bin/bash

if [ -z "$_7z_args" ]; then
    _7z_args="-t7z"
fi

shopt -s extglob
7z_input_is_output() {
	printf '%s' "$current_menu_header $_7z_process"
	command_igir <<< 1 >/dev/null 2>&1
	cd "$backup_path" || return
	for i in *.7z; do 7z x "$i" -aou -o"." >/dev/null 2>&1 && rm "$i"; done
	cd - >/dev/null 2>&1 || return
	command_igir <<< 1 >/dev/null 2>&1
	cd "$input" || return
	for i in *.!(7z|zip); do 7z a $_7z_args "${i%.*}.7z" "$i" >/dev/null 2>&1 && rm "$i"; done
	shopt -u extglob
	cd - >/dev/null 2>&1 || return
}

7z_input_not_output() {
	printf '%s' "$current_menu_header $_7z_process"
	command_igir <<< 1 >/dev/null 2>&1
	cd "$input" || return
	for i in *.7z; do 7z x "$i" -aou -o"." >/dev/null 2>&1 && rm "$i"; done
	cd - >/dev/null 2>&1 || return
	command_igir <<< 1 >/dev/null 2>&1
	cd "$output" || return
	for i in *.!(7z|zip); do 7z a $_7z_args "${i%.*}.7z" "$i" >/dev/null 2>&1 && rm "$i"; done
	shopt -u extglob
	cd - >/dev/null 2>&1 || return
}

7z_handler() {
	# Check for 7z Command
	if command -v "7z" &> /dev/null; then
    	:
	else
		return
	fi

	# Check for 7z files
	shopt -s nullglob
	files=("$input"/*.7z)
	shopt -u nullglob

	# If no 7z files exist then exit this function
	if (( ${#files[@]} == 0 )); then
		return
	fi

	# Check if command is only 'report' - No file handling done so skip
	if [[ "$command" == "report" ]]; then
		return
	# Check if command is copy - Unmatched files would need compared between different input and output dirs to work so skip
	elif [[ "$command" == *"copy"* ]]; then
		return
	# Check if command is move
	elif [[ "$command" == *"move"* ]]; then
		# Check if 'clean --clean-backup' is set - Works if input == | != output
		if [[ "$command_add" == *"clean --clean-backup"* ]]; then
			if [[ "$command_add" =~ --clean-backup[[:space:]]+([^[:space:]]+) ]]; then
    			backup_path="${BASH_REMATCH[1]}"
			fi
				# 'clean --clean-backup' present & input == output - Use 7z function for input == output
				if [[ "$input" == "$output" ]]; then
					7z_input_is_output
					return
				else
				# 'clean --clean-backup' present & input != output - Use 7z function for input != output
					7z_input_not_output
					return
				fi
		else
			# No 'clean --clean-backup' & input == output - No 7z possible(Unused requires parsing report and comparing files)
			if [[ "$input" == "$output" ]]; then
				return
			else
			# No 'clean --clean-backup' & input != output - Use 7z function for input != output
				7z_input_not_output
				return
			fi
		fi
	fi
}
