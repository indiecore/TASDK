#pragma once
#include "TribesGame.TrDevice.h"
#include "Engine.SoundCue.h"
#include "Engine.AnimNodeAdditiveBlending.h"
#include "Engine.SkelControlSingleBone.h"
#include "Engine.AnimNodeSequence.h"
#include "Engine.Projectile.h"
#include "TribesGame.TrProjectile.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrDevice_RemoteArxBuster." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrDevice_RemoteArxBuster." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrDevice_RemoteArxBuster : public TrDevice
	{
	public:
		ADD_OBJECT(SoundCue, m_ArxIdleSound)
		ADD_OBJECT(AnimNodeAdditiveBlending, DetReadyAdditiveAnimNode)
		ADD_VAR(::BoolProperty, r_bIsLeftArmVisible, 0x1)
		ADD_OBJECT(SkelControlSingleBone, DetonatorChild)
		ADD_OBJECT(SkelControlSingleBone, DetonatorControl)
		void SetArxIdle(bool bEnabled)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_RemoteArxBuster.SetArxIdle");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bEnabled;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_RemoteArxBuster.ReplicatedEvent");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetLeftArmVisible(bool bVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_RemoteArxBuster.SetLeftArmVisible");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bVisible;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DetPoseActive(bool bActive)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_RemoteArxBuster.DetPoseActive");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bActive;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PostInitAnimTree(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelComp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_RemoteArxBuster.PostInitAnimTree");
			byte* params = (byte*)malloc(4);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = SkelComp;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		int AddAmmo(int Amount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_RemoteArxBuster.AddAmmo");
			byte* params = (byte*)malloc(8);
			*(int*)params = Amount;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		void PerformInactiveReload()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_RemoteArxBuster.PerformInactiveReload");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RequestReload()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_RemoteArxBuster.RequestReload");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool CanClientRequestReloadNow()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_RemoteArxBuster.CanClientRequestReloadNow");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void StartFire(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_RemoteArxBuster.StartFire");
			byte* params = (byte*)malloc(1);
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void FireAmmunition()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_RemoteArxBuster.FireAmmunition");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class Projectile* ProjectileFire()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_RemoteArxBuster.ProjectileFire");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Projectile**)params;
			free(params);
			return returnVal;
		}
		void ActivateRemoteRounds(bool bDoNoDamage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_RemoteArxBuster.ActivateRemoteRounds");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bDoNoDamage;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void HideArmTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_RemoteArxBuster.HideArmTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_RemoteArxBuster.Destroyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnRemoteProjectileDestroyedByOther(class TrProjectile* DestroyedProjectile)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_RemoteArxBuster.OnRemoteProjectileDestroyedByOther");
			byte* params = (byte*)malloc(4);
			*(class TrProjectile**)params = DestroyedProjectile;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnAnimPlay(class AnimNodeSequence* SeqNode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_RemoteArxBuster.OnAnimPlay");
			byte* params = (byte*)malloc(4);
			*(class AnimNodeSequence**)params = SeqNode;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnAnimEnd(class AnimNodeSequence* SeqNode, float PlayedTime, float ExcessTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_RemoteArxBuster.OnAnimEnd");
			byte* params = (byte*)malloc(12);
			*(class AnimNodeSequence**)params = SeqNode;
			*(float*)(params + 4) = PlayedTime;
			*(float*)(params + 8) = ExcessTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnPlayRetrieveAnim()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_RemoteArxBuster.OnPlayRetrieveAnim");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayWeaponEquip()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_RemoteArxBuster.PlayWeaponEquip");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayWeaponPutDown()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_RemoteArxBuster.PlayWeaponPutDown");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PutDownFast()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_RemoteArxBuster.PutDownFast");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnSwitchAwayFromWeapon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_RemoteArxBuster.OnSwitchAwayFromWeapon");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
