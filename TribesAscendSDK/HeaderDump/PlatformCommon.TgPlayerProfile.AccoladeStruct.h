#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TgPlayerProfile.AccoladeStruct." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class AccoladeStruct
	{
	public:
		ADD_VAR(::IntProperty, Value, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Type, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ActivityId, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, AccoladeId, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
