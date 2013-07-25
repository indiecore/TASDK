#pragma once
#include "Engine.NavigationPoint.h"
#include "Engine.SequenceAction.h"
#include "UTGame.UTBot.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTSeqAct_AddNamedBot." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTSeqAct_AddNamedBot." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTSeqAct_AddNamedBot : public SequenceAction
	{
	public:
		ADD_OBJECT(UTBot, SpawnedBot)
		ADD_OBJECT(NavigationPoint, StartSpot)
		ADD_VAR(::IntProperty, TeamIndex, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bForceTeam, 0x1)
		ADD_VAR(::StrProperty, BotName, 0xFFFFFFFF)
		void Activated()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSeqAct_AddNamedBot.Activated");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int GetObjClassVersion()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSeqAct_AddNamedBot.GetObjClassVersion");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
