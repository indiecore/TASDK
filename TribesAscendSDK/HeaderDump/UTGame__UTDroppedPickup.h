#pragma once
#include "Engine__DroppedPickup.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTDroppedPickup." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UTDroppedPickup : public DroppedPickup
	{
	public:
		ADD_VAR(::BoolProperty, bPickupable, 0x1)
		ADD_VAR(::FloatProperty, StartScale, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
