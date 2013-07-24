#pragma once
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.SeqEvent_PlayerSpawned." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SeqEvent_PlayerSpawned : public SequenceEvent
	{
	public:
		ADD_OBJECT(Object, SpawnPoint)
	};
}
#undef ADD_OBJECT
