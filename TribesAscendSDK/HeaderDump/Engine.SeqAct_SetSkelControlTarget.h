#pragma once
#include "Engine.SequenceAction.h"
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class SeqAct_SetSkelControlTarget : public SequenceAction
	{
	public:
		ADD_STRUCT(ScriptArray<class Object*>, TargetActors, 240)
		ADD_STRUCT(ScriptName, SkelControlName, 232)
	};
}
#undef ADD_STRUCT
