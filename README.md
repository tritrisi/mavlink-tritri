# TRITRI MAVLink dialect

TRITRI is a downstream MAVLink 2 dialect for Speed0 counter-UAS command and control.
It layers private COP messages on top of the shared [MAVLink-M](https://github.com/Dronecode/mavlink-military)
vocabulary (`53000-53099`). See [Dronecode/mavlink-military](https://github.com/Dronecode/mavlink-military).

## What's in this repository

| File | Purpose |
| --- | --- |
| `military.xml` | Shared MAVLink-M dialect (from [Dronecode/mavlink-military](https://github.com/Dronecode/mavlink-military)). |
| `tritri.xml` | TRITRI dialect root — includes `military.xml` and defines private COP messages `53900-53901`. |
| `military_extensions.xml` | Upstream template only; TRITRI uses `tritri.xml` instead. |
| `docs/C2_INTEGRATION.md` | C2-facing integration guide (architecture, engagement flow, message field tables). |
| `generated/` | Pre-generated C headers for the full TRITRI dialect (`military` + `tritri` message sets). |
| [`IDMAPPING.md`](IDMAPPING.md) | Message-ID allocation for `53000-53999`. |
| `scripts/generate.sh` | Regenerate C headers locally. |

## Private TRITRI messages

| Name | ID | Role |
| --- | --- | --- |
| `TRITRI_TRACK` | 53900 | Track identity / correlation spine on the live COP path. |
| `TRITRI_TARGET` | 53901 | Live air kinematics correlated by `track_uid`. |

Shared engagement messages (`TARGET_HANDOVER`, `FIRES`, `ENGAGEMENT_DIRECTIVE`, `MAVLINK_M_ACK`,
`BATTLE_DAMAGE_ASSESSMENT`, etc.) come from `military.xml`. See [`docs/C2_INTEGRATION.md`](docs/C2_INTEGRATION.md)
for the Speed0 wire profile (sysids, instance routing, engagement states).

## Generate bindings

```sh
./scripts/generate.sh
```

Or with [mavgen](https://mavlink.io/en/getting_started/generate_language.html) directly after
placing `military.xml` and `tritri.xml` beside upstream `common.xml`:

```sh
python3 -m pymavlink.tools.mavgen \
  --lang=C --wire-protocol=2.0 --no-validate \
  --output=out tritri.xml
```

Pre-generated C headers live under `generated/include/mavlink/v2.0/`. Include
`tritri/mavlink.h` for the full dialect.

## Upstream

- Shared MAVLink-M spec and ID policy: [Dronecode/mavlink-military](https://github.com/Dronecode/mavlink-military)
- TRITRI private IDs (`53900-53999`) are program-specific; participating systems must share this ICD.

## License

MIT. See [`LICENSE`](LICENSE).
