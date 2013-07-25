#pragma once
#include "TribesGame__TrAnimNodeBlendList.h"
#include "TribesGame__TrPawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrAnimNodeBlendBy3pDevice." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrAnimNodeBlendBy3pDevice." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrAnimNodeBlendBy3pDevice : public TrAnimNodeBlendList
	{
	public:
		ADD_VAR(::NameProperty, m_StandardReloadAnimName, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, m_SkiingReloadName, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, m_StandardFireAnimName, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, m_SkiingFireName, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fRefireTimePreview, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bCurrentDeviceSupportsAltSkiReloadAnims, 0x10)
		ADD_VAR(::BoolProperty, m_bCurrentDeviceSupportsAltSkiFireAnims, 0x8)
		ADD_VAR(::BoolProperty, m_bScalePutawayRetrieveAnims, 0x4)
		ADD_VAR(::BoolProperty, m_bFirePreview, 0x2)
		ADD_VAR(::BoolProperty, m_bScaleFireByRefireTime, 0x1)
		ADD_OBJECT(TrPawn, m_TrPawn)
		void PlayIdle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAnimNodeBlendBy3pDevice.PlayIdle");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayBuildup()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAnimNodeBlendBy3pDevice.PlayBuildup");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayFire(float RefireTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAnimNodeBlendBy3pDevice.PlayFire");
			byte* params = (byte*)malloc(4);
			*(float*)params = RefireTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayPutaway(float PutAwayTime, float ForcedRateBuff)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAnimNodeBlendBy3pDevice.PlayPutaway");
			byte* params = (byte*)malloc(8);
			*(float*)params = PutAwayTime;
			*(float*)(params + 4) = ForcedRateBuff;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayRetrieve(float RetrieveTime, float ForcedRateBuff)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAnimNodeBlendBy3pDevice.PlayRetrieve");
			byte* params = (byte*)malloc(8);
			*(float*)params = RetrieveTime;
			*(float*)(params + 4) = ForcedRateBuff;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayReload(float ReloadTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAnimNodeBlendBy3pDevice.PlayReload");
			byte* params = (byte*)malloc(4);
			*(float*)params = ReloadTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayOffhand(ScriptName OffhandAnimName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAnimNodeBlendBy3pDevice.PlayOffhand");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = OffhandAnimName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
