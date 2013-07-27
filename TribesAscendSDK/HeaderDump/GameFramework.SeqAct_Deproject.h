#pragma once
#include "Engine.SequenceAction.h"
#include "Core.Object.h"
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
	class SeqAct_Deproject : public SequenceAction
	{
	public:
		ADD_STRUCT(Object::Vector, HitNormal, 260)
		ADD_STRUCT(Object::Vector, HitLocation, 248)
		ADD_OBJECT(Object, HitObject, 244)
		ADD_STRUCT(float, TraceDistance, 240)
		ADD_STRUCT(float, ScreenY, 236)
		ADD_STRUCT(float, ScreenX, 232)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
