#pragma once
#include "Core.Object.h"
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
namespace UnrealScript
{
	class CurveEdPresetCurve : public Object
	{
	public:
		struct PresetGeneratedPoint
		{
		public:
			ADD_STRUCT(Object::EInterpCurveMode, IntepMode, 20)
			ADD_STRUCT(float, TangentOut, 16)
			ADD_STRUCT(float, TangentIn, 12)
			ADD_BOOL(TangentsValid, 8, 0x1)
			ADD_STRUCT(float, KeyOut, 4)
			ADD_STRUCT(float, KeyIn, 0)
		};
		ADD_STRUCT(ScriptArray<CurveEdPresetCurve::PresetGeneratedPoint>, Points, 72)
		ADD_STRUCT(ScriptString*, CurveName, 60)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
