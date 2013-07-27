#pragma once
#include "Engine.PrimitiveComponent.h"
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
	class SplineComponent : public PrimitiveComponent
	{
	public:
		ADD_STRUCT(Object::InterpCurveFloat, SplineReparamTable, 524)
		ADD_BOOL(bSplineDisabled, 520, 0x1)
		ADD_STRUCT(float, SplineArrowSize, 516)
		ADD_STRUCT(float, SplineDrawRes, 512)
		ADD_STRUCT(Object::Color, SplineColor, 508)
		ADD_STRUCT(float, SplineCurviness, 504)
		ADD_STRUCT(Object::InterpCurveVector, SplineInfo, 488)
		void UpdateSplineCurviness()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SplineComponent.UpdateSplineCurviness");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateSplineReparamTable()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SplineComponent.UpdateSplineReparamTable");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		float GetSplineLength()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SplineComponent.GetSplineLength");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		Object::Vector GetLocationAtDistanceAlongSpline(float Distance)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SplineComponent.GetLocationAtDistanceAlongSpline");
			byte params[16] = { NULL };
			*(float*)&params[0] = Distance;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[4];
		}
		Object::Vector GetTangentAtDistanceAlongSpline(float Distance)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SplineComponent.GetTangentAtDistanceAlongSpline");
			byte params[16] = { NULL };
			*(float*)&params[0] = Distance;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[4];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
