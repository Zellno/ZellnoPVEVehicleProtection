class CfgPatches
{
    class ZellnoPVEVehicleProtection
    {
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] =
        {
            "DZ_Data",
            "DZ_Scripts"
        };
    };
};

class CfgMods
{
    class ZellnoPVEVehicleProtection
    {
        dir = "ZellnoPVEVehicleProtection";
        name = "Zellno PVE Vehicle Protection";
        author = "Zellno";
        version = "0.1.0-alpha";
        type = "mod";

        dependencies[] =
        {
            "World"
        };

        class defs
        {
            class worldScriptModule
            {
                value = "";
                files[] =
                {
                    "ZellnoPVEVehicleProtection/scripts/4_World"
                };
            };
        };
    };
};
