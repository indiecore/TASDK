#pragma once
#include "Engine.PhysicalMaterialPropertyBase.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UTPhysicalMaterialProperty : public PhysicalMaterialPropertyBase
	{
	public:
		ADD_STRUCT(ScriptName, MaterialType, 60)
	};
}
#undef ADD_STRUCT
