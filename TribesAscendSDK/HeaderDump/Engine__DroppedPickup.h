#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.DroppedPickup." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.DroppedPickup." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class DroppedPickup : public Actor
	{
	public:
		ADD_VAR(::BoolProperty, bFadeOut, 0x1)
		ADD_OBJECT(NavigationPoint, PickupCache)
		ADD_OBJECT(Inventory, Inventory)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
