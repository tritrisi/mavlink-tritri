#!/usr/bin/env bash
# Generate TRITRI dialect bindings (MAVLink-M + TRITRI private messages).
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
DEPS="${ROOT}/.deps"
MAVLINK_DIR="${MAVLINK_DIR:-${DEPS}/mavlink}"
PYMAVLINK_DIR="${PYMAVLINK_DIR:-${DEPS}/pymavlink}"
OUTPUT="${OUTPUT:-${ROOT}/generated/include/mavlink/v2.0}"
MAVGEN_LANG="${MAVGEN_LANG:-C}"

mkdir -p "${DEPS}"

if [[ ! -f "${MAVLINK_DIR}/message_definitions/v1.0/common.xml" ]]; then
  git clone --depth 1 https://github.com/mavlink/mavlink.git "${MAVLINK_DIR}"
fi

if [[ ! -f "${PYMAVLINK_DIR}/tools/mavgen.py" ]]; then
  git clone --depth 1 https://github.com/ArduPilot/pymavlink.git "${PYMAVLINK_DIR}"
fi

pip install -q future lxml 2>/dev/null || pip3 install -q future lxml

cp "${ROOT}/military.xml" "${ROOT}/tritri.xml" "${MAVLINK_DIR}/message_definitions/v1.0/"

rm -rf "${OUTPUT}"
mkdir -p "${OUTPUT}"

python3 "${PYMAVLINK_DIR}/tools/mavgen.py" \
  --lang="${MAVGEN_LANG}" \
  --wire-protocol=2.0 \
  --no-validate \
  --output="${OUTPUT}" \
  "${MAVLINK_DIR}/message_definitions/v1.0/tritri.xml"

echo "Generated ${MAVGEN_LANG} bindings under ${OUTPUT}"
