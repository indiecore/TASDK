#pragma once
#include "GFxUI__GFxMoviePlayer.h"
#include "UTGame__UTWeapon.h"
#include "UTGame__UTPlayerReplicationInfo.h"
#include "UTGame__UTGameReplicationInfo.h"
#include "UTGame__GFxMinimap.h"
#include "UTGame__UTVehicle.h"
#include "GFxUI__GFxObject.h"
#include "Engine__WorldInfo.h"
#include "Engine__Weapon.h"
#include "Engine__LocalPlayer.h"
#include "Engine__PlayerReplicationInfo.h"
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
		// Here lies the not-yet-implemented method 'registerMiniMapView'
		// Here lies the not-yet-implemented method 'SetAmmoCountTF'
		// Here lies the not-yet-implemented method 'CreateMessageRow'
		// Here lies the not-yet-implemented method 'InitMessageRow'
		// Here lies the not-yet-implemented method 'Init'
		// Here lies the not-yet-implemented method 'LoadHeEn'
		// Here lies the not-yet-implemented method 'UpdateHealth'
		// Here lies the not-yet-implemented method 'UpdateEnergy'
		// Here lies the not-yet-implemented method 'FormatTime'
		// Here lies the not-yet-implemented method 'ClearStats'
		// Here lies the not-yet-implemented method 'RemoveMessage'
		// Here lies the not-yet-implemented method 'AddMessage'
		// Here lies the not-yet-implemented method 'UpdateGameHUD'
		// Here lies the not-yet-implemented method 'TickHud'
		// Here lies the not-yet-implemented method 'ToggleCrosshair'
		// Here lies the not-yet-implemented method 'MinimapZoomOut'
		// Here lies the not-yet-implemented method 'MinimapZoomIn'
		// Here lies the not-yet-implemented method 'DisplayHit'
		// Here lies the not-yet-implemented method 'ShowMultiKill'
		// Here lies the not-yet-implemented method 'SetCenterText'
		// Here lies the not-yet-implemented method 'GetRank'
		// Here lies the not-yet-implemented method 'AddDeathMessage'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
