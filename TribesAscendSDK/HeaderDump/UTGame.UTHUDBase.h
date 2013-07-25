#pragma once
#include "UDKBase.UDKHUD.h"
#include "Engine.PlayerController.h"
#include "Engine.Texture2D.h"
#include "UTGame.UTGameReplicationInfo.h"
#include "UTGame.UTPlayerController.h"
#include "UTGame.GFxUI_PauseMenu.h"
#include "Engine.Canvas.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTHUDBase." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UTGame.UTHUDBase." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTHUDBase." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTHUDBase : public UDKHUD
	{
	public:
		ADD_VAR(::BoolProperty, bCrosshairShow, 0x4)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'BlackColor'!
		ADD_OBJECT(Texture2D, IconHudTexture)
		ADD_VAR(::BoolProperty, bCrosshairOnFriendly, 0x8)
		ADD_VAR(::FloatProperty, ResolutionScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastPickupTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ConfiguredCrosshairScaling, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bGreenCrosshair, 0x10)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'LightGreenColor'!
		ADD_VAR(::BoolProperty, bIsSplitScreen, 0x1)
		ADD_VAR(::IntProperty, ViewY, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ViewX, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ResolutionScaleX, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'LightGoldColor'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'GoldColor'!
		ADD_VAR(::StrProperty, ConsoleIconFontClassName, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastTimeTooltipDrawn, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Engine.UIRoot.TextureCoordinates' for the property named 'ToolTipSepCoords'!
		ADD_VAR(::BoolProperty, bEnableActorOverlays, 0x2)
		ADD_OBJECT(UTGameReplicationInfo, UTGRI)
		ADD_OBJECT(UTPlayerController, UTPlayerOwner)
		ADD_OBJECT(ScriptClass, MusicManagerClass)
		ADD_OBJECT(GFxUI_PauseMenu, PauseMenuMovie)
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUDBase.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Timer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUDBase.Timer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowMenu()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUDBase.ShowMenu");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ResolutionChanged()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUDBase.ResolutionChanged");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisplayHit(Vector HitDir, int Damage, ScriptClass* DamageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUDBase.DisplayHit");
			byte* params = (byte*)malloc(20);
			*(Vector*)params = HitDir;
			*(int*)(params + 12) = Damage;
			*(ScriptClass**)(params + 16) = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PostRender()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUDBase.PostRender");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RemoveMovies()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUDBase.RemoveMovies");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetVisible(bool bNewVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUDBase.SetVisible");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bNewVisible;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CloseOtherMenus()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUDBase.CloseOtherMenus");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TogglePauseMenu()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUDBase.TogglePauseMenu");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CompletePauseMenuClose()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUDBase.CompletePauseMenuClose");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReleaseShowScores()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUDBase.ReleaseShowScores");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int GetLocalPlayerOwnerIndex()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUDBase.GetLocalPlayerOwnerIndex");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		void DrawToolTip(class Canvas* Cvs, class PlayerController* PC, ScriptArray<wchar_t> Command, float X, float Y, float U, float V, float UL, float VL, float ResScale, class Texture2D* IconTexture, float Alpha)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUDBase.DrawToolTip");
			byte* params = (byte*)malloc(56);
			*(class Canvas**)params = Cvs;
			*(class PlayerController**)(params + 4) = PC;
			*(ScriptArray<wchar_t>*)(params + 8) = Command;
			*(float*)(params + 20) = X;
			*(float*)(params + 24) = Y;
			*(float*)(params + 28) = U;
			*(float*)(params + 32) = V;
			*(float*)(params + 36) = UL;
			*(float*)(params + 40) = VL;
			*(float*)(params + 44) = ResScale;
			*(class Texture2D**)(params + 48) = IconTexture;
			*(float*)(params + 52) = Alpha;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool CheckCrosshairOnFriendly()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUDBase.CheckCrosshairOnFriendly");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void ClearCrosshairOnFriendly()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUDBase.ClearCrosshairOnFriendly");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DrawShadowedTile(class Texture2D* Tex, float X, float Y, float XL, float YL, float U, float V, float UL, float VL, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void* TileColor, bool bScaleToRes)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUDBase.DrawShadowedTile");
			byte* params = (byte*)malloc(44);
			*(class Texture2D**)params = Tex;
			*(float*)(params + 4) = X;
			*(float*)(params + 8) = Y;
			*(float*)(params + 12) = XL;
			*(float*)(params + 16) = YL;
			*(float*)(params + 20) = U;
			*(float*)(params + 24) = V;
			*(float*)(params + 28) = UL;
			*(float*)(params + 32) = VL;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void**)(params + 36) = TileColor;
			*(bool*)(params + 40) = bScaleToRes;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DrawShadowedStretchedTile(class Texture2D* Tex, float X, float Y, float XL, float YL, float U, float V, float UL, float VL, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void* TileColor, bool bScaleToRes)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUDBase.DrawShadowedStretchedTile");
			byte* params = (byte*)malloc(44);
			*(class Texture2D**)params = Tex;
			*(float*)(params + 4) = X;
			*(float*)(params + 8) = Y;
			*(float*)(params + 12) = XL;
			*(float*)(params + 16) = YL;
			*(float*)(params + 20) = U;
			*(float*)(params + 24) = V;
			*(float*)(params + 28) = UL;
			*(float*)(params + 32) = VL;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void**)(params + 36) = TileColor;
			*(bool*)(params + 40) = bScaleToRes;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DrawShadowedRotatedTile(class Texture2D* Tex, Rotator Rot, float X, float Y, float XL, float YL, float U, float V, float UL, float VL, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void* TileColor, bool bScaleToRes)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTHUDBase.DrawShadowedRotatedTile");
			byte* params = (byte*)malloc(56);
			*(class Texture2D**)params = Tex;
			*(Rotator*)(params + 4) = Rot;
			*(float*)(params + 16) = X;
			*(float*)(params + 20) = Y;
			*(float*)(params + 24) = XL;
			*(float*)(params + 28) = YL;
			*(float*)(params + 32) = U;
			*(float*)(params + 36) = V;
			*(float*)(params + 40) = UL;
			*(float*)(params + 44) = VL;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void**)(params + 48) = TileColor;
			*(bool*)(params + 52) = bScaleToRes;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
