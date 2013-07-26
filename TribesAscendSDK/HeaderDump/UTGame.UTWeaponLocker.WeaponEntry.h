#pragma once
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTWeaponLocker.WeaponEntry." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class WeaponEntry
	{
	public:
		ADD_OBJECT(ScriptClass, WeaponClass)
	};
}
#undef ADD_OBJECT
