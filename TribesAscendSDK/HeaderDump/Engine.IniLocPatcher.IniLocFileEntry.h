#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " IniLocPatcher.IniLocFileEntry." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class IniLocFileEntry
	{
	public:
		ADD_VAR(::ByteProperty, ReadState, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, Filename, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
