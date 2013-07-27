#pragma once
#include "Engine.PrimitiveComponent.h"
#include "Engine.MaterialInterface.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class RB_ConstraintDrawComponent : public PrimitiveComponent
	{
	public:
		ADD_OBJECT(MaterialInterface, LimitMaterial, 488)
	};
}
#undef ADD_OBJECT
