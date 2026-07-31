# Zellno PVE Vehicle Protection

Small and focused vehicle protection for full-PVE DayZ servers.

## Status

Version `0.1.0-alpha` for DayZ 1.29.

The implementation has completed single-player functional testing with
vanilla and CarPack vehicles. Tests that require a second survivor remain
pending.

## Features

- Prevents players from damaging cars with firearms.
- Prevents players from damaging cars with melee attacks.
- Protects vehicle attachments such as doors, windows, wheels, radiator,
  battery and spark plug from player firearms and melee attacks.
- Prevents cars from causing vanilla `TransportHit` damage to players.
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

Three narrowly scoped filters are used:

1. `CarScript` rejects `CLOSE_COMBAT` and `FIRE_ARM` damage originating from
   a player or an item parented to a player.
2. `ItemBase` rejects the same player-originated damage only when the item's
   direct hierarchy parent is a `CarScript`.
3. `PlayerBase` rejects only `CUSTOM` damage whose ammo identifier is
   `TransportHit` and whose source is a `CarScript`.

Every other damage event is passed to the existing callback chain through
`super.EEOnDamageCalculated(...)`.

## Compatibility

Designed for:

- DayZ 1.29;
- vanilla wheeled vehicles;
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

See `TESTING.md` for the complete matrix and pending multiplayer tests.

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
