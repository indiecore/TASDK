#pragma once
#include "TribesGame.TrDevice_AutoFire.h"
#include "Engine.Projectile.h"
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
		Vector GetPhysicalFireStartLoc(Vector AimDir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Claymore.GetPhysicalFireStartLoc");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = AimDir;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 12);
			free(params);
			return returnVal;
		}
		class Projectile* ProjectileFire()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_Claymore.ProjectileFire");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Projectile**)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
