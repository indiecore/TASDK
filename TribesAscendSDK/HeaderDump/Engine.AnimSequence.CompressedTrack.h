#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " AnimSequence.CompressedTrack." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class CompressedTrack
	{
	public:
		ADD_VAR(::FloatProperty, Ranges, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Mins, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
