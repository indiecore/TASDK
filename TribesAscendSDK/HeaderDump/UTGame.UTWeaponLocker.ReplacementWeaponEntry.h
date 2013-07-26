#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTWeaponLocker.ReplacementWeaponEntry." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTWeaponLocker.ReplacementWeaponEntry." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class ReplacementWeaponEntry
	{
	public:
		ADD_OBJECT(ScriptClass, WeaponClass)
		ADD_VAR(::BoolProperty, bReplaced, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
