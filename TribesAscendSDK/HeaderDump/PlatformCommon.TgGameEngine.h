#pragma once
#include "Engine.GameEngine.h"
#include "Engine.PlayerController.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty PlatformCommon.TgGameEngine." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TgGameEngine : public GameEngine
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'pEventMarshal'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'pOutgoingMarshal'!
		void OnMarshalEvent(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer'!
void* pMarEvent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function PlatformCommon.TgGameEngine.OnMarshalEvent");
			byte* params = (byte*)malloc(4);
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer'!
void**)params = pMarEvent;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool SetFunction(int nFunction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function PlatformCommon.TgGameEngine.SetFunction");
			byte* params = (byte*)malloc(8);
			*(int*)params = nFunction;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool SetFieldInt(int nToken, int IntValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function PlatformCommon.TgGameEngine.SetFieldInt");
			byte* params = (byte*)malloc(12);
			*(int*)params = nToken;
			*(int*)(params + 4) = IntValue;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool SetFieldFloat(int nToken, float FloatValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function PlatformCommon.TgGameEngine.SetFieldFloat");
			byte* params = (byte*)malloc(12);
			*(int*)params = nToken;
			*(float*)(params + 4) = FloatValue;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool SetFieldString(int nToken, ScriptArray<wchar_t> StrValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function PlatformCommon.TgGameEngine.SetFieldString");
			byte* params = (byte*)malloc(20);
			*(int*)params = nToken;
			*(ScriptArray<wchar_t>*)(params + 4) = StrValue;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		void ClearMarshal()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function PlatformCommon.TgGameEngine.ClearMarshal");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SendMarshal(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void* qwPlayerId, bool bLowPriority)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function PlatformCommon.TgGameEngine.SendMarshal");
			byte* params = (byte*)malloc(12);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void**)params = qwPlayerId;
			*(bool*)(params + 8) = bLowPriority;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SendMarshalAll(bool bLowPriority)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function PlatformCommon.TgGameEngine.SendMarshalAll");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bLowPriority;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool GetFieldInt(int nToken, int& IntValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function PlatformCommon.TgGameEngine.GetFieldInt");
			byte* params = (byte*)malloc(12);
			*(int*)params = nToken;
			*(int*)(params + 4) = IntValue;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			IntValue = *(int*)(params + 4);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool GetFieldFloat(int nToken, float& FloatValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function PlatformCommon.TgGameEngine.GetFieldFloat");
			byte* params = (byte*)malloc(12);
			*(int*)params = nToken;
			*(float*)(params + 4) = FloatValue;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			FloatValue = *(float*)(params + 4);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool GetFieldString(int nToken, ScriptArray<wchar_t>& StrValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function PlatformCommon.TgGameEngine.GetFieldString");
			byte* params = (byte*)malloc(20);
			*(int*)params = nToken;
			*(ScriptArray<wchar_t>*)(params + 4) = StrValue;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			StrValue = *(ScriptArray<wchar_t>*)(params + 4);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		void AddMarshalEventDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* MarshalEventDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function PlatformCommon.TgGameEngine.AddMarshalEventDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = MarshalEventDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearMarshalEventDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* MarshalEventDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function PlatformCommon.TgGameEngine.ClearMarshalEventDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = MarshalEventDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SendCtrlRequest(ScriptArray<wchar_t> fsRequest)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function PlatformCommon.TgGameEngine.SendCtrlRequest");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = fsRequest;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SendGameRequest(ScriptArray<wchar_t> fsRequest)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function PlatformCommon.TgGameEngine.SendGameRequest");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = fsRequest;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool HandlePlayerCommandInput(ScriptArray<wchar_t> FSCommand, class PlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function PlatformCommon.TgGameEngine.HandlePlayerCommandInput");
			byte* params = (byte*)malloc(20);
			*(ScriptArray<wchar_t>*)params = FSCommand;
			*(class PlayerController**)(params + 12) = PC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_STRUCT
