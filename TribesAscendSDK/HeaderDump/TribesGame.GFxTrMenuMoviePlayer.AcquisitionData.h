#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GFxTrMenuMoviePlayer.AcquisitionData." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class AcquisitionData
	{
	public:
		ADD_VAR(::IntProperty, Icon, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, Type, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, Text, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, Title, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
