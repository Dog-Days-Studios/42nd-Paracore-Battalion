if (!hasInterface) exitWith {};
if (missionNamespace getVariable ["Para42_grappleClientRegistered", false]) exitWith {};

missionNamespace setVariable ["Para42_grappleClientRegistered", true];

if (isNil {missionNamespace getVariable "Para42_grappleDrawEh"}) then {
    private _drawEh = addMissionEventHandler ["Draw3D", {
        call Para42_fnc_drawGrappleRopes;
    }];
    missionNamespace setVariable ["Para42_grappleDrawEh", _drawEh];
};

[] spawn {
    private _lastPlayer = objNull;

    while {true} do {
        if (!isNull player && {_lastPlayer isNotEqualTo player}) then {
            private _oldOwner = missionNamespace getVariable ["Para42_grappleActionOwner", objNull];
            private _oldAction = missionNamespace getVariable ["Para42_grappleActionId", -1];

            if (!isNull _oldOwner && {_oldAction >= 0}) then {
                _oldOwner removeAction _oldAction;
            };

            private _actionId = player addAction [
                "Use Grapple Rope",
                {
                    [_this, "rope"] call Para42_fnc_useGrappleAction;
                },
                nil,
                6,
                true,
                true,
                "",
                "['rope'] call Para42_fnc_canUseGrappleAction"
            ];

            missionNamespace setVariable ["Para42_grappleActionOwner", player];
            missionNamespace setVariable ["Para42_grappleActionId", _actionId];
            _lastPlayer = player;
        };

        uiSleep 1;
    };
};
