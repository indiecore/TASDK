#pragma once
#include "TribesGame.TrAnimNodeBlendList.h"
#include "GameFramework.GameSkelCtrl_Recoil.h"
#include "TribesGame.TrPawn.h"
#include "TribesGame.TrSkelControl_SpinControl.h"
#include "TribesGame.TrDevice.h"
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
	class TrAnimNodeBlendByDeviceAnim : public TrAnimNodeBlendList
	{
	public:
		class DeviceNodeCameraAnimation
		{
		public:
			ADD_BOOL(bRandomStartTime, 28, 0x2)
			ADD_BOOL(bLoop, 28, 0x1)
			ADD_STRUCT(float, BlendOutTime, 24)
			ADD_STRUCT(float, BlendInTime, 20)
			ADD_STRUCT(float, Scale, 16)
			ADD_STRUCT(float, Rate, 12)
			ADD_OBJECT(CameraAnimInst, CameraAnimInstance, 8)
			ADD_OBJECT(CameraAnim, CameraAnim, 4)
			ADD_STRUCT(int, ChildIndex, 0)
		};
		ADD_STRUCT(ScriptArray<ScriptName>, m_nmRecoilControlNames, 312)
		ADD_STRUCT(ScriptArray<class GameSkelCtrl_Recoil*>, m_RecoilControls, 324)
		ADD_STRUCT(ScriptArray<class GameSkelCtrl_Recoil*>, m_TinyWeaponsRecoilControls, 336)
		ADD_STRUCT(ScriptArray<TrAnimNodeBlendByDeviceAnim::DeviceNodeCameraAnimation>, m_CameraAnimations, 408)
		ADD_STRUCT(int, m_nSocketIndex, 404)
		ADD_OBJECT(TrAnimNodeBlendByDeviceAnim, m_SecondaryDeviceBlendNode, 400)
		ADD_STRUCT(ScriptName, m_SecondaryDeviceBlendNodeName, 392)
		ADD_STRUCT(ScriptName, m_StandardReloadAnimName, 384)
		ADD_STRUCT(ScriptName, m_ReloadPartialClipAnimName, 376)
		ADD_STRUCT(ScriptName, m_StandardFireAnimName, 368)
		ADD_STRUCT(ScriptName, m_DryFireAnimName, 360)
		ADD_STRUCT(ScriptName, m_FireFinalRoundAnimName, 352)
		ADD_BOOL(m_bScalePutawayRetrieveAnims, 348, 0x8)
		ADD_BOOL(m_bScaleFireByRefireTime, 348, 0x4)
		ADD_BOOL(m_bPlayFire, 348, 0x2)
		ADD_BOOL(m_bPlayBuildUp, 348, 0x1)
		ADD_OBJECT(TrSkelControl_SpinControl, m_BuildupFireSpinControl, 308)
		ADD_STRUCT(ScriptName, m_nmBuildupFireSpinControlName, 300)
		ADD_OBJECT(TrDevice, m_Device, 296)
		ADD_OBJECT(TrPawn, m_TrPawn, 292)
		void StopAnim()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAnimNodeBlendByDeviceAnim.StopAnim");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetActiveChild(int ChildIndex, float BlendTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAnimNodeBlendByDeviceAnim.SetActiveChild");
			byte params[8] = { NULL };
			*(int*)&params[0] = ChildIndex;
			*(float*)&params[4] = BlendTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayIdle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAnimNodeBlendByDeviceAnim.PlayIdle");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayAltIdle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAnimNodeBlendByDeviceAnim.PlayAltIdle");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayBuildup(float BuildupTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAnimNodeBlendByDeviceAnim.PlayBuildup");
			byte params[4] = { NULL };
			*(float*)&params[0] = BuildupTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayFire(int SocketIndex, float RefireTime, int RoundsRemainingInClip)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAnimNodeBlendByDeviceAnim.PlayFire");
			byte params[12] = { NULL };
			*(int*)&params[0] = SocketIndex;
			*(float*)&params[4] = RefireTime;
			*(int*)&params[8] = RoundsRemainingInClip;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayPutaway(float PutAwayTime, float ForcedRateBuff)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAnimNodeBlendByDeviceAnim.PlayPutaway");
			byte params[8] = { NULL };
			*(float*)&params[0] = PutAwayTime;
			*(float*)&params[4] = ForcedRateBuff;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayRetrieve(float RetrieveTime, float ForcedRateBuff)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAnimNodeBlendByDeviceAnim.PlayRetrieve");
			byte params[8] = { NULL };
			*(float*)&params[0] = RetrieveTime;
			*(float*)&params[4] = ForcedRateBuff;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayReload(float ReloadTime, int RoundsRemainingInClip)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAnimNodeBlendByDeviceAnim.PlayReload");
			byte params[8] = { NULL };
			*(float*)&params[0] = ReloadTime;
			*(int*)&params[4] = RoundsRemainingInClip;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayOffhand(float Rate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAnimNodeBlendByDeviceAnim.PlayOffhand");
			byte params[4] = { NULL };
			*(float*)&params[0] = Rate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnStopFire()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAnimNodeBlendByDeviceAnim.OnStopFire");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayDryFire()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAnimNodeBlendByDeviceAnim.PlayDryFire");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayQuickRetrieve()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAnimNodeBlendByDeviceAnim.PlayQuickRetrieve");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
