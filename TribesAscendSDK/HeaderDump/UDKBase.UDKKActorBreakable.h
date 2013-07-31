#pragma once
#include "Engine.KActor.h"
#include "Core.Object.h"
#include "Engine.Actor.h"
#include "Engine.Controller.h"
#include "Engine.ParticleSystem.h"
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
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class UDKKActorBreakable : public KActor
	{
	public:
		ADD_OBJECT(Controller, InstigatorController, 740)
		ADD_OBJECT(ParticleSystem, BrokenTemplate, 736)
		ADD_STRUCT(int, DOEResetThreshold, 732)
		ADD_OBJECT(ScriptClass, DmgTypeClass, 728)
		ADD_STRUCT(int, EncroachDamage_Self, 724)
		ADD_STRUCT(int, EncroachDamage_Other, 720)
		ADD_STRUCT(int, Health, 716)
		ADD_BOOL(bBroken, 712, 0x20)
		ADD_BOOL(bBreakWhenCausingDamage, 712, 0x10)
		ADD_BOOL(bTakeDamageOnEncroachment, 712, 0x8)
		ADD_BOOL(bResetDOEWhenAsleep, 712, 0x4)
		ADD_BOOL(bDamageOnEncroachment, 712, 0x2)
		ADD_BOOL(bHasHealth, 712, 0x1)
		bool OnEncroach(class Actor* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34950);
			byte params[8] = { NULL };
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void OnBreakApart()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34952);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TakeDamage(int Damage, class Controller* EventInstigator, Vector HitLocation, Vector Momentum, ScriptClass* DamageType, Actor::TraceHitInfo HitInfo, class Actor* DamageCauser)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34968);
			byte params[68] = { NULL };
			*(int*)params = Damage;
			*(class Controller**)&params[4] = EventInstigator;
			*(Vector*)&params[8] = HitLocation;
			*(Vector*)&params[20] = Momentum;
			*(ScriptClass**)&params[32] = DamageType;
			*(Actor::TraceHitInfo*)&params[36] = HitInfo;
			*(class Actor**)&params[64] = DamageCauser;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool EncroachingOn(class Actor* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34976);
			byte params[8] = { NULL };
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void BreakApart()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34979);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34980);
			byte params[8] = { NULL };
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
