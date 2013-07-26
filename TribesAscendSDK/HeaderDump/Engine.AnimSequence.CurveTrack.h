#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " AnimSequence.CurveTrack." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class CurveTrack
	{
	public:
		ADD_VAR(::NameProperty, CurveName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
