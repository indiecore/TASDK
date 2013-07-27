#pragma once
#include "UTGame.UTDummyPawn.h"
#include "Core.Object.h"
#include "Engine.Actor.h"
#include "Engine.SeqAct_Latent.h"
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
	class UTSeqAct_DummyWeaponFire : public SeqAct_Latent
	{
	public:
		ADD_BOOL(bSuppressSounds, 284, 0x1)
		ADD_OBJECT(Actor, Target, 268)
		ADD_STRUCT(Rotator, MaxSpread, 272)
		ADD_OBJECT(Actor, Origin, 264)
		ADD_STRUCT(int, ShotsFired, 288)
		ADD_STRUCT(byte, FireMode, 260)
		ADD_OBJECT(ScriptClass, WeaponClass, 256)
		ADD_STRUCT(int, ShotsToFire, 252)
		ADD_OBJECT(UTDummyPawn, DummyPawn, 248)
		void Activated()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49086);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NotifyDummyFire()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49088);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool Update(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49089);
			byte params[8] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
