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

## Multiplayer integration tests

| Test | Status |
|---|---|
| Car run-over against another survivor | Passed |
| PVEZReloaded player protection against a SNAFU M249 | Passed |
| Clothing preservation during blocked player firearm damage | Passed |
| Combined PVEZReloaded and vehicle protection in the active server configuration | Passed |
| Direct firearm hit against a vehicle occupant | Outside this mod's scope |
| Isolated run-over test without PVEZReloaded | Not performed |

Another survivor was struck by a player-driven vehicle and received no
apparent `TransportHit` damage. The test was performed with Zellno PVE Vehicle
Protection and PVEZReloaded active, confirming compatibility in the server's
production mod configuration.

Because PVEZReloaded remained active, this test does not isolate which mod
rejected the final damage event. Zellno PVE Vehicle Protection independently
contains a narrowly scoped filter for car-originated `TransportHit` damage.

PVEZReloaded was also tested separately through direct player-versus-player
automatic fire with a SNAFU M249. The target received no apparent player
damage, and the target's clothing remained undamaged.

Direct firearm damage against a vehicle occupant is not a requirement of
Zellno PVE Vehicle Protection. Player-versus-player damage remains the
responsibility of DayZ and the active PVE system.
