#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " OnlineSubsystem.TitleFile." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TitleFile
	{
	public:
		ADD_VAR(::StrProperty, Filename, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, AsyncState, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
