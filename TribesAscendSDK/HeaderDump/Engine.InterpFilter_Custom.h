#pragma once
#include "Engine.InterpFilter.h"
#include "Engine.InterpGroup.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class InterpFilter_Custom : public InterpFilter
	{
	public:
		ADD_STRUCT(ScriptArray<class InterpGroup*>, GroupsToInclude, 72)
	};
}
#undef ADD_STRUCT
