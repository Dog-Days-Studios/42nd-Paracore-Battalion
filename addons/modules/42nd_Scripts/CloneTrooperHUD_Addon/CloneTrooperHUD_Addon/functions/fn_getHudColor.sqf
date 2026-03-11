private _preset = missionNamespace getVariable ["CTHUD_colorPreset", "default"];
private _custom = missionNamespace getVariable ["CTHUD_customColor", [0.15, 0.65, 1, 1]];

switch (toLower _preset) do
{
    case "green": { [0.1, 1, 0.2, 1] };
    case "amber": { [1, 0.75, 0.1, 1] };
    case "red": { [1, 0.2, 0.2, 1] };
    case "protanopia": { [0.2, 0.8, 1, 1] };
    case "deuteranopia": { [1, 1, 0.2, 1] };
    case "tritanopia": { [1, 0.45, 0.2, 1] };
    case "mono": { [1, 1, 1, 1] };
    case "custom": { _custom };
    default { [0.15, 0.65, 1, 1] };
};
