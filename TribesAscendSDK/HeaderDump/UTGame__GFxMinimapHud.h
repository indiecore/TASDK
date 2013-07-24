#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.GFxMinimapHud." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UTGame.GFxMinimapHud." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.GFxMinimapHud." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GFxMinimapHud : public GFxMoviePlayer
	{
	public:
		ADD_VAR(::BoolProperty, bIsTeamHUD, 0x1)
		ADD_VAR(::FloatProperty, Radius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, NormalZoomf, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CurZoomf, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bDrawWeaponCrosshairs, 0x2)
		ADD_OBJECT(UTGameReplicationInfo, GRI)
		ADD_OBJECT(UTPlayerReplicationInfo, LastFlagCarrier)
		ADD_OBJECT(UTPlayerReplicationInfo, LastEnemy)
		ADD_VAR(::ByteProperty, LastFlagHome, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, LastScore, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, LastAmmoCount, 0xFFFFFFFF)
		ADD_OBJECT(UTWeapon, LastWeapon)
		ADD_OBJECT(UTVehicle, LastVehicle)
		ADD_OBJECT(GFxObject, MultiKillMC)
		ADD_OBJECT(GFxObject, MultiKillMsg_TF)
		ADD_OBJECT(GFxObject, MultiKillN_TF)
		ADD_OBJECT(GFxObject, HitLocMC)
		ADD_OBJECT(GFxObject, CreditsAndStreaksMC)
		ADD_OBJECT(GFxObject, OffhandsAndFlagMC)
		ADD_OBJECT(GFxObject, EnemyNameTF)
		ADD_OBJECT(GFxObject, CenterTextTF)
		ADD_OBJECT(GFxObject, CenterTextMC)
		ADD_OBJECT(GFxObject, TimeTF)
		ADD_OBJECT(GFxObject, TeamStatsMC)
		ADD_OBJECT(GFxObject, PlayerStatsMC)
		ADD_VAR(::IntProperty, NumMessages, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MessageHeight, 0xFFFFFFFF)
		ADD_OBJECT(GFxObject, LogMC)
		// WARNING: Unknown structure type 'ScriptStruct UTGame.GFxMinimapHud.HeEnDisplay' for the property named 'VehicleHE'!
		// WARNING: Unknown structure type 'ScriptStruct UTGame.GFxMinimapHud.HeEnDisplay' for the property named 'PlayerHE'!
		ADD_VAR(::FloatProperty, MinZoomf, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxZoomf, 0xFFFFFFFF)
		ADD_OBJECT(GFxMinimap, Minimap)
		ADD_OBJECT(WorldInfo, ThisWorld)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
