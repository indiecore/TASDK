#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameInfo.GameClassShortName." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GameClassShortName
	{
	public:
		ADD_VAR(::StrProperty, GameClassName, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ShortName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
