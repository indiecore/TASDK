#pragma once
#include "TribesGame.TrAnimNodeBlendList.h"
#include "TribesGame.TrPawn.h"
#include "TribesGame.TrSkelControl_SpinControl.h"
#include "TribesGame.TrDevice.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrAnimNodeBlendByDeviceAnim." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrAnimNodeBlendByDeviceAnim." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrAnimNodeBlendByDeviceAnim : public TrAnimNodeBlendList
	{
	public:
		ADD_VAR(::IntProperty, m_nSocketIndex, 0xFFFFFFFF)
		ADD_OBJECT(TrAnimNodeBlendByDeviceAnim, m_SecondaryDeviceBlendNode)
		ADD_VAR(::NameProperty, m_SecondaryDeviceBlendNodeName, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, m_StandardReloadAnimName, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, m_ReloadPartialClipAnimName, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, m_StandardFireAnimName, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, m_DryFireAnimName, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, m_FireFinalRoundAnimName, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bScalePutawayRetrieveAnims, 0x8)
		ADD_VAR(::BoolProperty, m_bScaleFireByRefireTime, 0x4)
		ADD_VAR(::BoolProperty, m_bPlayFire, 0x2)
		ADD_VAR(::BoolProperty, m_bPlayBuildUp, 0x1)
		ADD_OBJECT(TrSkelControl_SpinControl, m_BuildupFireSpinControl)
		ADD_VAR(::NameProperty, m_nmBuildupFireSpinControlName, 0xFFFFFFFF)
		ADD_OBJECT(TrDevice, m_Device)
		ADD_OBJECT(TrPawn, m_TrPawn)
		void StopAnim()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAnimNodeBlendByDeviceAnim.StopAnim");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetActiveChild(int ChildIndex, float BlendTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAnimNodeBlendByDeviceAnim.SetActiveChild");
			byte* params = (byte*)malloc(8);
			*(int*)params = ChildIndex;
			*(float*)(params + 4) = BlendTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(4);
			*(float*)params = BuildupTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayFire(int SocketIndex, float RefireTime, int RoundsRemainingInClip)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAnimNodeBlendByDeviceAnim.PlayFire");
			byte* params = (byte*)malloc(12);
			*(int*)params = SocketIndex;
			*(float*)(params + 4) = RefireTime;
			*(int*)(params + 8) = RoundsRemainingInClip;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayPutaway(float PutAwayTime, float ForcedRateBuff)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAnimNodeBlendByDeviceAnim.PlayPutaway");
			byte* params = (byte*)malloc(8);
			*(float*)params = PutAwayTime;
			*(float*)(params + 4) = ForcedRateBuff;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayRetrieve(float RetrieveTime, float ForcedRateBuff)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAnimNodeBlendByDeviceAnim.PlayRetrieve");
			byte* params = (byte*)malloc(8);
			*(float*)params = RetrieveTime;
			*(float*)(params + 4) = ForcedRateBuff;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayReload(float ReloadTime, int RoundsRemainingInClip)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAnimNodeBlendByDeviceAnim.PlayReload");
			byte* params = (byte*)malloc(8);
			*(float*)params = ReloadTime;
			*(int*)(params + 4) = RoundsRemainingInClip;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayOffhand(float Rate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAnimNodeBlendByDeviceAnim.PlayOffhand");
			byte* params = (byte*)malloc(4);
			*(float*)params = Rate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
#undef ADD_VAR
#undef ADD_OBJECT
