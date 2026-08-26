[h1]Zellno PVE Vehicle Protection[/h1]

Small and focused vehicle protection for full-PVE DayZ servers.

[h2]Features[/h2]

[list]
[*]Prevents players from damaging vehicles with firearms.
[*]Prevents players from damaging vehicles with melee attacks and fists.
[*]Protects vehicle attachments such as doors, windows, wheels, radiator,
battery and spark plug.
[*]Prevents cars from causing vanilla TransportHit damage to players.
[*]Preserves collision, mechanical, environmental and maintenance damage.
[*]Preserves crash damage to vehicle occupants.
[*]Preserves vehicle collision damage against infected and animals.
[/list]

[h2]Compatibility[/h2]

[list]
[*]DayZ 1.29
[*]Vanilla wheeled vehicles
[*]CarPack vehicles based on CarScript
[*]PVEZReloaded
[*]No Community Framework dependency
[/list]

[h2]Current status[/h2]

Version 0.1.0-alpha.

Functional testing has passed with vanilla and CarPack vehicles.

Multiplayer vehicle run-over protection also passed on the Zellno DayZ Server:
another survivor was struck by a player-driven vehicle and received no
apparent TransportHit damage.

The multiplayer test was performed with Zellno PVE Vehicle Protection and
PVEZReloaded active. This confirms compatibility in the server's active PVE
configuration, but does not isolate which mod rejected the final damage event.

[h2]Notes[/h2]

Glass impact sounds and visual effects may still play even when vehicle
damage is rejected. Punching vehicle glass may still injure the attacker.
These are preserved vanilla consequences.

[h2]Source code[/h2]

[url=https://github.com/Zellno/ZellnoPVEVehicleProtection]
GitHub — ZellnoPVEVehicleProtection
[/url]

[h2]Monetization Permission[/h2]

Zellno permits the use of Zellno PVE Vehicle Protection on monetized DayZ
servers, provided that the server operator is registered, approved and listed
under Bohemia Interactive's DayZ Server Monetization program and complies
with all applicable rules.

This permission applies only to the original content provided by Zellno in
Zellno PVE Vehicle Protection. It does not grant permission to monetize DayZ
itself or any third-party modification or content used alongside this mod.

Server operators are responsible for obtaining any additional permissions
required by the authors of other mods installed on their servers.

[url=https://www.bohemia.net/monetization]
Official monetization rules
[/url]

[url=https://www.bohemia.net/monetization/approved/dayz]
Approved DayZ servers
[/url]

[h2]License[/h2]

MIT License.

Developed and tested on Linux using the Windows DayZ Tools through Wine.
