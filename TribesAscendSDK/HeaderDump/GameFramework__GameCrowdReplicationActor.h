#pragma once
#include "Engine__Actor.h"
#include "GameFramework__SeqAct_GameCrowdSpawner.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.GameCrowdReplicationActor." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty GameFramework.GameCrowdReplicationActor." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GameCrowdReplicationActor : public Actor
	{
	public:
		ADD_VAR(::IntProperty, DestroyAllCount, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bSpawningActive, 0x1)
		ADD_OBJECT(SeqAct_GameCrowdSpawner, Spawner)
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameCrowdReplicationActor.ReplicatedEvent");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
