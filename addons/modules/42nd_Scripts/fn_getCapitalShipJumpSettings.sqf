params [
    ["_shipClass", "", [""]],
    ["_finalAltitude", 2000, [0]]
];

private _superCapitalShips =
[
    "ls_staticShip_mandator",
    "ls_staticShip_lucrehulk",
    "ls_staticShip_subjugator"
];

private _heavyCapitalShips =
[
    "ls_staticShip_venator_zeus",
    "ls_staticShip_venator",
    "ls_staticShip_venator_hollow",
    "ls_staticShip_venator_fullHollow",
    "ls_staticShip_venator_open",
    "ls_staticShip_venator_open_hollow",
    "ls_staticShip_venator_open_fullHollow",
    "ls_staticShip_providence_zeus",
    "ls_staticShip_providence",
    "ls_staticShip_providence_hollow",
    "ls_staticShip_providence_dreadnought_zeus",
    "ls_staticShip_providence_dreadnought",
    "ls_staticShip_providence_dreadnought_hollow",
    "ls_staticShip_recusant_zeus_dreadnought",
    "ls_staticShip_recusant_dreadnought"
];

private _capitalShips =
[
    "ls_staticShip_acclamator",
    "ls_staticShip_acclamator_hollow",
    "ls_staticShip_quasar",
    "ls_staticShip_munificent",
    "ls_staticShip_recusant_zeus",
    "ls_staticShip_recusant"
];

private _escortShips =
[
    "ls_staticShip_c9LightCruiser_republic",
    "ls_staticShip_fg40SupportFrigate",
    "ls_staticShip_hardcell",
    "ls_staticShip_coreShip",
    "ls_staticShip_diamondClassCruiser_cis",
    "ls_staticShip_dby827",
    "ls_staticShip_sdsStealthShip"
];

private _startDistance = 5000;
private _jumpDistance = 1000;
private _jumpDuration = 0.4;
private _driftDuration = 6.5;
private _dirOffset = 0;

switch (true) do
{
    case (_shipClass in _superCapitalShips):
    {
        _startDistance = 12000;
        _jumpDistance = 2600;
        _jumpDuration = 0.55;
        _driftDuration = 12;
    };
    case (_shipClass in _heavyCapitalShips):
    {
        _startDistance = 8500;
        _jumpDistance = 1800;
        _jumpDuration = 0.5;
        _driftDuration = 9;
    };
    case (_shipClass in _capitalShips):
    {
        _startDistance = 6500;
        _jumpDistance = 1400;
        _jumpDuration = 0.45;
        _driftDuration = 7.5;
    };
    case (_shipClass in _escortShips):
    {
        _startDistance = 4200;
        _jumpDistance = 900;
        _jumpDuration = 0.35;
        _driftDuration = 6;
    };
};

private _altitudeScale = (_finalAltitude max 250) min 6000;
_startDistance = _startDistance max (_altitudeScale * 1.5);
_jumpDistance = _jumpDistance max (_altitudeScale * 0.35);
_jumpDistance = _jumpDistance min (_startDistance * 0.6);

[
    _startDistance,
    _jumpDistance,
    _jumpDuration,
    _driftDuration,
    _dirOffset
]
