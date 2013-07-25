#pragma once
#include "Core.Object.h"
#include "Engine.LocalMessage.h"
#include "Engine.PlayerReplicationInfo.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.FailedConnect." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class FailedConnect : public LocalMessage
	{
	public:
		ADD_VAR(::StrProperty, FailMessage, 0xFFFFFFFF)
		int GetFailSwitch(ScriptArray<wchar_t> FailString)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FailedConnect.GetFailSwitch");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = FailString;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 12);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetString(int Switch, bool bPRI1HUD, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI, class Object* OptionalObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FailedConnect.GetString");
			byte* params = (byte*)malloc(32);
			*(int*)params = Switch;
			*(bool*)(params + 4) = bPRI1HUD;
			*(class PlayerReplicationInfo**)(params + 8) = RelatedPRI;
			*(class PlayerReplicationInfo**)(params + 12) = RelatedPRI;
			*(class Object**)(params + 16) = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 20);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
