#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " EngineTypes.LocalizedSubtitle." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class LocalizedSubtitle
	{
	public:
		ADD_VAR(::BoolProperty, bManualWordWrap, 0x2)
		ADD_VAR(::BoolProperty, bMature, 0x1)
		ADD_VAR(::StrProperty, LanguageExt, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
