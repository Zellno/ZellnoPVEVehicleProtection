class ZPVP_DamageSource
{
    static bool IsControlledByPlayer(EntityAI source)
    {
        if (!source)
        {
            return false;
        }

        if (source.IsPlayer())
        {
            return true;
        }

        EntityAI parent = source.GetHierarchyParent();

        if (parent && parent.IsPlayer())
        {
            return true;
        }

        return false;
    }
}

modded class CarScript
{
    override bool EEOnDamageCalculated(TotalDamageResult damageResult, int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos, float speedCoef)
    {
        if ((damageType == DamageType.CLOSE_COMBAT || damageType == DamageType.FIRE_ARM) && ZPVP_DamageSource.IsControlledByPlayer(source))
        {
            return false;
        }

        return super.EEOnDamageCalculated(damageResult, damageType, source, component, dmgZone, ammo, modelPos, speedCoef);
    }
}

modded class ItemBase
{
    override bool EEOnDamageCalculated(TotalDamageResult damageResult, int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos, float speedCoef)
    {
        EntityAI parent = GetHierarchyParent();

        if (CarScript.Cast(parent) && (damageType == DamageType.CLOSE_COMBAT || damageType == DamageType.FIRE_ARM) && ZPVP_DamageSource.IsControlledByPlayer(source))
        {
            return false;
        }

        return super.EEOnDamageCalculated(damageResult, damageType, source, component, dmgZone, ammo, modelPos, speedCoef);
    }
}

modded class PlayerBase
{
    override bool EEOnDamageCalculated(TotalDamageResult damageResult, int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos, float speedCoef)
    {
        if (damageType == DamageType.CUSTOM && ammo == "TransportHit" && CarScript.Cast(source))
        {
            return false;
        }

        return super.EEOnDamageCalculated(damageResult, damageType, source, component, dmgZone, ammo, modelPos, speedCoef);
    }
}
