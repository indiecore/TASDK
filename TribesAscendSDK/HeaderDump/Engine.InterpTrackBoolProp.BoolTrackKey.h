#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " InterpTrackBoolProp.BoolTrackKey." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class BoolTrackKey
	{
	public:
		ADD_VAR(::BoolProperty, Value, 0x1)
		ADD_VAR(::FloatProperty, Time, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
