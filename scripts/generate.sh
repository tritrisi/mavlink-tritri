#!/usr/bin/env bash
# Generate TRITRI dialect bindings (MAVLink-M + TRITRI private messages).
# Pins match .github/workflows/generate_c_lib.yml — bump both together.
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
DEPS="${ROOT}/.deps"
MAVLINK_DIR="${MAVLINK_DIR:-${DEPS}/mavlink}"
PYMAVLINK_DIR="${PYMAVLINK_DIR:-${DEPS}/pymavlink}"
OUTPUT="${OUTPUT:-${ROOT}/generated/include/mavlink/v2.0}"
MAVGEN_LANG="${MAVGEN_LANG:-C}"
MAVLINK_REF="${MAVLINK_REF:-87da370c02e40f6f9a2eacf1b162d7f07e640467}"
PYMAVLINK_REF="${PYMAVLINK_REF:-19880422d451de4daba3fd96781076afb1cb889c}"

mkdir -p "${DEPS}"

clone_or_checkout() {
  local url=$1 dest=$2 ref=$3
  if [[ ! -d "${dest}/.git" ]]; then
    git clone --depth 1 "${url}" "${dest}"
  fi
  git -C "${dest}" fetch --depth 1 origin "${ref}"
  git -C "${dest}" checkout --detach FETCH_HEAD
}

clone_or_checkout https://github.com/mavlink/mavlink.git "${MAVLINK_DIR}" "${MAVLINK_REF}"
clone_or_checkout https://github.com/ArduPilot/pymavlink.git "${PYMAVLINK_DIR}" "${PYMAVLINK_REF}"

pip install -q future lxml 2>/dev/null || pip3 install -q future lxml

"${ROOT}/.github/scripts/generate_c_headers.sh" \
  "${ROOT}" "${MAVLINK_DIR}" "${PYMAVLINK_DIR}" "${OUTPUT}"

echo "Generated ${MAVGEN_LANG} bindings under ${OUTPUT}"
