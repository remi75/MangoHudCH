#!/bin/sh

MANGOHUD_LIB_NAME="libMangoHud.so:libMangoHud32.so"
if [ "$MANGOHUD_NODLSYM" = "1" ]; then
	MANGOHUD_LIB_NAME="libmangohud_gl_nodlsym.so"
fi

if [ "$#" -eq 0 ]; then
	programname=`basename "$0"`
	echo "ERROR: No program supplied"
	echo
	echo "Usage: $programname <program>"
	exit 1
fi

# Execute the strangled program under a clean environment
# pass through the FPS and overriden LD_PRELOAD environment variables
LD_PRELOAD="${LD_PRELOAD}:${MANGOHUD_LIB_NAME}"

DIRNAME=$(dirname "$0")
LD_LIBRARY_PATH="${HOME}/.local/share/MangoHud"

echo $LD_LIBRARY_PATH
exec env LD_LIBRARY_PATH="$LD_LIBRARY_PATH" LD_PRELOAD="${LD_PRELOAD}" "$@"
