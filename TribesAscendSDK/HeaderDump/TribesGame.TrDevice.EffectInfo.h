#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TrDevice.EffectInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TrDevice.EffectInfo." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class EffectInfo
	{
	public:
		ADD_VAR(::FloatProperty, interval, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Value, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Lifetime, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, Type, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, effectClass)
		ADD_VAR(::ByteProperty, FireModeNum, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
