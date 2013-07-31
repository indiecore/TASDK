#pragma once
#include "Engine.StaticMeshActorBase.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class StaticMeshCollectionActor : public StaticMeshActorBase
	{
	public:
		ADD_STRUCT(ScriptArray<
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void*>, StaticMeshComponents, 476)
		ADD_STRUCT(int, MaxStaticMeshComponents, 488)
	};
}
#undef ADD_STRUCT
