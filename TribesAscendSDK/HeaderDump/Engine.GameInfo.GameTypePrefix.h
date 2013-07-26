#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameInfo.GameTypePrefix." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GameTypePrefix
	{
	public:
		ADD_VAR(::StrProperty, GameType, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bUsesCommonPackage, 0x1)
		ADD_VAR(::StrProperty, Prefix, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
