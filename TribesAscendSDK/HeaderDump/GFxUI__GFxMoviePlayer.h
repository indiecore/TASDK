#pragma once
#include "Engine__TextureRenderTarget2D.h"
#include "GFxUI__SwfMovie.h"
#include "Core__Object.h"
#include "GFxUI__GFxDataStoreSubscriber.h"
#include "Engine__Texture.h"
#include "Engine__PlayerController.h"
#include "Engine__LocalPlayer.h"
#include "Engine__GameViewportClient.h"
#include "GFxUI__GFxObject.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GFxUI.GFxMoviePlayer." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty GFxUI.GFxMoviePlayer." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty GFxUI.GFxMoviePlayer." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GFxMoviePlayer : public Object
	{
	public:
		ADD_VAR(::IntProperty, LocalPlayerOwnerIndex, 0xFFFFFFFF)
		ADD_OBJECT(SwfMovie, MovieInfo)
		ADD_VAR(::BoolProperty, bAutoPlay, 0x80)
		ADD_OBJECT(Object, ExternalInterface)
		ADD_VAR(::BoolProperty, bPauseGameWhileActive, 0x100)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'pMovie'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'pCaptureKeys'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'pFocusIgnoreKeys'!
		ADD_VAR(::IntProperty, NextASUObject, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bMovieIsOpen, 0x1)
		ADD_VAR(::BoolProperty, bDisplayWithHudOff, 0x2)
		ADD_VAR(::BoolProperty, bEnableGammaCorrection, 0x4)
		ADD_VAR(::BoolProperty, bWidgetsInitializedThisFrame, 0x8)
		ADD_VAR(::BoolProperty, bLogUnhandedWidgetInitializations, 0x10)
		ADD_VAR(::BoolProperty, bAllowInput, 0x20)
		ADD_VAR(::BoolProperty, bAllowFocus, 0x40)
		ADD_VAR(::BoolProperty, bCloseOnLevelChange, 0x200)
		ADD_VAR(::BoolProperty, bOnlyOwnerFocusable, 0x400)
		ADD_VAR(::BoolProperty, bDiscardNonOwnerInput, 0x800)
		ADD_VAR(::BoolProperty, bCaptureInput, 0x1000)
		ADD_VAR(::BoolProperty, bIgnoreMouseInput, 0x2000)
		ADD_VAR(::BoolProperty, bForceSmoothAnimation, 0x4000)
		ADD_OBJECT(TextureRenderTarget2D, RenderTexture)
		ADD_VAR(::ByteProperty, TimingMode, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, RenderTextureMode, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, Priority, 0xFFFFFFFF)
		ADD_OBJECT(GFxDataStoreSubscriber, DataStoreSubscriber)
		void OnFocusLost(int LocalPlayerIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxMoviePlayer.OnFocusLost");
			byte* params = (byte*)malloc(4);
			*(int*)params = LocalPlayerIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnFocusGained(int LocalPlayerIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxMoviePlayer.OnFocusGained");
			byte* params = (byte*)malloc(4);
			*(int*)params = LocalPlayerIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ConsoleCommand(ScriptArray<wchar_t> Command)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxMoviePlayer.ConsoleCommand");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Command;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class PlayerController* GetPC()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxMoviePlayer.GetPC");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class PlayerController**)params;
			free(params);
			return returnVal;
		}
		class LocalPlayer* GetLP()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxMoviePlayer.GetLP");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class LocalPlayer**)params;
			free(params);
			return returnVal;
		}
		void Init(class LocalPlayer* LocPlay)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxMoviePlayer.Init");
			byte* params = (byte*)malloc(4);
			*(class LocalPlayer**)params = LocPlay;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetWidgetPathBinding(class GFxObject* WidgetToBind, ScriptName Path)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxMoviePlayer.SetWidgetPathBinding");
			byte* params = (byte*)malloc(12);
			*(class GFxObject**)params = WidgetToBind;
			*(ScriptName*)(params + 4) = Path;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Advance(float Time)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxMoviePlayer.Advance");
			byte* params = (byte*)malloc(4);
			*(float*)params = Time;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PostWidgetInit()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxMoviePlayer.PostWidgetInit");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool WidgetUnloaded(ScriptName WidgetName, ScriptName WidgetPath, class GFxObject* Widget)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxMoviePlayer.WidgetUnloaded");
			byte* params = (byte*)malloc(24);
			*(ScriptName*)params = WidgetName;
			*(ScriptName*)(params + 8) = WidgetPath;
			*(class GFxObject**)(params + 16) = Widget;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 20);
			free(params);
			return returnVal;
		}
		bool WidgetInitialized(ScriptName WidgetName, ScriptName WidgetPath, class GFxObject* Widget)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxMoviePlayer.WidgetInitialized");
			byte* params = (byte*)malloc(24);
			*(ScriptName*)params = WidgetName;
			*(ScriptName*)(params + 8) = WidgetPath;
			*(class GFxObject**)(params + 16) = Widget;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 20);
			free(params);
			return returnVal;
		}
		class GFxObject* ActionScriptObject(ScriptArray<wchar_t> Path)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxMoviePlayer.ActionScriptObject");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = Path;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class GFxObject**)(params + 12);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> ActionScriptString(ScriptArray<wchar_t> Path)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxMoviePlayer.ActionScriptString");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = Path;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 12);
			free(params);
			return returnVal;
		}
		float ActionScriptFloat(ScriptArray<wchar_t> Path)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxMoviePlayer.ActionScriptFloat");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = Path;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 12);
			free(params);
			return returnVal;
		}
		int ActionScriptInt(ScriptArray<wchar_t> Path)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxMoviePlayer.ActionScriptInt");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = Path;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 12);
			free(params);
			return returnVal;
		}
		void ActionScriptVoid(ScriptArray<wchar_t> Path)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxMoviePlayer.ActionScriptVoid");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Path;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		
// WARNING: Unknown structure type 'ScriptStruct GFxUI.GFxMoviePlayer.ASValue'!
void* Invoke(ScriptArray<wchar_t> method, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void* args)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxMoviePlayer.Invoke");
			byte* params = (byte*)malloc(48);
			*(ScriptArray<wchar_t>*)params = method;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 12) = args;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// WARNING: Unknown structure type 'ScriptStruct GFxUI.GFxMoviePlayer.ASValue'!
void**)(params + 24);
			free(params);
			return returnVal;
		}
		void ActionScriptSetFunction(class GFxObject* Object, ScriptArray<wchar_t> Member)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxMoviePlayer.ActionScriptSetFunction");
			byte* params = (byte*)malloc(16);
			*(class GFxObject**)params = Object;
			*(ScriptArray<wchar_t>*)(params + 4) = Member;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class GFxObject* CreateArray()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxMoviePlayer.CreateArray");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class GFxObject**)params;
			free(params);
			return returnVal;
		}
		class GFxObject* CreateObject(ScriptArray<wchar_t> ASClass, ScriptClass* Type)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxMoviePlayer.CreateObject");
			byte* params = (byte*)malloc(20);
			*(ScriptArray<wchar_t>*)params = ASClass;
			*(ScriptClass**)(params + 12) = Type;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class GFxObject**)(params + 16);
			free(params);
			return returnVal;
		}
		bool SetVariableStringArray(ScriptArray<wchar_t> Path, int Index, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void* Arg)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxMoviePlayer.SetVariableStringArray");
			byte* params = (byte*)malloc(32);
			*(ScriptArray<wchar_t>*)params = Path;
			*(int*)(params + 12) = Index;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 16) = Arg;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 28);
			free(params);
			return returnVal;
		}
		bool SetVariableFloatArray(ScriptArray<wchar_t> Path, int Index, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void* Arg)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxMoviePlayer.SetVariableFloatArray");
			byte* params = (byte*)malloc(32);
			*(ScriptArray<wchar_t>*)params = Path;
			*(int*)(params + 12) = Index;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 16) = Arg;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 28);
			free(params);
			return returnVal;
		}
		bool SetVariableIntArray(ScriptArray<wchar_t> Path, int Index, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void* Arg)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxMoviePlayer.SetVariableIntArray");
			byte* params = (byte*)malloc(32);
			*(ScriptArray<wchar_t>*)params = Path;
			*(int*)(params + 12) = Index;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 16) = Arg;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 28);
			free(params);
			return returnVal;
		}
		bool SetVariableArray(ScriptArray<wchar_t> Path, int Index, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void* Arg)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxMoviePlayer.SetVariableArray");
			byte* params = (byte*)malloc(32);
			*(ScriptArray<wchar_t>*)params = Path;
			*(int*)(params + 12) = Index;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 16) = Arg;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 28);
			free(params);
			return returnVal;
		}
		bool GetVariableStringArray(ScriptArray<wchar_t> Path, int Index, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& Arg)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxMoviePlayer.GetVariableStringArray");
			byte* params = (byte*)malloc(32);
			*(ScriptArray<wchar_t>*)params = Path;
			*(int*)(params + 12) = Index;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 16) = Arg;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Arg = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 16);
			auto returnVal = *(bool*)(params + 28);
			free(params);
			return returnVal;
		}
		bool GetVariableFloatArray(ScriptArray<wchar_t> Path, int Index, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& Arg)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxMoviePlayer.GetVariableFloatArray");
			byte* params = (byte*)malloc(32);
			*(ScriptArray<wchar_t>*)params = Path;
			*(int*)(params + 12) = Index;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 16) = Arg;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Arg = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 16);
			auto returnVal = *(bool*)(params + 28);
			free(params);
			return returnVal;
		}
		bool GetVariableIntArray(ScriptArray<wchar_t> Path, int Index, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& Arg)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxMoviePlayer.GetVariableIntArray");
			byte* params = (byte*)malloc(32);
			*(ScriptArray<wchar_t>*)params = Path;
			*(int*)(params + 12) = Index;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 16) = Arg;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Arg = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 16);
			auto returnVal = *(bool*)(params + 28);
			free(params);
			return returnVal;
		}
		bool GetVariableArray(ScriptArray<wchar_t> Path, int Index, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& Arg)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxMoviePlayer.GetVariableArray");
			byte* params = (byte*)malloc(32);
			*(ScriptArray<wchar_t>*)params = Path;
			*(int*)(params + 12) = Index;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 16) = Arg;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Arg = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 16);
			auto returnVal = *(bool*)(params + 28);
			free(params);
			return returnVal;
		}
		void SetVariableObject(ScriptArray<wchar_t> Path, class GFxObject* Object)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxMoviePlayer.SetVariableObject");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = Path;
			*(class GFxObject**)(params + 12) = Object;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetVariableString(ScriptArray<wchar_t> Path, ScriptArray<wchar_t> S)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxMoviePlayer.SetVariableString");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = Path;
			*(ScriptArray<wchar_t>*)(params + 12) = S;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetVariableNumber(ScriptArray<wchar_t> Path, float F)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxMoviePlayer.SetVariableNumber");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = Path;
			*(float*)(params + 12) = F;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetVariableBool(ScriptArray<wchar_t> Path, bool B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxMoviePlayer.SetVariableBool");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = Path;
			*(bool*)(params + 12) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetVariable(ScriptArray<wchar_t> Path, 
// WARNING: Unknown structure type 'ScriptStruct GFxUI.GFxMoviePlayer.ASValue'!
void* Arg)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxMoviePlayer.SetVariable");
			byte* params = (byte*)malloc(36);
			*(ScriptArray<wchar_t>*)params = Path;
			*(
// WARNING: Unknown structure type 'ScriptStruct GFxUI.GFxMoviePlayer.ASValue'!
void**)(params + 12) = Arg;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class GFxObject* GetVariableObject(ScriptArray<wchar_t> Path, ScriptClass* Type)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxMoviePlayer.GetVariableObject");
			byte* params = (byte*)malloc(20);
			*(ScriptArray<wchar_t>*)params = Path;
			*(ScriptClass**)(params + 12) = Type;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class GFxObject**)(params + 16);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetVariableString(ScriptArray<wchar_t> Path)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxMoviePlayer.GetVariableString");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = Path;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 12);
			free(params);
			return returnVal;
		}
		float GetVariableNumber(ScriptArray<wchar_t> Path)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxMoviePlayer.GetVariableNumber");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = Path;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 12);
			free(params);
			return returnVal;
		}
		bool GetVariableBool(ScriptArray<wchar_t> Path)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxMoviePlayer.GetVariableBool");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = Path;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		
// WARNING: Unknown structure type 'ScriptStruct GFxUI.GFxMoviePlayer.ASValue'!
void* GetVariable(ScriptArray<wchar_t> Path)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxMoviePlayer.GetVariable");
			byte* params = (byte*)malloc(36);
			*(ScriptArray<wchar_t>*)params = Path;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// WARNING: Unknown structure type 'ScriptStruct GFxUI.GFxMoviePlayer.ASValue'!
void**)(params + 12);
			free(params);
			return returnVal;
		}
		bool FilterButtonInput(int ControllerId, ScriptName ButtonName, byte InputEvent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxMoviePlayer.FilterButtonInput");
			byte* params = (byte*)malloc(17);
			*(int*)params = ControllerId;
			*(ScriptName*)(params + 4) = ButtonName;
			*(params + 12) = InputEvent;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		void FlushPlayerInput(bool capturekeysonly)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxMoviePlayer.FlushPlayerInput");
			byte* params = (byte*)malloc(4);
			*(bool*)params = capturekeysonly;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearFocusIgnoreKeys()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxMoviePlayer.ClearFocusIgnoreKeys");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddFocusIgnoreKey(ScriptName Key)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxMoviePlayer.AddFocusIgnoreKey");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = Key;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearCaptureKeys()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxMoviePlayer.ClearCaptureKeys");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddCaptureKey(ScriptName Key)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxMoviePlayer.AddCaptureKey");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = Key;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetMovieCanReceiveInput(bool bCanReceiveInput)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxMoviePlayer.SetMovieCanReceiveInput");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bCanReceiveInput;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetMovieCanReceiveFocus(bool bCanReceiveFocus)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxMoviePlayer.SetMovieCanReceiveFocus");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bCanReceiveFocus;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetPerspective3D(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix'!
void*& matPersp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxMoviePlayer.SetPerspective3D");
			byte* params = (byte*)malloc(64);
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix'!
void**)params = matPersp;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			matPersp = *(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix'!
void**)params;
			free(params);
		}
		void SetView3D(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix'!
void*& matView)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxMoviePlayer.SetView3D");
			byte* params = (byte*)malloc(64);
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix'!
void**)params = matView;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			matView = *(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix'!
void**)params;
			free(params);
		}
		void GetVisibleFrameRect(float& x0, float& y0, float& X1, float& Y1)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxMoviePlayer.GetVisibleFrameRect");
			byte* params = (byte*)malloc(16);
			*(float*)params = x0;
			*(float*)(params + 4) = y0;
			*(float*)(params + 8) = X1;
			*(float*)(params + 12) = Y1;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			x0 = *(float*)params;
			y0 = *(float*)(params + 4);
			X1 = *(float*)(params + 8);
			Y1 = *(float*)(params + 12);
			free(params);
		}
		void SetAlignment(byte A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxMoviePlayer.SetAlignment");
			byte* params = (byte*)malloc(1);
			*params = A;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetViewScaleMode(byte SM)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxMoviePlayer.SetViewScaleMode");
			byte* params = (byte*)malloc(1);
			*params = SM;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetViewport(int X, int Y, int Width, int Height)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxMoviePlayer.SetViewport");
			byte* params = (byte*)malloc(16);
			*(int*)params = X;
			*(int*)(params + 4) = Y;
			*(int*)(params + 8) = Width;
			*(int*)(params + 12) = Height;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class GameViewportClient* GetGameViewportClient()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxMoviePlayer.GetGameViewportClient");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class GameViewportClient**)params;
			free(params);
			return returnVal;
		}
		void SetPriority(byte NewPriority)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxMoviePlayer.SetPriority");
			byte* params = (byte*)malloc(1);
			*params = NewPriority;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PublishDataStoreValues()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxMoviePlayer.PublishDataStoreValues");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RefreshDataStoreBindings()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxMoviePlayer.RefreshDataStoreBindings");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool SetExternalTexture(ScriptArray<wchar_t> Resource, class Texture* Texture)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxMoviePlayer.SetExternalTexture");
			byte* params = (byte*)malloc(20);
			*(ScriptArray<wchar_t>*)params = Resource;
			*(class Texture**)(params + 12) = Texture;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		void SetExternalInterface(class Object* H)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxMoviePlayer.SetExternalInterface");
			byte* params = (byte*)malloc(4);
			*(class Object**)params = H;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetForceSmoothAnimation(bool bEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxMoviePlayer.SetForceSmoothAnimation");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetTimingMode(byte Mode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxMoviePlayer.SetTimingMode");
			byte* params = (byte*)malloc(1);
			*params = Mode;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetMovieInfo(class SwfMovie* Data)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxMoviePlayer.SetMovieInfo");
			byte* params = (byte*)malloc(4);
			*(class SwfMovie**)params = Data;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ConditionalClearPause()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxMoviePlayer.ConditionalClearPause");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnClose()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxMoviePlayer.OnClose");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Close(bool Unload)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxMoviePlayer.Close");
			byte* params = (byte*)malloc(4);
			*(bool*)params = Unload;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetPause(bool bPausePlayback)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxMoviePlayer.SetPause");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bPausePlayback;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnPostAdvance(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxMoviePlayer.OnPostAdvance");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PostAdvance(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxMoviePlayer.PostAdvance");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool Start(bool StartPaused)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxMoviePlayer.Start");
			byte* params = (byte*)malloc(8);
			*(bool*)params = StartPaused;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
