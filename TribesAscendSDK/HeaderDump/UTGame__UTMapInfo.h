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
		void VerifyMapExtent()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTMapInfo.VerifyMapExtent");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FindObjectives()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTMapInfo.FindObjectives");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RenderLinks(class Canvas* Canvas, class UTPlayerController* PlayerOwner)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTMapInfo.RenderLinks");
			byte* params = (byte*)malloc(8);
			*(class Canvas**)params = Canvas;
			*(class UTPlayerController**)(params + 4) = PlayerOwner;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RenderAdditionalInformation(class Canvas* Canvas, class UTPlayerController* PlayerOwner)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTMapInfo.RenderAdditionalInformation");
			byte* params = (byte*)malloc(8);
			*(class Canvas**)params = Canvas;
			*(class UTPlayerController**)(params + 4) = PlayerOwner;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateNodes(class UTPlayerController* PlayerOwner)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTMapInfo.UpdateNodes");
			byte* params = (byte*)malloc(4);
			*(class UTPlayerController**)params = PlayerOwner;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DrawMap(class Canvas* Canvas, class UTPlayerController* PlayerOwner, float XPos, float YPos, float Width, float Height, bool bFullDetail, float AspectRatio)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTMapInfo.DrawMap");
			byte* params = (byte*)malloc(32);
			*(class Canvas**)params = Canvas;
			*(class UTPlayerController**)(params + 4) = PlayerOwner;
			*(float*)(params + 8) = XPos;
			*(float*)(params + 12) = YPos;
			*(float*)(params + 16) = Width;
			*(float*)(params + 20) = Height;
			*(bool*)(params + 24) = bFullDetail;
			*(float*)(params + 28) = AspectRatio;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddKeyVehicle(class UTVehicle* V)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTMapInfo.AddKeyVehicle");
			byte* params = (byte*)malloc(4);
			*(class UTVehicle**)params = V;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DrawRotatedTile(class Canvas* Canvas, class Texture2D* T, Vector MapLocation, int InYaw, float IconScale, 
// WARNING: Unknown structure type 'ScriptStruct Engine.UIRoot.TextureCoordinates'!
void* TexCoords, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor'!
void* DrawColor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTMapInfo.DrawRotatedTile");
			byte* params = (byte*)malloc(60);
			*(class Canvas**)params = Canvas;
			*(class Texture2D**)(params + 4) = T;
			*(Vector*)(params + 8) = MapLocation;
			*(int*)(params + 20) = InYaw;
			*(float*)(params + 24) = IconScale;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.UIRoot.TextureCoordinates'!
void**)(params + 28) = TexCoords;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor'!
void**)(params + 44) = DrawColor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DrawRotatedMaterialTile(class Canvas* Canvas, class MaterialInstanceConstant* M, Vector MapLocation, int InYaw, float XWidth, float YWidth, float XStart, float YStart, float XLength, float YLength)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTMapInfo.DrawRotatedMaterialTile");
			byte* params = (byte*)malloc(48);
			*(class Canvas**)params = Canvas;
			*(class MaterialInstanceConstant**)(params + 4) = M;
			*(Vector*)(params + 8) = MapLocation;
			*(int*)(params + 20) = InYaw;
			*(float*)(params + 24) = XWidth;
			*(float*)(params + 28) = YWidth;
			*(float*)(params + 32) = XStart;
			*(float*)(params + 36) = YStart;
			*(float*)(params + 40) = XLength;
			*(float*)(params + 44) = YLength;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		Vector UpdateHUDLocation(Vector InLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTMapInfo.UpdateHUDLocation");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = InLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 12);
			free(params);
			return returnVal;
		}
		void ChangeMapRotation(Rotator NewMapRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTMapInfo.ChangeMapRotation");
			byte* params = (byte*)malloc(12);
			*(Rotator*)params = NewMapRotation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DrawMapImage(class Canvas* Canvas, float X, float Y, float W, float H, float PlayerYaw, float BkgImgScaling)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTMapInfo.DrawMapImage");
			byte* params = (byte*)malloc(28);
			*(class Canvas**)params = Canvas;
			*(float*)(params + 4) = X;
			*(float*)(params + 8) = Y;
			*(float*)(params + 12) = W;
			*(float*)(params + 16) = H;
			*(float*)(params + 20) = PlayerYaw;
			*(float*)(params + 24) = BkgImgScaling;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		Vector GetActorHudLocation(class Actor* CActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTMapInfo.GetActorHudLocation");
			byte* params = (byte*)malloc(16);
			*(class Actor**)params = CActor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 4);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
