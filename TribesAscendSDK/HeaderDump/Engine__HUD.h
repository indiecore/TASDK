#pragma once
#include "Engine__Actor.h"
#include "Engine__Font.h"
#include "Engine__PlayerController.h"
#include "Engine__Canvas.h"
#include "Engine__Pawn.h"
#include "Core__Object.h"
#include "Engine__PlayerReplicationInfo.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.HUD." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.HUD." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.HUD." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class HUD : public Actor
	{
	public:
		ADD_OBJECT(Canvas, Canvas)
		ADD_VAR(::FloatProperty, RatioY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RatioX, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CenterY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CenterX, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SizeY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SizeX, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RenderDelta, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastHUDRenderTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ConsoleMessagePosY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ConsoleMessagePosX, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Engine.HUD.HudLocalizedMessage' for the property named 'LocalMessages'!
		ADD_VAR(::IntProperty, MaxHUDAreaMessageCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MessageFontOffset, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ConsoleFontSize, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ConsoleMessageCount, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'ConsoleColor'!
		ADD_VAR(::FloatProperty, HudCanvasScale, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bShowOverlays, 0x40)
		ADD_VAR(::BoolProperty, bMessageBeep, 0x20)
		ADD_VAR(::BoolProperty, bShowBadConnectionAlert, 0x10)
		ADD_VAR(::BoolProperty, bShowDebugInfo, 0x8)
		ADD_VAR(::BoolProperty, bShowScores, 0x4)
		ADD_VAR(::BoolProperty, bShowHUD, 0x2)
		ADD_VAR(::BoolProperty, bLostFocusPaused, 0x1)
		ADD_OBJECT(PlayerController, PlayerOwner)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'RedColor'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'GreenColor'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'WhiteColor'!
		bool ShouldDisplayDebug(ScriptName DebugType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.HUD.ShouldDisplayDebug");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = DebugType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		void Draw3DLine(Vector Start, Vector End, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void* LineColor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.HUD.Draw3DLine");
			byte* params = (byte*)malloc(28);
			*(Vector*)params = Start;
			*(Vector*)(params + 12) = End;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void**)(params + 24) = LineColor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Draw2DLine(int X1, int Y1, int X2, int Y2, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void* LineColor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.HUD.Draw2DLine");
			byte* params = (byte*)malloc(20);
			*(int*)params = X1;
			*(int*)(params + 4) = Y1;
			*(int*)(params + 8) = X2;
			*(int*)(params + 12) = Y2;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void**)(params + 16) = LineColor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.HUD.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DrawActorOverlays(Vector ViewPoint, Rotator ViewRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.HUD.DrawActorOverlays");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = ViewPoint;
			*(Rotator*)(params + 12) = ViewRotation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RemovePostRenderedActor(class Actor* A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.HUD.RemovePostRenderedActor");
			byte* params = (byte*)malloc(4);
			*(class Actor**)params = A;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddPostRenderedActor(class Actor* A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.HUD.AddPostRenderedActor");
			byte* params = (byte*)malloc(4);
			*(class Actor**)params = A;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ToggleHUD()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.HUD.ToggleHUD");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowHUD()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.HUD.ShowHUD");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowScores()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.HUD.ShowScores");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetShowScores(bool bNewValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.HUD.SetShowScores");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bNewValue;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ShowDebug(ScriptName DebugType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.HUD.ShowDebug");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = DebugType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ShowDebugInfo(float& out_YL, float& out_YPos)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.HUD.ShowDebugInfo");
			byte* params = (byte*)malloc(8);
			*(float*)params = out_YL;
			*(float*)(params + 4) = out_YPos;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_YL = *(float*)params;
			out_YPos = *(float*)(params + 4);
			free(params);
		}
		void DrawRoute(class Pawn* Target)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.HUD.DrawRoute");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = Target;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PreCalcValues()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.HUD.PreCalcValues");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostRender()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.HUD.PostRender");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DrawHUD()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.HUD.DrawHUD");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisplayBadConnectionAlert()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.HUD.DisplayBadConnectionAlert");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClearMessage(
// WARNING: Unknown structure type 'ScriptStruct Engine.HUD.HudLocalizedMessage'!
void*& M)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.HUD.ClearMessage");
			byte* params = (byte*)malloc(64);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.HUD.HudLocalizedMessage'!
void**)params = M;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			M = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.HUD.HudLocalizedMessage'!
void**)params;
			free(params);
		}
		void Message(class PlayerReplicationInfo* PRI, ScriptArray<wchar_t> msg, ScriptName MsgType, float Lifetime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.HUD.Message");
			byte* params = (byte*)malloc(28);
			*(class PlayerReplicationInfo**)params = PRI;
			*(ScriptArray<wchar_t>*)(params + 4) = msg;
			*(ScriptName*)(params + 16) = MsgType;
			*(float*)(params + 24) = Lifetime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DisplayConsoleMessages()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.HUD.DisplayConsoleMessages");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddConsoleMessage(ScriptArray<wchar_t> M, ScriptClass* InMessageClass, class PlayerReplicationInfo* PRI, float Lifetime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.HUD.AddConsoleMessage");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = M;
			*(ScriptClass**)(params + 12) = InMessageClass;
			*(class PlayerReplicationInfo**)(params + 16) = PRI;
			*(float*)(params + 20) = Lifetime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void LocalizedMessage(ScriptClass* InMessageClass, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI, ScriptArray<wchar_t> CriticalString, int Switch, float Position, float Lifetime, int FontSize, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void* DrawColor, class Object* OptionalObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.HUD.LocalizedMessage");
			byte* params = (byte*)malloc(48);
			*(ScriptClass**)params = InMessageClass;
			*(class PlayerReplicationInfo**)(params + 4) = RelatedPRI;
			*(class PlayerReplicationInfo**)(params + 8) = RelatedPRI;
			*(ScriptArray<wchar_t>*)(params + 12) = CriticalString;
			*(int*)(params + 24) = Switch;
			*(float*)(params + 28) = Position;
			*(float*)(params + 32) = Lifetime;
			*(int*)(params + 36) = FontSize;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void**)(params + 40) = DrawColor;
			*(class Object**)(params + 44) = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddLocalizedMessage(int Index, ScriptClass* InMessageClass, ScriptArray<wchar_t> CriticalString, int Switch, float Position, float Lifetime, int FontSize, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void* DrawColor, int MessageCount, class Object* OptionalObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.HUD.AddLocalizedMessage");
			byte* params = (byte*)malloc(48);
			*(int*)params = Index;
			*(ScriptClass**)(params + 4) = InMessageClass;
			*(ScriptArray<wchar_t>*)(params + 8) = CriticalString;
			*(int*)(params + 20) = Switch;
			*(float*)(params + 24) = Position;
			*(float*)(params + 28) = Lifetime;
			*(int*)(params + 32) = FontSize;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void**)(params + 36) = DrawColor;
			*(int*)(params + 40) = MessageCount;
			*(class Object**)(params + 44) = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void GetScreenCoords(float PosY, float& ScreenX, float& ScreenY, 
// WARNING: Unknown structure type 'ScriptStruct Engine.HUD.HudLocalizedMessage'!
void*& InMessage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.HUD.GetScreenCoords");
			byte* params = (byte*)malloc(76);
			*(float*)params = PosY;
			*(float*)(params + 4) = ScreenX;
			*(float*)(params + 8) = ScreenY;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.HUD.HudLocalizedMessage'!
void**)(params + 12) = InMessage;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			ScreenX = *(float*)(params + 4);
			ScreenY = *(float*)(params + 8);
			InMessage = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.HUD.HudLocalizedMessage'!
void**)(params + 12);
			free(params);
		}
		void DrawMessage(int I, float PosY, float& DX, float& DY)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.HUD.DrawMessage");
			byte* params = (byte*)malloc(16);
			*(int*)params = I;
			*(float*)(params + 4) = PosY;
			*(float*)(params + 8) = DX;
			*(float*)(params + 12) = DY;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			DX = *(float*)(params + 8);
			DY = *(float*)(params + 12);
			free(params);
		}
		void DrawMessageText(
// WARNING: Unknown structure type 'ScriptStruct Engine.HUD.HudLocalizedMessage'!
void* LocalMessage, float ScreenX, float ScreenY)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.HUD.DrawMessageText");
			byte* params = (byte*)malloc(72);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.HUD.HudLocalizedMessage'!
void**)params = LocalMessage;
			*(float*)(params + 64) = ScreenX;
			*(float*)(params + 68) = ScreenY;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DisplayLocalMessages()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.HUD.DisplayLocalMessages");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisplayKismetMessages()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.HUD.DisplayKismetMessages");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DrawText(ScriptArray<wchar_t> Text, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void* Position, class Font* TextFont, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void* FontScale, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void* TextColor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.HUD.DrawText");
			byte* params = (byte*)malloc(36);
			*(ScriptArray<wchar_t>*)params = Text;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void**)(params + 12) = Position;
			*(class Font**)(params + 20) = TextFont;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void**)(params + 24) = FontScale;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void**)(params + 32) = TextColor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class Font* GetFontSizeIndex(int FontSize)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.HUD.GetFontSizeIndex");
			byte* params = (byte*)malloc(8);
			*(int*)params = FontSize;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Font**)(params + 4);
			free(params);
			return returnVal;
		}
		void PlayerOwnerDied()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.HUD.PlayerOwnerDied");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnLostFocusPause(bool bEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.HUD.OnLostFocusPause");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
