#pragma once
#include "Engine.Texture2D.h"
#include "UDKBase.UDKMapInfo.h"
#include "UTGame.UTGameObjective.h"
#include "Engine.Texture.h"
#include "Core.Object.h"
#include "UDKBase.UDKVehicle.h"
#include "Engine.UIRoot.h"
#include "Engine.MaterialInstanceConstant.h"
#include "Engine.Material.h"
#include "Engine.Actor.h"
#include "UTGame.UTMapMusicInfo.h"
#include "Engine.Canvas.h"
#include "UTGame.UTPlayerController.h"
#include "UTGame.UTVehicle.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class UTMapInfo : public UDKMapInfo
	{
	public:
		ADD_OBJECT(Texture, MapTexture, 76)
		ADD_STRUCT(Vector, MapCenter, 84)
		ADD_STRUCT(float, MapExtent, 96)
		ADD_STRUCT(float, MapScale, 216)
		ADD_STRUCT(int, RecommendedPlayersMax, 68)
		ADD_STRUCT(int, RecommendedPlayersMin, 64)
		ADD_STRUCT(ScriptArray<class UTGameObjective*>, Objectives, 112)
		ADD_STRUCT(ScriptArray<class UTGameObjective*>, Sensors, 252)
		ADD_OBJECT(UDKVehicle, KeyVehicles, 244)
		ADD_STRUCT(UIRoot::TextureCoordinates, PlayerIconCoords, 228)
		ADD_OBJECT(MaterialInstanceConstant, GreenIconMaterialInstance, 224)
		ADD_STRUCT(float, ColorPercent, 220)
		ADD_STRUCT(Vector, CenterPos, 204)
		ADD_STRUCT(float, RadarRange, 200)
		ADD_STRUCT(float, RadarWidth, 196)
		ADD_STRUCT(Vector, ActualMapCenter, 184)
		ADD_STRUCT(float, UseableRadius, 180)
		ADD_OBJECT(Material, MapMaterialReference, 176)
		ADD_OBJECT(MaterialInstanceConstant, MapMaterialInstance, 172)
		ADD_STRUCT(int, CurrentMapRotYaw, 168)
		ADD_STRUCT(Vector, MapRotY, 156)
		ADD_STRUCT(Vector, MapRotX, 144)
		ADD_OBJECT(Texture2D, HUDIconsT, 140)
		ADD_OBJECT(Material, HudIcons, 136)
		ADD_OBJECT(Actor, WatchedActor, 132)
		ADD_OBJECT(Actor, CurrentActor, 128)
		ADD_BOOL(bMapUpToDate, 124, 0x1)
		ADD_STRUCT(float, DefaultMapSize, 108)
		ADD_STRUCT(float, RotatingMiniMapRange, 104)
		ADD_STRUCT(int, MapYaw, 100)
		ADD_STRUCT(float, MapTextureYaw, 80)
		ADD_OBJECT(UTMapMusicInfo, MapMusicInfo, 72)
		void VerifyMapExtent()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48361);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FindObjectives()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48365);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RenderLinks(class Canvas* Canvas, class UTPlayerController* PlayerOwner)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48367);
			byte params[8] = { NULL };
			*(class Canvas**)params = Canvas;
			*(class UTPlayerController**)&params[4] = PlayerOwner;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RenderAdditionalInformation(class Canvas* Canvas, class UTPlayerController* PlayerOwner)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48374);
			byte params[8] = { NULL };
			*(class Canvas**)params = Canvas;
			*(class UTPlayerController**)&params[4] = PlayerOwner;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateNodes(class UTPlayerController* PlayerOwner)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48378);
			byte params[4] = { NULL };
			*(class UTPlayerController**)params = PlayerOwner;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawMap(class Canvas* Canvas, class UTPlayerController* PlayerOwner, float XPos, float YPos, float Width, float Height, bool bFullDetail, float AspectRatio)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48381);
			byte params[32] = { NULL };
			*(class Canvas**)params = Canvas;
			*(class UTPlayerController**)&params[4] = PlayerOwner;
			*(float*)&params[8] = XPos;
			*(float*)&params[12] = YPos;
			*(float*)&params[16] = Width;
			*(float*)&params[20] = Height;
			*(bool*)&params[24] = bFullDetail;
			*(float*)&params[28] = AspectRatio;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddKeyVehicle(class UTVehicle* V)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48421);
			byte params[4] = { NULL };
			*(class UTVehicle**)params = V;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawRotatedTile(class Canvas* Canvas, class Texture2D* T, Vector MapLocation, int InYaw, float IconScale, UIRoot::TextureCoordinates TexCoords, Object::LinearColor DrawColor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48424);
			byte params[60] = { NULL };
			*(class Canvas**)params = Canvas;
			*(class Texture2D**)&params[4] = T;
			*(Vector*)&params[8] = MapLocation;
			*(int*)&params[20] = InYaw;
			*(float*)&params[24] = IconScale;
			*(UIRoot::TextureCoordinates*)&params[28] = TexCoords;
			*(Object::LinearColor*)&params[44] = DrawColor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawRotatedMaterialTile(class Canvas* Canvas, class MaterialInstanceConstant* M, Vector MapLocation, int InYaw, float XWidth, float YWidth, float XStart, float YStart, float XLength, float YLength)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48435);
			byte params[48] = { NULL };
			*(class Canvas**)params = Canvas;
			*(class MaterialInstanceConstant**)&params[4] = M;
			*(Vector*)&params[8] = MapLocation;
			*(int*)&params[20] = InYaw;
			*(float*)&params[24] = XWidth;
			*(float*)&params[28] = YWidth;
			*(float*)&params[32] = XStart;
			*(float*)&params[36] = YStart;
			*(float*)&params[40] = XLength;
			*(float*)&params[44] = YLength;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		Vector UpdateHUDLocation(Vector InLocation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48447);
			byte params[24] = { NULL };
			*(Vector*)params = InLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[12];
		}
		void ChangeMapRotation(Rotator NewMapRotation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48453);
			byte params[12] = { NULL };
			*(Rotator*)params = NewMapRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawMapImage(class Canvas* Canvas, float X, float Y, float W, float H, float PlayerYaw, float BkgImgScaling)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48456);
			byte params[28] = { NULL };
			*(class Canvas**)params = Canvas;
			*(float*)&params[4] = X;
			*(float*)&params[8] = Y;
			*(float*)&params[12] = W;
			*(float*)&params[16] = H;
			*(float*)&params[20] = PlayerYaw;
			*(float*)&params[24] = BkgImgScaling;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		Vector GetActorHudLocation(class Actor* CActor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48466);
			byte params[16] = { NULL };
			*(class Actor**)params = CActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[4];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
