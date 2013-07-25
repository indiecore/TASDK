#pragma once
#include "TribesGame__TrDevice_AutoFire.h"
#include "Engine__Projectile.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrDevice_Claymore." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrDevice_Claymore : public TrDevice_AutoFire
	{
	public:
		ADD_VAR(::FloatProperty, m_fWorldZPlacementOffset, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'GetPhysicalFireStartLoc'
		// Here lies the not-yet-implemented method 'ProjectileFire'
	};
}
#undef ADD_VAR
