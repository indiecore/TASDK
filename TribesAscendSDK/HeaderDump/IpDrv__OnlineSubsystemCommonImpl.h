#pragma once
#include "Engine__OnlineSubsystem.h"
#include "IpDrv__OnlineGameInterfaceImpl.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " IpDrv.OnlineSubsystemCommonImpl." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty IpDrv.OnlineSubsystemCommonImpl." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty IpDrv.OnlineSubsystemCommonImpl." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class OnlineSubsystemCommonImpl : public OnlineSubsystem
	{
	public:
		ADD_OBJECT(OnlineGameInterfaceImpl, GameInterfaceImpl)
		ADD_VAR(::BoolProperty, bIsUsingSpeechRecognition, 0x1)
		ADD_VAR(::IntProperty, MaxRemoteTalkers, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxLocalTalkers, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VoiceEngine'!
		ScriptArray<wchar_t> GetPlayerNicknameFromIndex(int UserIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.OnlineSubsystemCommonImpl.GetPlayerNicknameFromIndex");
			byte* params = (byte*)malloc(16);
			*(int*)params = UserIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 4);
			free(params);
			return returnVal;
		}
		
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void* GetPlayerUniqueNetIdFromIndex(int UserIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.OnlineSubsystemCommonImpl.GetPlayerUniqueNetIdFromIndex");
			byte* params = (byte*)malloc(12);
			*(int*)params = UserIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void**)(params + 4);
			free(params);
			return returnVal;
		}
		bool IsPlayerInSession(ScriptName SessionName, 
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void* PlayerID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.OnlineSubsystemCommonImpl.IsPlayerInSession");
			byte* params = (byte*)malloc(20);
			*(ScriptName*)params = SessionName;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void**)(params + 8) = PlayerID;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		void GetRegisteredPlayers(ScriptName SessionName, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& OutRegisteredPlayers)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function IpDrv.OnlineSubsystemCommonImpl.GetRegisteredPlayers");
			byte* params = (byte*)malloc(20);
			*(ScriptName*)params = SessionName;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 8) = OutRegisteredPlayers;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			OutRegisteredPlayers = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 8);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
