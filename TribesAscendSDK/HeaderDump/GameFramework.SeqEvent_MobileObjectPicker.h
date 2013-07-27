#pragma once
#include "GameFramework.SeqEvent_MobileRawInput.h"
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
	class SeqEvent_MobileObjectPicker : public SeqEvent_MobileRawInput
	{
	public:
		ADD_STRUCT(ScriptArray<class Object*>, Targets, 304)
		ADD_OBJECT(Object, FinalTouchObject, 300)
		ADD_STRUCT(Object::Vector, FinalTouchNormal, 288)
		ADD_STRUCT(Object::Vector, FinalTouchLocation, 276)
		ADD_STRUCT(float, TraceDistance, 272)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
