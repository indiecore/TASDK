#pragma once
#include "Engine.PrimitiveComponent.h"
#include "Core.Object.InterpCurveFloat.h"
#include "Core.Object.Color.h"
#include "Core.Object.InterpCurveVector.h"
#include "Core.Object.Vector.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SplineComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.SplineComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SplineComponent : public PrimitiveComponent
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<InterpCurveFloat>, SplineReparamTable, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bSplineDisabled, 0x1)
		ADD_VAR(::FloatProperty, SplineArrowSize, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SplineDrawRes, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Color>, SplineColor, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SplineCurviness, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<InterpCurveVector>, SplineInfo, 0xFFFFFFFF)
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
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		Vector GetLocationAtDistanceAlongSpline(float Distance)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SplineComponent.GetLocationAtDistanceAlongSpline");
			byte* params = (byte*)malloc(16);
			*(float*)params = Distance;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 4);
			free(params);
			return returnVal;
		}
		Vector GetTangentAtDistanceAlongSpline(float Distance)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SplineComponent.GetTangentAtDistanceAlongSpline");
			byte* params = (byte*)malloc(16);
			*(float*)params = Distance;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 4);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
