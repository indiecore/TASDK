#pragma once
#include "UDKBase.UDKHUD.h"
#include "UTGame.UTGameReplicationInfo.h"
#include "Core.Object.h"
#include "Engine.PlayerController.h"
#include "Engine.Texture2D.h"
#include "UTGame.UTPlayerController.h"
#include "Engine.UIRoot.h"
#include "UTGame.GFxUI_PauseMenu.h"
#include "Engine.Canvas.h"
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
	class UTHUDBase : public UDKHUD
	{
	public:
		ADD_BOOL(bCrosshairShow, 1444, 0x4)
		ADD_STRUCT(Object::Color, BlackColor, 1492)
		ADD_OBJECT(Texture2D, IconHudTexture, 1468)
		ADD_BOOL(bCrosshairOnFriendly, 1444, 0x8)
		ADD_STRUCT(float, ResolutionScale, 1508)
		ADD_STRUCT(float, LastPickupTime, 1488)
		ADD_STRUCT(float, ConfiguredCrosshairScaling, 1484)
		ADD_BOOL(bGreenCrosshair, 1444, 0x10)
		ADD_STRUCT(Object::Color, LightGreenColor, 1504)
		ADD_BOOL(bIsSplitScreen, 1444, 0x1)
		ADD_STRUCT(int, ViewY, 1520)
		ADD_STRUCT(int, ViewX, 1516)
		ADD_STRUCT(float, ResolutionScaleX, 1512)
		ADD_STRUCT(Object::Color, LightGoldColor, 1500)
		ADD_STRUCT(Object::Color, GoldColor, 1496)
		ADD_STRUCT(ScriptString*, ConsoleIconFontClassName, 1472)
		ADD_STRUCT(float, LastTimeTooltipDrawn, 1464)
		ADD_STRUCT(UIRoot::TextureCoordinates, ToolTipSepCoords, 1448)
		ADD_BOOL(bEnableActorOverlays, 1444, 0x2)
		ADD_OBJECT(UTGameReplicationInfo, UTGRI, 1440)
		ADD_OBJECT(UTPlayerController, UTPlayerOwner, 1436)
		ADD_OBJECT(ScriptClass, MusicManagerClass, 1432)
		ADD_OBJECT(GFxUI_PauseMenu, PauseMenuMovie, 1428)
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45438);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Timer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45441);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowMenu()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45442);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ResolutionChanged()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45443);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisplayHit(Vector HitDir, int Damage, ScriptClass* DamageType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45445);
			byte params[20] = { NULL };
			*(Vector*)params = HitDir;
			*(int*)&params[12] = Damage;
			*(ScriptClass**)&params[16] = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostRender()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45449);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RemoveMovies()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45450);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetVisible(bool bNewVisible)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45451);
			byte params[4] = { NULL };
			*(bool*)params = bNewVisible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CloseOtherMenus()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45453);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TogglePauseMenu()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45454);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CompletePauseMenuClose()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45455);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReleaseShowScores()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45456);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int GetLocalPlayerOwnerIndex()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45457);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		void DrawToolTip(class Canvas* Cvs, class PlayerController* PC, ScriptString* Command, float X, float Y, float U, float V, float UL, float VL, float ResScale, class Texture2D* IconTexture, float Alpha)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45459);
			byte params[56] = { NULL };
			*(class Canvas**)params = Cvs;
			*(class PlayerController**)&params[4] = PC;
			*(ScriptString**)&params[8] = Command;
			*(float*)&params[20] = X;
			*(float*)&params[24] = Y;
			*(float*)&params[28] = U;
			*(float*)&params[32] = V;
			*(float*)&params[36] = UL;
			*(float*)&params[40] = VL;
			*(float*)&params[44] = ResScale;
			*(class Texture2D**)&params[48] = IconTexture;
			*(float*)&params[52] = Alpha;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CheckCrosshairOnFriendly()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45482);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void ClearCrosshairOnFriendly()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45495);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DrawShadowedTile(class Texture2D* Tex, float X, float Y, float XL, float YL, float U, float V, float UL, float VL, Object::Color TileColor, bool bScaleToRes)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45496);
			byte params[44] = { NULL };
			*(class Texture2D**)params = Tex;
			*(float*)&params[4] = X;
			*(float*)&params[8] = Y;
			*(float*)&params[12] = XL;
			*(float*)&params[16] = YL;
			*(float*)&params[20] = U;
			*(float*)&params[24] = V;
			*(float*)&params[28] = UL;
			*(float*)&params[32] = VL;
			*(Object::Color*)&params[36] = TileColor;
			*(bool*)&params[40] = bScaleToRes;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawShadowedStretchedTile(class Texture2D* Tex, float X, float Y, float XL, float YL, float U, float V, float UL, float VL, Object::Color TileColor, bool bScaleToRes)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45509);
			byte params[44] = { NULL };
			*(class Texture2D**)params = Tex;
			*(float*)&params[4] = X;
			*(float*)&params[8] = Y;
			*(float*)&params[12] = XL;
			*(float*)&params[16] = YL;
			*(float*)&params[20] = U;
			*(float*)&params[24] = V;
			*(float*)&params[28] = UL;
			*(float*)&params[32] = VL;
			*(Object::Color*)&params[36] = TileColor;
			*(bool*)&params[40] = bScaleToRes;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawShadowedRotatedTile(class Texture2D* Tex, Rotator Rot, float X, float Y, float XL, float YL, float U, float V, float UL, float VL, Object::Color TileColor, bool bScaleToRes)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45523);
			byte params[56] = { NULL };
			*(class Texture2D**)params = Tex;
			*(Rotator*)&params[4] = Rot;
			*(float*)&params[16] = X;
			*(float*)&params[20] = Y;
			*(float*)&params[24] = XL;
			*(float*)&params[28] = YL;
			*(float*)&params[32] = U;
			*(float*)&params[36] = V;
			*(float*)&params[40] = UL;
			*(float*)&params[44] = VL;
			*(Object::Color*)&params[48] = TileColor;
			*(bool*)&params[52] = bScaleToRes;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
