#!/bin/sh
# Generate MAVLink 2 C headers for the TRITRI dialect.
#
# Usage: generate_c_headers.sh <source> <mavlink> <pymavlink> <out>
#   source     checkout of this repository
#   mavlink    checkout of mavlink/mavlink (provides common.xml and friends)
#   pymavlink  checkout of ArduPilot/pymavlink (provides mavgen)
#   out        output directory for the generated headers
set -eu

if [ $# -ne 4 ]; then
	echo "usage: $0 <source> <mavlink> <pymavlink> <out>" >&2
	exit 1
fi

source_dir=$1
mavlink_dir=$2
pymavlink_dir=$3
out_dir=$4
defs=$mavlink_dir/message_definitions/v1.0

# tritri.xml includes military.xml, which includes common.xml by relative path,
# so both dialect files have to sit next to the upstream definitions for mavgen.
cp "$source_dir/military.xml" "$source_dir/tritri.xml" "$defs/"

python3 "$pymavlink_dir/tools/mavgen.py" \
	--lang=C \
	--wire-protocol=2.0 \
	--output="$out_dir" \
	"$defs/tritri.xml"

mkdir -p "$out_dir/message_definitions"
for xml in tritri military common standard minimal development; do
	cp "$defs/$xml.xml" "$out_dir/message_definitions/"
done
