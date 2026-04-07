#!/bin/bash
set -ex

# Activate the python venv
source /opt/venv/bin/activate

# Conan
echo "Getting dependencies via Conan for all cmake presets..."

## Ensure profile exists and is configured for C++20
conan profile detect --force
conan profile path default > /dev/null # Ensure it's initialized
sed -i 's/compiler.cppstd=.*/compiler.cppstd=gnu20/' $(conan profile path default)

# Set Ninja globally
CONF_FILE="$(conan config home)/global.conf"
LINE="tools.cmake.cmaketoolchain:generator=Ninja"
grep -qxF "$LINE" "$CONF_FILE" || echo "$LINE" >> "$CONF_FILE"

# Get the dependencies for all our presets
cd /workspace

mkdir -p /build/debug
conan install . --output-folder=/build/debug --build=missing --update -s compiler.cppstd=gnu20 --settings=build_type=Debug

mkdir -p /build/release
conan install . --output-folder=/build/release --build=missing --update -s compiler.cppstd=gnu20 --settings=build_type=Release

mkdir -p /build/relwithdebuginfo
conan install . --output-folder=/build/relwithdebuginfo --build=missing --update -s compiler.cppstd=gnu20 --settings=build_type=RelWithDebInfo

exec "$@"