#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.Path_WithinDistanceEnvelope." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.Path_WithinDistanceEnvelope." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class Path_WithinDistanceEnvelope : public PathConstraint
	{
	public:
		ADD_STRUCT(::VectorProperty, EnvelopeTestPoint, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, SoftStartPenalty, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bOnlyThrowOutNodesThatLeaveEnvelope, 0x2)
		ADD_VAR(::BoolProperty, bSoft, 0x1)
		ADD_VAR(::FloatProperty, MinDistance, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxDistance, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
