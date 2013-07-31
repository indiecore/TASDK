#pragma once
#include "GFxUI.GFxObject.h"
#include "Core.Object.h"
#include "GFxUI.SwfMovie.h"
#include "Engine.Texture.h"
#include "Engine.TextureRenderTarget2D.h"
#include "GFxUI.GFxDataStoreSubscriber.h"
#include "Engine.PlayerController.h"
#include "Engine.LocalPlayer.h"
#include "Engine.GameViewportClient.h"
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
	class GFxMoviePlayer : public Object
	{
	public:
		enum ASType : byte
		{
			AS_Undefined = 0,
			AS_Null = 1,
			AS_Number = 2,
			AS_String = 3,
			AS_Boolean = 4,
			AS_MAX = 5,
		};
		enum GFxAlign : byte
		{
			Align_Center = 0,
			Align_TopCenter = 1,
			Align_BottomCenter = 2,
			Align_CenterLeft = 3,
			Align_CenterRight = 4,
			Align_TopLeft = 5,
			Align_TopRight = 6,
			Align_BottomLeft = 7,
			Align_BottomRight = 8,
			Align_MAX = 9,
		};
		enum GFxScaleMode : byte
		{
			SM_NoScale = 0,
			SM_ShowAll = 1,
			SM_ExactFit = 2,
			SM_NoBorder = 3,
			SM_MAX = 4,
		};
		enum GFxTimingMode : byte
		{
			TM_Game = 0,
			TM_Real = 1,
			TM_MAX = 2,
		};
		enum GFxRenderTextureMode : byte
		{
			RTM_Opaque = 0,
			RTM_Alpha = 1,
			RTM_AlphaComposite = 2,
			RTM_MAX = 3,
		};
		struct GFxWidgetBinding
		{
		public:
			ADD_STRUCT(ScriptName, WidgetName, 0)
			ADD_OBJECT(ScriptClass, WidgetClass, 8)
		};
		struct SoundThemeBinding
		{
		public:
			ADD_STRUCT(ScriptName, ThemeName, 0)
			ADD_OBJECT(UISoundTheme, Theme, 8)
		};
		struct GFxDataStoreBinding
		{
		public:
			ADD_STRUCT(UIRoot::UIDataStoreBinding, DataSource, 0)
			ADD_STRUCT(ScriptString*, VarPath, 48)
			ADD_STRUCT(ScriptString*, ModelId, 60)
			ADD_STRUCT(ScriptString*, ControlId, 72)
			ADD_BOOL(bEditable, 84, 0x1)
			ADD_STRUCT(ScriptArray<ScriptName>, CellTags, 88)
			ADD_STRUCT(ScriptArray<byte>, ModelIdUtf8, 100)
			ADD_STRUCT(ScriptArray<byte>, ControlIdUtf8, 112)
			ADD_STRUCT(ScriptArray<ScriptName>, FullCellTags, 132)
			ADD_STRUCT(Object::Pointer, ModelRef, 144)
			ADD_STRUCT(Object::Pointer, ControlRef, 148)
		};
		struct ExternalTexture
		{
		public:
			ADD_STRUCT(ScriptString*, Resource, 0)
			ADD_OBJECT(Texture, Texture, 12)
		};
		struct ASValue
		{
		public:
			ADD_STRUCT(GFxMoviePlayer::ASType, Type, 0)
			ADD_BOOL(B, 4, 0x1)
			ADD_STRUCT(float, N, 8)
			ADD_STRUCT(ScriptString*, S, 12)
		};
		ADD_STRUCT(int, LocalPlayerOwnerIndex, 208)
		ADD_OBJECT(SwfMovie, MovieInfo, 196)
		ADD_BOOL(bAutoPlay, 200, 0x80)
		ADD_OBJECT(Object, ExternalInterface, 212)
		ADD_BOOL(bPauseGameWhileActive, 200, 0x100)
		ADD_STRUCT(Object::Pointer, pMovie, 60)
		ADD_STRUCT(Object::Pointer, pCaptureKeys, 64)
		ADD_STRUCT(Object::Pointer, pFocusIgnoreKeys, 68)
		ADD_STRUCT(int, NextASUObject, 192)
		ADD_BOOL(bMovieIsOpen, 200, 0x1)
		ADD_BOOL(bDisplayWithHudOff, 200, 0x2)
		ADD_BOOL(bEnableGammaCorrection, 200, 0x4)
		ADD_BOOL(bWidgetsInitializedThisFrame, 200, 0x8)
		ADD_BOOL(bLogUnhandedWidgetInitializations, 200, 0x10)
		ADD_BOOL(bAllowInput, 200, 0x20)
		ADD_BOOL(bAllowFocus, 200, 0x40)
		ADD_BOOL(bCloseOnLevelChange, 200, 0x200)
		ADD_BOOL(bOnlyOwnerFocusable, 200, 0x400)
		ADD_BOOL(bDiscardNonOwnerInput, 200, 0x800)
		ADD_BOOL(bCaptureInput, 200, 0x1000)
		ADD_BOOL(bIgnoreMouseInput, 200, 0x2000)
		ADD_BOOL(bForceSmoothAnimation, 200, 0x4000)
		ADD_OBJECT(TextureRenderTarget2D, RenderTexture, 204)
		ADD_STRUCT(ScriptArray<ScriptName>, CaptureKeys, 216)
		ADD_STRUCT(ScriptArray<ScriptName>, FocusIgnoreKeys, 228)
		ADD_STRUCT(ScriptArray<GFxMoviePlayer::ExternalTexture>, ExternalTextures, 240)
		ADD_STRUCT(ScriptArray<GFxMoviePlayer::SoundThemeBinding>, SoundThemes, 252)
		ADD_STRUCT(GFxMoviePlayer::GFxTimingMode, TimingMode, 264)
		ADD_STRUCT(GFxMoviePlayer::GFxRenderTextureMode, RenderTextureMode, 265)
		ADD_STRUCT(byte, Priority, 266)
		ADD_STRUCT(ScriptArray<GFxMoviePlayer::GFxDataStoreBinding>, DataStoreBindings, 268)
		ADD_OBJECT(GFxDataStoreSubscriber, DataStoreSubscriber, 280)
		ADD_STRUCT(ScriptArray<GFxMoviePlayer::GFxWidgetBinding>, WidgetBindings, 284)
		ADD_STRUCT(ScriptArray<class GFxObject*>, ObjectValues, 356)
		void OnFocusLost(int LocalPlayerIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29656);
			byte params[4] = { NULL };
			*(int*)params = LocalPlayerIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnFocusGained(int LocalPlayerIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29657);
			byte params[4] = { NULL };
			*(int*)params = LocalPlayerIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ConsoleCommand(ScriptString* Command)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29659);
			byte params[12] = { NULL };
			*(ScriptString**)params = Command;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class PlayerController* GetPC()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29661);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class PlayerController**)params;
		}
		class LocalPlayer* GetLP()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29664);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class LocalPlayer**)params;
		}
		void Init(class LocalPlayer* LocPlay)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29667);
			byte params[4] = { NULL };
			*(class LocalPlayer**)params = LocPlay;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetWidgetPathBinding(class GFxObject* WidgetToBind, ScriptName Path)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29671);
			byte params[12] = { NULL };
			*(class GFxObject**)params = WidgetToBind;
			*(ScriptName*)&params[4] = Path;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Advance(float Time)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29675);
			byte params[4] = { NULL };
			*(float*)params = Time;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostWidgetInit()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29676);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool WidgetUnloaded(ScriptName WidgetName, ScriptName WidgetPath, class GFxObject* Widget)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29679);
			byte params[24] = { NULL };
			*(ScriptName*)params = WidgetName;
			*(ScriptName*)&params[8] = WidgetPath;
			*(class GFxObject**)&params[16] = Widget;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[20];
		}
		bool WidgetInitialized(ScriptName WidgetName, ScriptName WidgetPath, class GFxObject* Widget)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29680);
			byte params[24] = { NULL };
			*(ScriptName*)params = WidgetName;
			*(ScriptName*)&params[8] = WidgetPath;
			*(class GFxObject**)&params[16] = Widget;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[20];
		}
		class GFxObject* ActionScriptObject(ScriptString* Path)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29685);
			byte params[16] = { NULL };
			*(ScriptString**)params = Path;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxObject**)&params[12];
		}
		ScriptString* ActionScriptString(ScriptString* Path)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29690);
			byte params[24] = { NULL };
			*(ScriptString**)params = Path;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[12];
		}
		float ActionScriptFloat(ScriptString* Path)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29693);
			byte params[16] = { NULL };
			*(ScriptString**)params = Path;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[12];
		}
		int ActionScriptInt(ScriptString* Path)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29696);
			byte params[16] = { NULL };
			*(ScriptString**)params = Path;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[12];
		}
		void ActionScriptVoid(ScriptString* Path)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29699);
			byte params[12] = { NULL };
			*(ScriptString**)params = Path;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		GFxMoviePlayer::ASValue Invoke(ScriptString* method, ScriptArray<GFxMoviePlayer::ASValue> args)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29702);
			byte params[48] = { NULL };
			*(ScriptString**)params = method;
			*(ScriptArray<GFxMoviePlayer::ASValue>*)&params[12] = args;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(GFxMoviePlayer::ASValue*)&params[24];
		}
		void ActionScriptSetFunction(class GFxObject* Object, ScriptString* Member)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29704);
			byte params[16] = { NULL };
			*(class GFxObject**)params = Object;
			*(ScriptString**)&params[4] = Member;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class GFxObject* CreateArray()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29716);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxObject**)params;
		}
		class GFxObject* CreateObject(ScriptString* ASClass, ScriptClass* Type)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29719);
			byte params[20] = { NULL };
			*(ScriptString**)params = ASClass;
			*(ScriptClass**)&params[12] = Type;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxObject**)&params[16];
		}
		bool SetVariableStringArray(ScriptString* Path, int Index, ScriptArray<ScriptString*> Arg)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29721);
			byte params[32] = { NULL };
			*(ScriptString**)params = Path;
			*(int*)&params[12] = Index;
			*(ScriptArray<ScriptString*>*)&params[16] = Arg;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[28];
		}
		bool SetVariableFloatArray(ScriptString* Path, int Index, ScriptArray<float> Arg)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29725);
			byte params[32] = { NULL };
			*(ScriptString**)params = Path;
			*(int*)&params[12] = Index;
			*(ScriptArray<float>*)&params[16] = Arg;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[28];
		}
		bool SetVariableIntArray(ScriptString* Path, int Index, ScriptArray<int> Arg)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29731);
			byte params[32] = { NULL };
			*(ScriptString**)params = Path;
			*(int*)&params[12] = Index;
			*(ScriptArray<int>*)&params[16] = Arg;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[28];
		}
		bool SetVariableArray(ScriptString* Path, int Index, ScriptArray<GFxMoviePlayer::ASValue> Arg)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29737);
			byte params[32] = { NULL };
			*(ScriptString**)params = Path;
			*(int*)&params[12] = Index;
			*(ScriptArray<GFxMoviePlayer::ASValue>*)&params[16] = Arg;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[28];
		}
		bool GetVariableStringArray(ScriptString* Path, int Index, ScriptArray<ScriptString*>& Arg)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29743);
			byte params[32] = { NULL };
			*(ScriptString**)params = Path;
			*(int*)&params[12] = Index;
			*(ScriptArray<ScriptString*>*)&params[16] = Arg;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Arg = *(ScriptArray<ScriptString*>*)&params[16];
			return *(bool*)&params[28];
		}
		bool GetVariableFloatArray(ScriptString* Path, int Index, ScriptArray<float>& Arg)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29749);
			byte params[32] = { NULL };
			*(ScriptString**)params = Path;
			*(int*)&params[12] = Index;
			*(ScriptArray<float>*)&params[16] = Arg;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Arg = *(ScriptArray<float>*)&params[16];
			return *(bool*)&params[28];
		}
		bool GetVariableIntArray(ScriptString* Path, int Index, ScriptArray<int>& Arg)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29755);
			byte params[32] = { NULL };
			*(ScriptString**)params = Path;
			*(int*)&params[12] = Index;
			*(ScriptArray<int>*)&params[16] = Arg;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Arg = *(ScriptArray<int>*)&params[16];
			return *(bool*)&params[28];
		}
		bool GetVariableArray(ScriptString* Path, int Index, ScriptArray<GFxMoviePlayer::ASValue>& Arg)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29761);
			byte params[32] = { NULL };
			*(ScriptString**)params = Path;
			*(int*)&params[12] = Index;
			*(ScriptArray<GFxMoviePlayer::ASValue>*)&params[16] = Arg;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Arg = *(ScriptArray<GFxMoviePlayer::ASValue>*)&params[16];
			return *(bool*)&params[28];
		}
		void SetVariableObject(ScriptString* Path, class GFxObject* Object)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29767);
			byte params[16] = { NULL };
			*(ScriptString**)params = Path;
			*(class GFxObject**)&params[12] = Object;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetVariableString(ScriptString* Path, ScriptString* S)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29773);
			byte params[24] = { NULL };
			*(ScriptString**)params = Path;
			*(ScriptString**)&params[12] = S;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetVariableNumber(ScriptString* Path, float F)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29776);
			byte params[16] = { NULL };
			*(ScriptString**)params = Path;
			*(float*)&params[12] = F;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetVariableBool(ScriptString* Path, bool B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29779);
			byte params[16] = { NULL };
			*(ScriptString**)params = Path;
			*(bool*)&params[12] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetVariable(ScriptString* Path, GFxMoviePlayer::ASValue Arg)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29782);
			byte params[36] = { NULL };
			*(ScriptString**)params = Path;
			*(GFxMoviePlayer::ASValue*)&params[12] = Arg;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class GFxObject* GetVariableObject(ScriptString* Path, ScriptClass* Type)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29785);
			byte params[20] = { NULL };
			*(ScriptString**)params = Path;
			*(ScriptClass**)&params[12] = Type;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxObject**)&params[16];
		}
		ScriptString* GetVariableString(ScriptString* Path)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29788);
			byte params[24] = { NULL };
			*(ScriptString**)params = Path;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[12];
		}
		float GetVariableNumber(ScriptString* Path)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29792);
			byte params[16] = { NULL };
			*(ScriptString**)params = Path;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[12];
		}
		bool GetVariableBool(ScriptString* Path)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29795);
			byte params[16] = { NULL };
			*(ScriptString**)params = Path;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		GFxMoviePlayer::ASValue GetVariable(ScriptString* Path)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29798);
			byte params[36] = { NULL };
			*(ScriptString**)params = Path;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(GFxMoviePlayer::ASValue*)&params[12];
		}
		bool FilterButtonInput(int ControllerId, ScriptName ButtonName, Object::EInputEvent InputEvent)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29801);
			byte params[17] = { NULL };
			*(int*)params = ControllerId;
			*(ScriptName*)&params[4] = ButtonName;
			*(Object::EInputEvent*)&params[12] = InputEvent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void FlushPlayerInput(bool capturekeysonly)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29804);
			byte params[4] = { NULL };
			*(bool*)params = capturekeysonly;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearFocusIgnoreKeys()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29809);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddFocusIgnoreKey(ScriptName Key)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29811);
			byte params[8] = { NULL };
			*(ScriptName*)params = Key;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearCaptureKeys()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29812);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddCaptureKey(ScriptName Key)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29814);
			byte params[8] = { NULL };
			*(ScriptName*)params = Key;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetMovieCanReceiveInput(bool bCanReceiveInput)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29815);
			byte params[4] = { NULL };
			*(bool*)params = bCanReceiveInput;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetMovieCanReceiveFocus(bool bCanReceiveFocus)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29817);
			byte params[4] = { NULL };
			*(bool*)params = bCanReceiveFocus;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetPerspective3D(Object::Matrix& matPersp)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29819);
			byte params[64] = { NULL };
			*(Object::Matrix*)params = matPersp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			matPersp = *(Object::Matrix*)params;
		}
		void SetView3D(Object::Matrix& matView)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29821);
			byte params[64] = { NULL };
			*(Object::Matrix*)params = matView;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			matView = *(Object::Matrix*)params;
		}
		void GetVisibleFrameRect(float& x0, float& y0, float& X1, float& Y1)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29823);
			byte params[16] = { NULL };
			*(float*)params = x0;
			*(float*)&params[4] = y0;
			*(float*)&params[8] = X1;
			*(float*)&params[12] = Y1;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			x0 = *(float*)params;
			y0 = *(float*)&params[4];
			X1 = *(float*)&params[8];
			Y1 = *(float*)&params[12];
		}
		void SetAlignment(GFxMoviePlayer::GFxAlign A)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29825);
			byte params[1] = { NULL };
			*(GFxMoviePlayer::GFxAlign*)params = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetViewScaleMode(GFxMoviePlayer::GFxScaleMode SM)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29830);
			byte params[1] = { NULL };
			*(GFxMoviePlayer::GFxScaleMode*)params = SM;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetViewport(int X, int Y, int Width, int Height)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29834);
			byte params[16] = { NULL };
			*(int*)params = X;
			*(int*)&params[4] = Y;
			*(int*)&params[8] = Width;
			*(int*)&params[12] = Height;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class GameViewportClient* GetGameViewportClient()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29836);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GameViewportClient**)params;
		}
		void SetPriority(byte NewPriority)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29841);
			byte params[1] = { NULL };
			*params = NewPriority;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PublishDataStoreValues()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29843);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RefreshDataStoreBindings()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29845);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool SetExternalTexture(ScriptString* Resource, class Texture* Texture)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29846);
			byte params[20] = { NULL };
			*(ScriptString**)params = Resource;
			*(class Texture**)&params[12] = Texture;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void SetExternalInterface(class Object* H)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29847);
			byte params[4] = { NULL };
			*(class Object**)params = H;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetForceSmoothAnimation(bool bEnable)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29851);
			byte params[4] = { NULL };
			*(bool*)params = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetTimingMode(GFxMoviePlayer::GFxTimingMode Mode)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29854);
			byte params[1] = { NULL };
			*(GFxMoviePlayer::GFxTimingMode*)params = Mode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetMovieInfo(class SwfMovie* Data)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29856);
			byte params[4] = { NULL };
			*(class SwfMovie**)params = Data;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ConditionalClearPause()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29860);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnClose()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29862);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Close(bool Unload)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29865);
			byte params[4] = { NULL };
			*(bool*)params = Unload;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetPause(bool bPausePlayback)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29866);
			byte params[4] = { NULL };
			*(bool*)params = bPausePlayback;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnPostAdvance(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29868);
			byte params[4] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostAdvance(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29870);
			byte params[4] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool Start(bool StartPaused)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29873);
			byte params[8] = { NULL };
			*(bool*)params = StartPaused;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
