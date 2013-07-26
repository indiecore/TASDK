#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GFxMoviePlayer.ASValue." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ASValue
	{
	public:
		ADD_VAR(::ByteProperty, Type, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, B, 0x1)
		ADD_VAR(::FloatProperty, N, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, S, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
