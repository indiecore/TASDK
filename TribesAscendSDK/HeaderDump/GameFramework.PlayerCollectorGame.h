#pragma once
#include "Engine.GameInfo.h"
#include "Engine.PlayerController.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.PlayerCollectorGame." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class PlayerCollectorGame : public GameInfo
	{
	public:
		ADD_VAR(::StrProperty, URLToLoad, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NumberOfClientsToWaitFor, 0xFFFFFFFF)
		class PlayerController* Login(ScriptArray<wchar_t> Portal, ScriptArray<wchar_t> Options, 
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void* UniqueId, ScriptArray<wchar_t>& ErrorMessage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.PlayerCollectorGame.Login");
			byte* params = (byte*)malloc(48);
			*(ScriptArray<wchar_t>*)params = Portal;
			*(ScriptArray<wchar_t>*)(params + 12) = Options;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void**)(params + 24) = UniqueId;
			*(ScriptArray<wchar_t>*)(params + 32) = ErrorMessage;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			ErrorMessage = *(ScriptArray<wchar_t>*)(params + 32);
			auto returnVal = *(class PlayerController**)(params + 44);
			free(params);
			return returnVal;
		}
		void GetSeamlessTravelActorList(bool bToEntry, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& ActorList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.PlayerCollectorGame.GetSeamlessTravelActorList");
			byte* params = (byte*)malloc(16);
			*(bool*)params = bToEntry;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4) = ActorList;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			ActorList = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4);
			free(params);
		}
	};
}
#undef ADD_VAR
