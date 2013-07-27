#pragma once
#include "TribesGame.TrDevice_AutoFire.h"
#include "Core.Object.h"
#include "Engine.Projectile.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class TrDevice_Claymore : public TrDevice_AutoFire
	{
	public:
		ADD_STRUCT(float, m_fWorldZPlacementOffset, 2164)
		Vector GetPhysicalFireStartLoc(Vector AimDir)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(81013);
			byte params[24] = { NULL };
			*(Vector*)params = AimDir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[12];
		}
		class Projectile* ProjectileFire()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(81017);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Projectile**)params;
		}
	};
}
#undef ADD_STRUCT
