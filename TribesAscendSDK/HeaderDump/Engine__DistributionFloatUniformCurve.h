#pragma once
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.DistributionFloatUniformCurve." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class DistributionFloatUniformCurve : public DistributionFloat
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.InterpCurveVector2D' for the property named 'ConstantCurve'!
	};
}
#undef ADD_STRUCT
