# Changelog

## 0.2.0-alpha

- Added DayZ 1.30 compatibility.
- Added protection for Jana 50 and Bitrak 682 motorcycles based on
  `MotorbikeScript`.
- Added player firearm and melee protection for motorcycle bodies.
- Added player firearm and melee protection for items directly attached to
  supported motorcycles.
- Extended the `TransportHit` source filter to supported motorcycles.
- Preserved the existing `CarScript` protection path.
- Passed local fist, sledgehammer and SNAFU M60 tests with both motorcycle
  models.
- Preserved vanilla crash consequences to the motorcycle rider.
- Documented that multiplayer motorcycle run-over testing was not performed.

## 0.1.0-alpha

- Added player firearm protection for `CarScript`.
- Added player melee protection for `CarScript`.
- Added firearm and melee protection for direct vehicle attachments.
- Added player protection against car-originated `TransportHit` damage.
- Preserved vanilla collision, mechanical and environmental damage.
- Preserved crash damage to occupants.
- Preserved vehicle damage against infected and animals.
- Completed vanilla Ada 4x4 functional tests.
- Validated light and heavy fist attacks against a vanilla vehicle.
- Completed CarPack Cadillac Escalade functional tests.
- Validated light and heavy fist attacks against a CarPack vehicle.
- Preserved vanilla attacker bleeding when punching vehicle glass.
- Completed multiplayer run-over testing against another survivor.
- Confirmed no `TransportHit` damage against the survivor.
