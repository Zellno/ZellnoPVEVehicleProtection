# Zellno PVE Vehicle Protection

Small and focused vehicle protection for full-PVE DayZ servers.

## Status

Version `0.2.0-alpha` for DayZ 1.30.

The implementation has completed functional testing with vanilla cars,
CarPack vehicles and the DayZ 1.30 Jana 50 and Bitrak 682 motorcycles.
Multiplayer car run-over protection has also passed: another survivor was
struck by a player-driven car and received no `TransportHit` damage.

Motorcycle-originated `TransportHit` protection is implemented through the same
shared vehicle-family filter. A direct motorcycle run-over test against another
survivor was not performed because a second local client was unavailable.

## Features

- Prevents players from damaging supported cars and motorcycles with
  firearms.
- Prevents players from damaging supported cars and motorcycles with melee
  attacks.
- Protects supported vehicle attachments such as doors, windows, wheels,
  radiator, battery and spark plug from player firearms and melee attacks.
- Prevents supported cars and motorcycles from causing vanilla `TransportHit`
  damage to players.
- Preserves collision damage to vehicles.
- Preserves crash damage to vehicle occupants.
- Preserves mechanical, environmental and maintenance damage.
- Preserves vehicle collision damage against infected and animals.
- Does not make nearby objects invulnerable.

## Preserved behavior

The mod does not block:

- vehicle collisions with terrain, buildings, trees or other objects;
- damage caused by engine misuse or environmental conditions;
- crash damage applied directly to occupants;
- explosions;
- traps;
- infected and animal damage unless it is a player-originated firearm or
  melee attack against a protected vehicle;
- direct damage aimed at an occupant through a vehicle opening.

Direct player-versus-player damage remains the responsibility of DayZ and
other PVE systems such as PVEZReloaded.

## Implementation

The mod uses the official `EEOnDamageCalculated` callback, which runs
immediately before damage is applied.

Four narrowly scoped filters are used:

1. A shared vehicle-family helper recognizes `CarScript` and
   `MotorbikeScript`.
2. `CarScript` and `MotorbikeScript` reject `CLOSE_COMBAT` and `FIRE_ARM`
   damage originating from a player or an item parented to a player.
3. `ItemBase` rejects the same player-originated damage only when the item's
   direct hierarchy parent belongs to a supported vehicle family.
4. `PlayerBase` rejects only `CUSTOM` damage whose ammo identifier is
   `TransportHit` and whose source belongs to a supported vehicle family.

Every other damage event is passed to the existing callback chain through
`super.EEOnDamageCalculated(...)`.

## Compatibility

Designed for:

- DayZ 1.30;
- vanilla wheeled vehicles based on `CarScript`;
- Jana 50 and Bitrak 682 motorcycles based on `MotorbikeScript`;
- CarPack vehicles based on `CarScript`;
- PVEZReloaded;
- Linux-hosted development and testing.

The mod has no Community Framework dependency and contains no models,
textures, sounds or other external resources.

## Testing summary

Approved with a vanilla Ada 4x4:

- light and heavy fist attacks;
- heavy melee-weapon attacks against body and attachments;
- M249 automatic fire;
- Alligator high-caliber fire;
- collision damage;
- occupant crash effects;
- infected collision damage;
- animal collision damage.

Approved with a CarPack Cadillac Escalade:

- heavy melee attacks;
- M249 automatic fire;
- Alligator high-caliber fire;
- collision damage.

Approved locally with the DayZ 1.30 Jana 50 and Bitrak 682:

- fist attacks;
- sledgehammer attacks;
- SNAFU M60 automatic fire;
- no vehicle damage detected after player attacks;
- vanilla crash consequences to the rider preserved.

Motorcycle run-over protection against another survivor was not directly
tested. See `TESTING.md` for the complete test matrix and multiplayer results.

## Development environment

Developed and built on Linux using the Windows DayZ Tools through Wine.

## Monetization Permission

Zellno permits the use of Zellno PVE Vehicle Protection on monetized DayZ
servers, provided that the server operator is registered, approved and listed
under Bohemia Interactive's DayZ Server Monetization program and complies
with all applicable rules.

This permission applies only to the original content provided by Zellno in
Zellno PVE Vehicle Protection. It does not grant permission to monetize DayZ
itself or any third-party modification or content used alongside this mod.

Server operators are responsible for obtaining any additional permissions
required by the authors of other mods installed on their servers.

- [Official monetization rules](https://www.bohemia.net/monetization)
- [Approved DayZ servers](https://www.bohemia.net/monetization/approved/dayz)

## License

MIT.
