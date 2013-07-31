#pragma once
#include "TribesGame.TrDevice.h"
#include "Engine.SoundCue.h"
#include "TribesGame.TrProj_RemoteArxBuster.h"
#include "Engine.AnimNodeAdditiveBlending.h"
#include "Engine.SkelControlSingleBone.h"
#include "Engine.AnimNodeSequence.h"
#include "Engine.Projectile.h"
#include "TribesGame.TrProjectile.h"
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
	class TrDevice_RemoteArxBuster : public TrDevice
	{
	public:
		ADD_STRUCT(ScriptArray<class TrProj_RemoteArxBuster*>, RemoteArxRounds, 2160)
		ADD_OBJECT(SoundCue, m_ArxIdleSound, 2176)
		ADD_OBJECT(AnimNodeAdditiveBlending, DetReadyAdditiveAnimNode, 2172)
		ADD_BOOL(r_bIsLeftArmVisible, 2156, 0x1)
		ADD_OBJECT(SkelControlSingleBone, DetonatorChild, 2152)
		ADD_OBJECT(SkelControlSingleBone, DetonatorControl, 2148)
		void SetArxIdle(bool bEnabled)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(85767);
			byte params[4] = { NULL };
			*(bool*)params = bEnabled;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(85770);
			byte params[8] = { NULL };
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetLeftArmVisible(bool bVisible)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(85772);
			byte params[4] = { NULL };
			*(bool*)params = bVisible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DetPoseActive(bool bActive)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(85774);
			byte params[4] = { NULL };
			*(bool*)params = bActive;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostInitAnimTree(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelComp)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(85776);
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = SkelComp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int AddAmmo(int Amount)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(85778);
			byte params[8] = { NULL };
			*(int*)params = Amount;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		void PerformInactiveReload()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(85781);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RequestReload()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(85782);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool CanClientRequestReloadNow()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(85783);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void StartFire(byte FireModeNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(85785);
			byte params[1] = { NULL };
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FireAmmunition()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(85788);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class Projectile* ProjectileFire()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(85789);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Projectile**)params;
		}
		void ActivateRemoteRounds(bool bDoNoDamage)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(85793);
			byte params[4] = { NULL };
			*(bool*)params = bDoNoDamage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void HideArmTimer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(85797);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(85798);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnRemoteProjectileDestroyedByOther(class TrProjectile* DestroyedProjectile)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(85809);
			byte params[4] = { NULL };
			*(class TrProjectile**)params = DestroyedProjectile;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnAnimPlay(class AnimNodeSequence* SeqNode)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(85814);
			byte params[4] = { NULL };
			*(class AnimNodeSequence**)params = SeqNode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnAnimEnd(class AnimNodeSequence* SeqNode, float PlayedTime, float ExcessTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(85816);
			byte params[12] = { NULL };
			*(class AnimNodeSequence**)params = SeqNode;
			*(float*)&params[4] = PlayedTime;
			*(float*)&params[8] = ExcessTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnPlayRetrieveAnim()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(85820);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayWeaponEquip()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(85821);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayWeaponPutDown()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(85822);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PutDownFast()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(85823);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnSwitchAwayFromWeapon()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(85824);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
