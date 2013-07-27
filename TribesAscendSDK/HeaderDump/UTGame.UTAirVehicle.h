#pragma once
#include "UTGame.UTVehicle.h"
#include "UDKBase.UDKProjectile.h"
#include "Engine.Actor.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UTAirVehicle : public UTVehicle
	{
	public:
		ADD_STRUCT(float, LastRadarLockWarnTime, 2776)
		ADD_STRUCT(ScriptString*, RadarLockMessage, 2764)
		ADD_STRUCT(float, PushForce, 2760)
		ADD_BOOL(bAutoLand, 2756, 0x1)
		void LockOnWarning(class UDKProjectile* IncomingMissile)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTAirVehicle.LockOnWarning");
			byte params[4] = { NULL };
			*(class UDKProjectile**)&params[0] = IncomingMissile;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetDriving(bool bNewDriving)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTAirVehicle.SetDriving");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bNewDriving;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool RecommendLongRangedAttack()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTAirVehicle.RecommendLongRangedAttack");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool Dodge(Actor::EDoubleClickDir DoubleClickMove)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTAirVehicle.Dodge");
			byte params[5] = { NULL };
			*(Actor::EDoubleClickDir*)&params[0] = DoubleClickMove;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
