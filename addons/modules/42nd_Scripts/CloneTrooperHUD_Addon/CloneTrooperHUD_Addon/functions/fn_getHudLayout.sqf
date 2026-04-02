private _preset = toLower (missionNamespace getVariable ["CTHUD_textScalePreset", "default"]);

switch (_preset) do
{
    case "compact": { ["CTHUD_Main_Compact", 0.9, 7] };
    case "large": { ["CTHUD_Main_Large", 1.15, 6] };
    case "xlarge": { ["CTHUD_Main_XLarge", 1.3, 5] };
    default { ["CTHUD_Main", 1, 7] };
};
