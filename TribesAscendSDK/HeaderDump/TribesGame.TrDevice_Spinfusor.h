#pragma once
#include "TribesGame.TrDevice.h"
#include "Engine.SoundCue.h"
#include "Engine.SkelControlSingleBone.h"
#include "TribesGame.TrSkelControl_SpinControl.h"
#include "Engine.AnimNodeSequence.h"
#include "Core.Object.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class TrDevice_Spinfusor : public TrDevice
	{
	public:
		ADD_OBJECT(SoundCue, m_SpinfusorIdleSound, 2156)
		ADD_OBJECT(SkelControlSingleBone, m_DiscVisibilityControl, 2152)
		ADD_OBJECT(TrSkelControl_SpinControl, m_DiscSpinControl, 2148)
		void UpdateReplicatedCarriedAmmo()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(81433);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostInitAnimTree(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelComp)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(81434);
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = SkelComp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnAnimPlay(class AnimNodeSequence* SeqNode)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(81436);
			byte params[4] = { NULL };
			*(class AnimNodeSequence**)params = SeqNode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnAnimEnd(class AnimNodeSequence* SeqNode, float PlayedTime, float ExcessTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(81438);
			byte params[12] = { NULL };
			*(class AnimNodeSequence**)params = SeqNode;
			*(float*)&params[4] = PlayedTime;
			*(float*)&params[8] = ExcessTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayFireEffects(byte FireModeNum, Vector HitLocation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(81442);
			byte params[13] = { NULL };
			*params = FireModeNum;
			*(Vector*)&params[4] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayWeaponEquip()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(81445);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetDiscVisibility(bool bVisible)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(81446);
			byte params[4] = { NULL };
			*(bool*)params = bVisible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetDiscSpinning(bool bEnabled)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(81448);
			byte params[4] = { NULL };
			*(bool*)params = bEnabled;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayWeaponPutDown()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(81451);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PutDownFast()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(81452);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnSwitchAwayFromWeapon()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(81453);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_OBJECT
