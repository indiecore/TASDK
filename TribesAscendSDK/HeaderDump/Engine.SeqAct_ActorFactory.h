#pragma once
#include "Core.Object.h"
#include "Engine.Actor.h"
#include "Engine.SeqAct_Latent.h"
#include "Engine.ActorFactory.h"
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
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class SeqAct_ActorFactory : public SeqAct_Latent
	{
	public:
		enum EPointSelection : byte
		{
			PS_Normal = 0,
			PS_Random = 1,
			PS_Reverse = 2,
			PS_MAX = 3,
		};
		ADD_STRUCT(ScriptArray<class Actor*>, SpawnPoints, 260)
		ADD_STRUCT(ScriptArray<Vector>, SpawnLocations, 272)
		ADD_STRUCT(ScriptArray<Vector>, SpawnOrientations, 284)
		ADD_STRUCT(float, RemainingDelay, 312)
		ADD_STRUCT(int, SpawnedCount, 308)
		ADD_STRUCT(int, LastSpawnIdx, 304)
		ADD_STRUCT(float, SpawnDelay, 300)
		ADD_STRUCT(int, SpawnCount, 296)
		ADD_STRUCT(SeqAct_ActorFactory::EPointSelection, PointSelection, 256)
		ADD_OBJECT(ActorFactory, Factory, 252)
		ADD_BOOL(bCheckSpawnCollision, 248, 0x4)
		ADD_BOOL(bIsSpawning, 248, 0x2)
		ADD_BOOL(bEnabled, 248, 0x1)
		int GetObjClassVersion()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(25562);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
