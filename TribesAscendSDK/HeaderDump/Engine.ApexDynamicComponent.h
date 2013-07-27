#pragma once
#include "Engine.ApexComponentBase.h"
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class ApexDynamicComponent : public ApexComponentBase
	{
	public:
		ADD_STRUCT(Object::Pointer, ComponentDynamicResources, 520)
	};
}
#undef ADD_STRUCT
