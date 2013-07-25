#pragma once
#include "Engine__SeqAct_Latent.h"
#include "Engine__ActorFactory.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqAct_ActorFactory." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.SeqAct_ActorFactory." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SeqAct_ActorFactory : public SeqAct_Latent
	{
	public:
		ADD_VAR(::FloatProperty, RemainingDelay, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SpawnedCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, LastSpawnIdx, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SpawnDelay, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SpawnCount, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, PointSelection, 0xFFFFFFFF)
		ADD_OBJECT(ActorFactory, Factory)
		ADD_VAR(::BoolProperty, bCheckSpawnCollision, 0x4)
		ADD_VAR(::BoolProperty, bIsSpawning, 0x2)
		ADD_VAR(::BoolProperty, bEnabled, 0x1)
		// Here lies the not-yet-implemented method 'GetObjClassVersion'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
