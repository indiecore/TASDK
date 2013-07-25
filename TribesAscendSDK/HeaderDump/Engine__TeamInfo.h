#pragma once
#include "Engine__ReplicationInfo.h"
#include "Engine__Controller.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.TeamInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.TeamInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TeamInfo : public ReplicationInfo
	{
	public:
		ADD_VAR(::IntProperty, TeamIndex, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Score, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'TeamColor'!
		ADD_VAR(::IntProperty, Size, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, TeamName, 0xFFFFFFFF)
		ScriptArray<wchar_t> GetHumanReadableName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.TeamInfo.GetHumanReadableName");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.TeamInfo.ReplicatedEvent");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Destroyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.TeamInfo.Destroyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool AddToTeam(class Controller* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.TeamInfo.AddToTeam");
			byte* params = (byte*)malloc(8);
			*(class Controller**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void RemoveFromTeam(class Controller* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.TeamInfo.RemoveFromTeam");
			byte* params = (byte*)malloc(4);
			*(class Controller**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		byte GetTeamNum()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.TeamInfo.GetTeamNum");
			byte* params = (byte*)malloc(1);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
