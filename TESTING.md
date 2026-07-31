# Test Matrix

## Environment

- DayZ Server: 1.29.163451
- Steam build ID: 24041098
- Mission: Chernarus
- Platform: Linux
- DayZ Tools: Windows tools executed through Wine
- PVE system present: PVEZReloaded
- Vehicle mod present: CarPack

## Compilation and integration

| Test | Result |
|---|---|
| PBO build with FileBank | Passed |
| Zellno signature | Passed |
| DSCheckSignatures | Passed |
| World module compilation | Passed |
| Server startup with active mod set | Passed |
| PVEZReloaded coexistence at startup | Passed |
| CarPack coexistence at startup | Passed |
| Client symbolic link | Passed |
| Link repair idempotency | Passed |

## Vanilla Ada 4x4

| Test | Result |
|---|---|
| Light fist attacks | Passed |
| Heavy fist attacks | Passed |
| Heavy sledgehammer against body | Passed |
| Heavy sledgehammer against windows | Passed |
| Heavy sledgehammer against doors | Passed |
| Heavy sledgehammer against open trunk | Passed |
| Heavy sledgehammer against wheels | Passed |
| M249 automatic fire | Passed |
| Alligator high-caliber fire | Passed |
| Fire against engine and radiator | Passed |
| Vehicle inspection after player attacks | No damage detected |
| Moderate collision damage | Preserved |
| Damage transfer to vehicle attachments | Preserved |
| Occupant crash effects | Preserved |
| Infected run-over damage | Preserved |
| Animal run-over damage | Preserved |

Visual glass impact effects may still play locally even when server-side
damage is rejected. This is cosmetic and did not reduce vehicle HP.

The attacking player may receive a vanilla bleeding injury when punching
vehicle glass. This self-inflicted consequence remains active even though
vehicle damage is rejected.

## CarPack Cadillac Escalade

| Test | Result |
|---|---|
| Light fist attacks against CarPack | Passed |
| Heavy fist attacks against CarPack | Passed |
| Heavy sledgehammer attacks | Passed |
| M249 automatic fire | Passed |
| Alligator high-caliber fire | Passed |
| Vehicle inspection after player attacks | No damage detected |
| Moderate collision damage | Preserved |
| Damage transfer to radiator | Preserved |

## Scope validation

A nearby RaG vehicle-lift notebook was destroyed by automatic fire while the
vehicle remained undamaged. This confirmed that the protection does not make
nearby world objects invulnerable.

## Pending tests requiring two players

| Test | Status |
|---|---|
| Car run-over against another survivor | Pending |
| Direct firearm hit against vehicle occupant | Pending |
| PVEZReloaded player-versus-player behavior | Pending |
| Combined PVEZReloaded and vehicle protection under two-player combat | Pending |

The alpha must not be described as fully multiplayer-homologated until these
tests are completed.
