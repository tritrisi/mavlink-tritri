#!/usr/bin/env bash
# Regenerate SVG diagrams from docs/diagrams/*.mmd (dark theme, Cursor-like styling).
set -euo pipefail

DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/../docs/diagrams" && pwd)"
CONFIG="${DIR}/theme.json"
BG="#1e1e1e"
CHROME="${PUPPETEER_EXECUTABLE_PATH:-$(ls -d "${HOME}/.cache/puppeteer/chrome-headless-shell/"*/chrome-headless-shell-mac-*/chrome-headless-shell 2>/dev/null | head -1)}"

if [[ -z "${CHROME}" || ! -x "${CHROME}" ]]; then
  echo "Install Chrome headless: npx puppeteer browsers install chrome-headless-shell" >&2
  exit 1
fi

export PUPPETEER_EXECUTABLE_PATH="${CHROME}"

for mmd in "${DIR}"/*.mmd; do
  out="${mmd%.mmd}.svg"
  echo "Rendering $(basename "${mmd}") ..."
  npx --yes @mermaid-js/mermaid-cli@11.6.0 \
    -c "${CONFIG}" \
    -i "${mmd}" \
    -o "${out}" \
    -b "${BG}"
done

echo "Done."
