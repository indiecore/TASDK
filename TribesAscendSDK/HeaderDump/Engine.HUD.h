#pragma once
#include "Core.Object.h"
#include "Engine.Actor.h"
#include "Engine.Canvas.h"
#include "Engine.Font.h"
#include "Engine.Pawn.h"
#include "Engine.PlayerController.h"
#include "Engine.PlayerReplicationInfo.h"
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
	class HUD : public Actor
	{
	public:
		struct KismetDrawTextInfo
		{
		public:
			ADD_STRUCT(Object::Vector2D, MessageOffset, 36)
			ADD_STRUCT(float, MessageEndTime, 48)
			ADD_STRUCT(Object::Color, MessageColor, 44)
			ADD_STRUCT(Object::Vector2D, MessageFontScale, 28)
			ADD_OBJECT(Font, MessageFont, 24)
			ADD_STRUCT(ScriptString*, AppendedText, 12)
			ADD_STRUCT(ScriptString*, MessageText, 0)
		};
		struct ConsoleMessage
		{
		public:
			ADD_OBJECT(PlayerReplicationInfo, PRI, 20)
			ADD_STRUCT(float, MessageLife, 16)
			ADD_STRUCT(Object::Color, TextColor, 12)
			ADD_STRUCT(ScriptString*, Text, 0)
		};
		struct HudLocalizedMessage
		{
		public:
			ADD_OBJECT(Object, OptionalObject, 60)
			ADD_STRUCT(int, Count, 56)
			ADD_BOOL(Drawn, 52, 0x1)
			ADD_STRUCT(float, DY, 48)
			ADD_STRUCT(float, DX, 44)
			ADD_OBJECT(Font, StringFont, 40)
			ADD_STRUCT(int, FontSize, 36)
			ADD_STRUCT(Object::Color, DrawColor, 32)
			ADD_STRUCT(float, PosY, 28)
			ADD_STRUCT(float, Lifetime, 24)
			ADD_STRUCT(float, EndOfLife, 20)
			ADD_STRUCT(int, Switch, 16)
			ADD_STRUCT(ScriptString*, StringMessage, 4)
			ADD_OBJECT(ScriptClass, Message, 0)
		};
		ADD_OBJECT(Canvas, Canvas, 1064)
		ADD_STRUCT(ScriptArray<class Actor*>, PostRenderedActors, 500)
		ADD_STRUCT(ScriptArray<HUD::ConsoleMessage>, ConsoleMessages, 512)
		ADD_STRUCT(ScriptArray<ScriptName>, DebugDisplay, 1100)
		ADD_STRUCT(ScriptArray<HUD::KismetDrawTextInfo>, KismetTextInfo, 1112)
		ADD_STRUCT(float, RatioY, 1096)
		ADD_STRUCT(float, RatioX, 1092)
		ADD_STRUCT(float, CenterY, 1088)
		ADD_STRUCT(float, CenterX, 1084)
		ADD_STRUCT(float, SizeY, 1080)
		ADD_STRUCT(float, SizeX, 1076)
		ADD_STRUCT(float, RenderDelta, 1072)
		ADD_STRUCT(float, LastHUDRenderTime, 1068)
		ADD_STRUCT(float, ConsoleMessagePosY, 1060)
		ADD_STRUCT(float, ConsoleMessagePosX, 1056)
		ADD_STRUCT(HUD::HudLocalizedMessage, LocalMessages, 544)
		ADD_STRUCT(int, MaxHUDAreaMessageCount, 540)
		ADD_STRUCT(int, MessageFontOffset, 536)
		ADD_STRUCT(int, ConsoleFontSize, 532)
		ADD_STRUCT(int, ConsoleMessageCount, 528)
		ADD_STRUCT(Object::Color, ConsoleColor, 524)
		ADD_STRUCT(float, HudCanvasScale, 496)
		ADD_BOOL(bShowOverlays, 492, 0x40)
		ADD_BOOL(bMessageBeep, 492, 0x20)
		ADD_BOOL(bShowBadConnectionAlert, 492, 0x10)
		ADD_BOOL(bShowDebugInfo, 492, 0x8)
		ADD_BOOL(bShowScores, 492, 0x4)
		ADD_BOOL(bShowHUD, 492, 0x2)
		ADD_BOOL(bLostFocusPaused, 492, 0x1)
		ADD_OBJECT(PlayerController, PlayerOwner, 488)
		ADD_STRUCT(Object::Color, RedColor, 484)
		ADD_STRUCT(Object::Color, GreenColor, 480)
		ADD_STRUCT(Object::Color, WhiteColor, 476)
		bool ShouldDisplayDebug(ScriptName DebugType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4184);
			byte params[12] = { NULL };
			*(ScriptName*)params = DebugType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void Draw3DLine(Vector Start, Vector End, Object::Color LineColor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13718);
			byte params[28] = { NULL };
			*(Vector*)params = Start;
			*(Vector*)&params[12] = End;
			*(Object::Color*)&params[24] = LineColor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Draw2DLine(int X1, int Y1, int X2, int Y2, Object::Color LineColor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13722);
			byte params[20] = { NULL };
			*(int*)params = X1;
			*(int*)&params[4] = Y1;
			*(int*)&params[8] = X2;
			*(int*)&params[12] = Y2;
			*(Object::Color*)&params[16] = LineColor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13728);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DrawActorOverlays(Vector ViewPoint, Rotator ViewRotation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13729);
			byte params[24] = { NULL };
			*(Vector*)params = ViewPoint;
			*(Rotator*)&params[12] = ViewRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RemovePostRenderedActor(class Actor* A)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13732);
			byte params[4] = { NULL };
			*(class Actor**)params = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddPostRenderedActor(class Actor* A)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13735);
			byte params[4] = { NULL };
			*(class Actor**)params = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ToggleHUD()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13738);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowHUD()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13739);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowScores()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13740);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetShowScores(bool bNewValue)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13741);
			byte params[4] = { NULL };
			*(bool*)params = bNewValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ShowDebug(ScriptName DebugType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13743);
			byte params[8] = { NULL };
			*(ScriptName*)params = DebugType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ShowDebugInfo(float& out_YL, float& out_YPos)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13748);
			byte params[8] = { NULL };
			*(float*)params = out_YL;
			*(float*)&params[4] = out_YPos;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_YL = *(float*)params;
			out_YPos = *(float*)&params[4];
		}
		void DrawRoute(class Pawn* Target)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13751);
			byte params[4] = { NULL };
			*(class Pawn**)params = Target;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PreCalcValues()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13760);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostRender()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13761);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DrawHUD()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13767);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisplayBadConnectionAlert()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13770);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClearMessage(HUD::HudLocalizedMessage& M)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13771);
			byte params[64] = { NULL };
			*(HUD::HudLocalizedMessage*)params = M;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			M = *(HUD::HudLocalizedMessage*)params;
		}
		void Message(class PlayerReplicationInfo* PRI, ScriptString* msg, ScriptName MsgType, float Lifetime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13773);
			byte params[28] = { NULL };
			*(class PlayerReplicationInfo**)params = PRI;
			*(ScriptString**)&params[4] = msg;
			*(ScriptName*)&params[16] = MsgType;
			*(float*)&params[24] = Lifetime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DisplayConsoleMessages()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13778);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddConsoleMessage(ScriptString* M, ScriptClass* InMessageClass, class PlayerReplicationInfo* PRI, float Lifetime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13784);
			byte params[24] = { NULL };
			*(ScriptString**)params = M;
			*(ScriptClass**)&params[12] = InMessageClass;
			*(class PlayerReplicationInfo**)&params[16] = PRI;
			*(float*)&params[20] = Lifetime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LocalizedMessage(ScriptClass* InMessageClass, class PlayerReplicationInfo* RelatedPRI_1, class PlayerReplicationInfo* RelatedPRI_2, ScriptString* CriticalString, int Switch, float Position, float Lifetime, int FontSize, Object::Color DrawColor, class Object* OptionalObject)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13795);
			byte params[48] = { NULL };
			*(ScriptClass**)params = InMessageClass;
			*(class PlayerReplicationInfo**)&params[4] = RelatedPRI_1;
			*(class PlayerReplicationInfo**)&params[8] = RelatedPRI_2;
			*(ScriptString**)&params[12] = CriticalString;
			*(int*)&params[24] = Switch;
			*(float*)&params[28] = Position;
			*(float*)&params[32] = Lifetime;
			*(int*)&params[36] = FontSize;
			*(Object::Color*)&params[40] = DrawColor;
			*(class Object**)&params[44] = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddLocalizedMessage(int Index, ScriptClass* InMessageClass, ScriptString* CriticalString, int Switch, float Position, float Lifetime, int FontSize, Object::Color DrawColor, int MessageCount, class Object* OptionalObject)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13815);
			byte params[48] = { NULL };
			*(int*)params = Index;
			*(ScriptClass**)&params[4] = InMessageClass;
			*(ScriptString**)&params[8] = CriticalString;
			*(int*)&params[20] = Switch;
			*(float*)&params[24] = Position;
			*(float*)&params[28] = Lifetime;
			*(int*)&params[32] = FontSize;
			*(Object::Color*)&params[36] = DrawColor;
			*(int*)&params[40] = MessageCount;
			*(class Object**)&params[44] = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GetScreenCoords(float PosY, float& ScreenX, float& ScreenY, HUD::HudLocalizedMessage& InMessage)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13826);
			byte params[76] = { NULL };
			*(float*)params = PosY;
			*(float*)&params[4] = ScreenX;
			*(float*)&params[8] = ScreenY;
			*(HUD::HudLocalizedMessage*)&params[12] = InMessage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ScreenX = *(float*)&params[4];
			ScreenY = *(float*)&params[8];
			InMessage = *(HUD::HudLocalizedMessage*)&params[12];
		}
		void DrawMessage(int I, float PosY, float& DX, float& DY)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13831);
			byte params[16] = { NULL };
			*(int*)params = I;
			*(float*)&params[4] = PosY;
			*(float*)&params[8] = DX;
			*(float*)&params[12] = DY;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			DX = *(float*)&params[8];
			DY = *(float*)&params[12];
		}
		void DrawMessageText(HUD::HudLocalizedMessage LocalMessage, float ScreenX, float ScreenY)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13839);
			byte params[72] = { NULL };
			*(HUD::HudLocalizedMessage*)params = LocalMessage;
			*(float*)&params[64] = ScreenX;
			*(float*)&params[68] = ScreenY;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DisplayLocalMessages()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13844);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisplayKismetMessages()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13854);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DrawText(ScriptString* Text, Object::Vector2D Position, class Font* TextFont, Object::Vector2D FontScale, Object::Color TextColor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13856);
			byte params[36] = { NULL };
			*(ScriptString**)params = Text;
			*(Object::Vector2D*)&params[12] = Position;
			*(class Font**)&params[20] = TextFont;
			*(Object::Vector2D*)&params[24] = FontScale;
			*(Object::Color*)&params[32] = TextColor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class Font* GetFontSizeIndex(int FontSize)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13864);
			byte params[8] = { NULL };
			*(int*)params = FontSize;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Font**)&params[4];
		}
		void PlayerOwnerDied()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13871);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnLostFocusPause(bool bEnable)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13872);
			byte params[4] = { NULL };
			*(bool*)params = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
