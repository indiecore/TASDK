#pragma once
#include "UTGame.UTWeaponPawn.h"
#include "Engine.SoundCue.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrWeaponPawn." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrWeaponPawn." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrWeaponPawn : public UTWeaponPawn
	{
	public:
		ADD_VAR(::FloatProperty, m_fCurrentAccuracy, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, r_nFlashReload, 0xFFFFFFFF)
		ADD_OBJECT(SoundCue, r_scFiringLoop)
		ADD_VAR(::BoolProperty, r_bFiringLoopSound, 0x1)
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrWeaponPawn.ReplicatedEvent");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayReload()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrWeaponPawn.PlayReload");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ProcessViewRotation(float DeltaTime, Rotator& out_ViewRotation, Rotator& out_DeltaRot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrWeaponPawn.ProcessViewRotation");
			byte* params = (byte*)malloc(28);
			*(float*)params = DeltaTime;
			*(Rotator*)(params + 4) = out_ViewRotation;
			*(Rotator*)(params + 16) = out_DeltaRot;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_ViewRotation = *(Rotator*)(params + 4);
			out_DeltaRot = *(Rotator*)(params + 16);
			free(params);
		}
		void ClientPlayLoopSound()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrWeaponPawn.ClientPlayLoopSound");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayLoopingSound(class SoundCue* InSound, bool Play)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrWeaponPawn.PlayLoopingSound");
			byte* params = (byte*)malloc(8);
			*(class SoundCue**)params = InSound;
			*(bool*)(params + 4) = Play;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
