#pragma once
#include "UDKBase__UDKMapInfo.h"
#include "Engine__Texture.h"
#include "Engine__Canvas.h"
#include "Engine__Texture2D.h"
#include "UDKBase__UDKVehicle.h"
#include "Engine__MaterialInstanceConstant.h"
#include "Engine__Material.h"
#include "Engine__Actor.h"
#include "UTGame__UTMapMusicInfo.h"
#include "UTGame__UTPlayerController.h"
#include "UTGame__UTVehicle.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTMapInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UTGame.UTMapInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTMapInfo." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTMapInfo : public UDKMapInfo
	{
	public:
		ADD_OBJECT(Texture, MapTexture)
		ADD_STRUCT(::VectorProperty, MapCenter, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, MapExtent, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MapScale, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, RecommendedPlayersMax, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, RecommendedPlayersMin, 0xFFFFFFFF)
		ADD_OBJECT(UDKVehicle, KeyVehicles)
		// WARNING: Unknown structure type 'ScriptStruct Engine.UIRoot.TextureCoordinates' for the property named 'PlayerIconCoords'!
		ADD_OBJECT(MaterialInstanceConstant, GreenIconMaterialInstance)
		ADD_VAR(::FloatProperty, ColorPercent, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, CenterPos, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, RadarRange, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RadarWidth, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, ActualMapCenter, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, UseableRadius, 0xFFFFFFFF)
		ADD_OBJECT(Material, MapMaterialReference)
		ADD_OBJECT(MaterialInstanceConstant, MapMaterialInstance)
		ADD_VAR(::IntProperty, CurrentMapRotYaw, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, MapRotY, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, MapRotX, 0xFFFFFFFF
		ADD_OBJECT(Texture2D, HUDIconsT)
		ADD_OBJECT(Material, HudIcons)
		ADD_OBJECT(Actor, WatchedActor)
		ADD_OBJECT(Actor, CurrentActor)
		ADD_VAR(::BoolProperty, bMapUpToDate, 0x1)
		ADD_VAR(::FloatProperty, DefaultMapSize, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RotatingMiniMapRange, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MapYaw, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MapTextureYaw, 0xFFFFFFFF)
		ADD_OBJECT(UTMapMusicInfo, MapMusicInfo)
		// Here lies the not-yet-implemented method 'VerifyMapExtent'
		// Here lies the not-yet-implemented method 'FindObjectives'
		// Here lies the not-yet-implemented method 'RenderLinks'
		// Here lies the not-yet-implemented method 'RenderAdditionalInformation'
		// Here lies the not-yet-implemented method 'UpdateNodes'
		// Here lies the not-yet-implemented method 'DrawMap'
		// Here lies the not-yet-implemented method 'AddKeyVehicle'
		// Here lies the not-yet-implemented method 'DrawRotatedTile'
		// Here lies the not-yet-implemented method 'DrawRotatedMaterialTile'
		// Here lies the not-yet-implemented method 'UpdateHUDLocation'
		// Here lies the not-yet-implemented method 'ChangeMapRotation'
		// Here lies the not-yet-implemented method 'DrawMapImage'
		// Here lies the not-yet-implemented method 'GetActorHudLocation'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
