# Test Matrix

## Environment

- DayZ Server: 1.30.164078.38
- Mission: `zellno.chernarusplus`
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

## DayZ 1.30 motorcycles

The Jana 50 and Bitrak 682 inherit from `MotorbikeScript`. Both motorcycle
models were tested locally; their seven color variants use the same supported
base family.

| Test | Jana 50 | Bitrak 682 |
|---|---|---|
| Server and client loading | Passed | Passed |
| Fist attacks | Passed | Passed |
| Sledgehammer attacks | Passed | Passed |
| SNAFU M60 automatic fire | Passed | Passed |
| Vehicle inspection after player attacks | No damage detected | No damage detected |
| Normal engine and riding behavior | Passed | Passed |
| Crash consequences to rider | Not repeated | Preserved; rider killed |
| Visible motorcycle damage after tested crash | Not evaluated | No damage detected |

The absence of visible motorcycle damage after the tested Bitrak 682 crash is
recorded as observed DayZ 1.30 behavior. The mod does not reject motorcycle
collision damage: only player-originated `CLOSE_COMBAT` and `FIRE_ARM` events
are filtered.

## Scope validation

A nearby RaG vehicle-lift notebook was destroyed by automatic fire while the
vehicle remained undamaged. This confirmed that the protection does not make
nearby world objects invulnerable.

## Multiplayer tests

| Test | Status |
|---|---|
| Car run-over against another survivor | Passed |
| Motorcycle run-over against another survivor | Not performed |

Another survivor was struck by a player-driven car and received no
`TransportHit` damage.

Motorcycle-originated `TransportHit` protection uses the same shared
vehicle-family filter and recognizes `MotorbikeScript`. A direct motorcycle
run-over test was not performed because a second local client was unavailable.
