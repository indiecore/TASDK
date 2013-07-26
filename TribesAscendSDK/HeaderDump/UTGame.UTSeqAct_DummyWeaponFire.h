#pragma once
#include "UTGame.UTDummyPawn.h"
#include "Engine.Actor.h"
#include "Engine.SeqAct_Latent.h"
#include "Core.Object.Rotator.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTSeqAct_DummyWeaponFire." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UTGame.UTSeqAct_DummyWeaponFire." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTSeqAct_DummyWeaponFire." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTSeqAct_DummyWeaponFire : public SeqAct_Latent
	{
	public:
		ADD_VAR(::BoolProperty, bSuppressSounds, 0x1)
		ADD_OBJECT(Actor, Target)
		ADD_STRUCT(::RotatorProperty, MaxSpread, 0xFFFFFFFF)
		ADD_OBJECT(Actor, Origin)
		ADD_VAR(::IntProperty, ShotsFired, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, FireMode, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, WeaponClass)
		ADD_VAR(::IntProperty, ShotsToFire, 0xFFFFFFFF)
		ADD_OBJECT(UTDummyPawn, DummyPawn)
		void Activated()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSeqAct_DummyWeaponFire.Activated");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NotifyDummyFire()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSeqAct_DummyWeaponFire.NotifyDummyFire");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool Update(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSeqAct_DummyWeaponFire.Update");
			byte* params = (byte*)malloc(8);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
