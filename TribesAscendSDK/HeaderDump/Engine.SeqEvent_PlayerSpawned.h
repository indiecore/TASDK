#pragma once
#include "Engine.SequenceEvent.h"
#include "Core.Object.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class SeqEvent_PlayerSpawned : public SequenceEvent
	{
	public:
		ADD_OBJECT(Object, SpawnPoint, 256)
	};
}
#undef ADD_OBJECT
