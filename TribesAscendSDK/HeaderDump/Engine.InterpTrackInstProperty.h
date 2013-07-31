#pragma once
#include "Core.Object.h"
#include "Engine.InterpTrackInst.h"
#include "Core.Function.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class InterpTrackInstProperty : public InterpTrackInst
	{
	public:
		ADD_OBJECT(Object, PropertyOuterObjectInst, 64)
		ADD_OBJECT(Function, PropertyUpdateCallback, 60)
	};
}
#undef ADD_OBJECT
