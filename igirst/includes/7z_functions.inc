#!/bin/bash

if [ -z "$_7z_args" ]; then
    _7z_args="-t7z"
fi
shopt -s extglob nullglob
7z_input_is_output() {
	command_igir <<< 1 >/dev/null 2>&1
	[[ -z "$backup_path" || -z "$input" || -z "$igirst_dir" ]] && return 1
	# Check for 7z files
	files=("$backup_path"/*.7z)
	# If no 7z files exist then exit this function
	if (( ${#files[@]} == 0 )); then
		shopt -u extglob nullglob
		return
	fi
	printf '%s' "$current_menu_header $_7z_process"
	cd "$backup_path" || { shopt -u extglob nullglob >/dev/null 2>&1; return 1; }
	for i in *.7z; do
		[[ -f "$i" ]] || continue
		"$_7z_command" x "$i" -aou -o"." >/dev/null 2>&1 && rm -- "$i"
	done
	cd "$igirst_dir" || { shopt -u extglob nullglob >/dev/null 2>&1; return 1; }
	command_igir <<< 1 >/dev/null 2>&1
	cd "$input" || { shopt -u extglob nullglob >/dev/null 2>&1; return 1; }
	for i in *.!(7z|zip); do
		[[ -f "$i" ]] || continue
		"$_7z_command" a $_7z_args "${i%.*}.7z" "$i" >/dev/null 2>&1 && rm -- "$i"
	done
	shopt -u extglob nullglob
	cd "$igirst_dir" >/dev/null 2>&1 || { shopt -u extglob nullglob >/dev/null 2>&1; return 1; }
}

7z_input_not_output() {
	command_igir <<< 1 >/dev/null 2>&1
	[[ -z "$input" || -z "$output" || -z "$igirst_dir" ]] && return 1
	# Check for 7z files
	files=("$input"/*.7z)
	# If no 7z files exist then exit this function
	if (( ${#files[@]} == 0 )); then
		shopt -u extglob nullglob
		return
	fi
	printf '%s' "$current_menu_header $_7z_process"
	cd "$input" || { shopt -u extglob nullglob >/dev/null 2>&1; return 1; }
	for i in *.7z; do
		[[ -f "$i" ]] || continue
		"$_7z_command" x "$i" -aou -o"." >/dev/null 2>&1 && rm -- "$i"
	done
	cd "$igirst_dir" || { shopt -u extglob nullglob >/dev/null 2>&1; return 1; }
	command_igir <<< 1 >/dev/null 2>&1
	cd "$output" || { shopt -u extglob nullglob >/dev/null 2>&1; return 1; }
	for i in *.!(7z|zip); do
		[[ -f "$i" ]] || continue
		"$_7z_command" a $_7z_args "${i%.*}.7z" "$i" >/dev/null 2>&1 && rm -- "$i"
	done
	shopt -u extglob nullglob
	cd "$igirst_dir" >/dev/null 2>&1 || { shopt -u extglob nullglob >/dev/null 2>&1; return 1; }
}

7z_handler() {
	# Check for 7z Command
	if [ -z "$_7z_command" ]; then
		return 0
	fi
	if command -v "$_7z_command" &> /dev/null; then
		:
	elif [ -x "$_7z_command" ]; then
		:
	else
		return 1
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
