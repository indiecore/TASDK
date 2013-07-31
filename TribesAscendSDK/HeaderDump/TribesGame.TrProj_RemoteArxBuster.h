#pragma once
#include "TribesGame.TrProj_StickyGrenade.h"
#include "Engine.Actor.h"
#include "Core.Object.h"
#include "Engine.Controller.h"
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
namespace UnrealScript
{
	class TrProj_RemoteArxBuster : public TrProj_StickyGrenade
	{
	public:
		ADD_BOOL(m_bIsDetonating, 892, 0x1)
		void PreBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108922);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TakeRadiusDamage(class Controller* EventInstigator, float BaseDamage, float InDamageRadius, ScriptClass* DamageType, float Momentum, Vector HurtOrigin, bool bFullDamage, class Actor* DamageCauser, float DamageFalloffExponent)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108923);
			byte params[44] = { NULL };
			*(class Controller**)params = EventInstigator;
			*(float*)&params[4] = BaseDamage;
			*(float*)&params[8] = InDamageRadius;
			*(ScriptClass**)&params[12] = DamageType;
			*(float*)&params[16] = Momentum;
			*(Vector*)&params[20] = HurtOrigin;
			*(bool*)&params[32] = bFullDamage;
			*(class Actor**)&params[36] = DamageCauser;
			*(float*)&params[40] = DamageFalloffExponent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TakeDamage(int DamageAmount, class Controller* EventInstigator, Vector HitLocation, Vector Momentum, ScriptClass* DamageType, Actor::TraceHitInfo HitInfo, class Actor* DamageCauser)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108934);
			byte params[68] = { NULL };
			*(int*)params = DamageAmount;
			*(class Controller**)&params[4] = EventInstigator;
			*(Vector*)&params[8] = HitLocation;
			*(Vector*)&params[20] = Momentum;
			*(ScriptClass**)&params[32] = DamageType;
			*(Actor::TraceHitInfo*)&params[36] = HitInfo;
			*(class Actor**)&params[64] = DamageCauser;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ReportDestroyedByOtherToParentDevice()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108942);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool StickToTarget(class Actor* Target, Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108946);
			byte params[32] = { NULL };
			*(class Actor**)params = Target;
			*(Vector*)&params[4] = HitLocation;
			*(Vector*)&params[16] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[28];
		}
		void Destroyed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(108951);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
