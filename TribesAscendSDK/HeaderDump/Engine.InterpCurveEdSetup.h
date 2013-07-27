#pragma once
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
	class InterpCurveEdSetup : public Object
	{
	public:
		class CurveEdEntry
		{
		public:
			ADD_STRUCT(float, ClampHigh, 40)
			ADD_STRUCT(float, ClampLow, 36)
			ADD_STRUCT(int, bClamp, 32)
			ADD_STRUCT(int, bFloatingPointColorCurve, 28)
			ADD_STRUCT(int, bColorCurve, 24)
			ADD_STRUCT(int, bHideCurve, 20)
			ADD_STRUCT(ScriptString*, CurveName, 8)
			ADD_STRUCT(Object::Color, CurveColor, 4)
			ADD_OBJECT(Object, CurveObject, 0)
		};
		class CurveEdTab
		{
		public:
			ADD_STRUCT(ScriptArray<InterpCurveEdSetup::CurveEdEntry>, Curves, 12)
			ADD_STRUCT(float, ViewEndOutput, 36)
			ADD_STRUCT(float, ViewStartOutput, 32)
			ADD_STRUCT(float, ViewEndInput, 28)
			ADD_STRUCT(float, ViewStartInput, 24)
			ADD_STRUCT(ScriptString*, TabName, 0)
		};
		ADD_STRUCT(ScriptArray<InterpCurveEdSetup::CurveEdTab>, Tabs, 60)
		ADD_STRUCT(int, ActiveTab, 72)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
