#pragma once
#include "Core.Object.h"
#include "Engine.GameEngine.h"
#include "Engine.PlayerController.h"
#include "Engine.OnlineSubsystem.h"
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
namespace UnrealScript
{
	class TgGameEngine : public GameEngine
	{
	public:
		struct MAR_EVENT
		{
		public:
			ADD_STRUCT(Object::Pointer, pMarshal, 40)
			ADD_STRUCT(ScriptString*, fsMessage, 28)
			ADD_STRUCT(int, nStmMsgId, 24)
			ADD_STRUCT(QWord, qwInfo, 16)
			ADD_STRUCT(QWord, qwId, 8)
			ADD_STRUCT(int, nFunction, 4)
			ADD_BOOL(bSuccess, 0, 0x1)
		};
		ADD_STRUCT(ScriptArray<
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void*>, MarshalEventDelegates, 1808)
		ADD_STRUCT(Object::Pointer, pEventMarshal, 1824)
		ADD_STRUCT(Object::Pointer, pOutgoingMarshal, 1820)
		void OnMarshalEvent(Object::Pointer pMarEvent)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34270);
			byte params[4] = { NULL };
			*(Object::Pointer*)params = pMarEvent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool SetFunction(int nFunction)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34282);
			byte params[8] = { NULL };
			*(int*)params = nFunction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool SetFieldInt(int nToken, int IntValue)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34285);
			byte params[12] = { NULL };
			*(int*)params = nToken;
			*(int*)&params[4] = IntValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool SetFieldFloat(int nToken, float FloatValue)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34289);
			byte params[12] = { NULL };
			*(int*)params = nToken;
			*(float*)&params[4] = FloatValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool SetFieldString(int nToken, ScriptString* StrValue)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34293);
			byte params[20] = { NULL };
			*(int*)params = nToken;
			*(ScriptString**)&params[4] = StrValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void ClearMarshal()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34297);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SendMarshal(OnlineSubsystem::UniqueNetId qwPlayerId, bool bLowPriority)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34298);
			byte params[12] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)params = qwPlayerId;
			*(bool*)&params[8] = bLowPriority;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SendMarshalAll(bool bLowPriority)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34301);
			byte params[4] = { NULL };
			*(bool*)params = bLowPriority;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool GetFieldInt(int nToken, int& IntValue)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34303);
			byte params[12] = { NULL };
			*(int*)params = nToken;
			*(int*)&params[4] = IntValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			IntValue = *(int*)&params[4];
			return *(bool*)&params[8];
		}
		bool GetFieldFloat(int nToken, float& FloatValue)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34307);
			byte params[12] = { NULL };
			*(int*)params = nToken;
			*(float*)&params[4] = FloatValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			FloatValue = *(float*)&params[4];
			return *(bool*)&params[8];
		}
		bool GetFieldString(int nToken, ScriptString*& StrValue)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34311);
			byte params[20] = { NULL };
			*(int*)params = nToken;
			*(ScriptString**)&params[4] = StrValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			StrValue = *(ScriptString**)&params[4];
			return *(bool*)&params[16];
		}
		void AddMarshalEventDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* MarshalEventDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34316);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = MarshalEventDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearMarshalEventDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* MarshalEventDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34318);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = MarshalEventDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SendCtrlRequest(ScriptString* fsRequest)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34320);
			byte params[12] = { NULL };
			*(ScriptString**)params = fsRequest;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SendGameRequest(ScriptString* fsRequest)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34322);
			byte params[12] = { NULL };
			*(ScriptString**)params = fsRequest;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool HandlePlayerCommandInput(ScriptString* FSCommand, class PlayerController* PC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34324);
			byte params[20] = { NULL };
			*(ScriptString**)params = FSCommand;
			*(class PlayerController**)&params[12] = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
