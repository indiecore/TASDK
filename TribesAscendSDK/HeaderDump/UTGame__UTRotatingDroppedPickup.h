#pragma once
#include "UTGame__UTDroppedPickup.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTRotatingDroppedPickup." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UTRotatingDroppedPickup : public UTDroppedPickup
	{
	public:
		ADD_VAR(::FloatProperty, YawRotationRate, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
