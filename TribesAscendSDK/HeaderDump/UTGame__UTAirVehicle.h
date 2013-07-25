#pragma once
#include "UTGame__UTVehicle.h"
#include "UDKBase__UDKProjectile.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTAirVehicle." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UTAirVehicle : public UTVehicle
	{
	public:
		ADD_VAR(::FloatProperty, LastRadarLockWarnTime, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, RadarLockMessage, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, PushForce, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bAutoLand, 0x1)
		void LockOnWarning(class UDKProjectile* IncomingMissile)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTAirVehicle.LockOnWarning");
			byte* params = (byte*)malloc(4);
			*(class UDKProjectile**)params = IncomingMissile;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetDriving(bool bNewDriving)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTAirVehicle.SetDriving");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bNewDriving;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool RecommendLongRangedAttack()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTAirVehicle.RecommendLongRangedAttack");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool Dodge(byte DoubleClickMove)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTAirVehicle.Dodge");
			byte* params = (byte*)malloc(5);
			*params = DoubleClickMove;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
