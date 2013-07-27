#pragma once
#include "TribesGame.TrAnimNodeBlendList.h"
#include "GameFramework.GameSkelCtrl_Recoil.h"
#include "TribesGame.TrPawn.h"
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
	class TrAnimNodeBlendBy3pDevice : public TrAnimNodeBlendList
	{
	public:
		ADD_STRUCT(ScriptArray<ScriptName>, m_nmRecoilControlNames, 296)
		ADD_STRUCT(ScriptArray<class GameSkelCtrl_Recoil*>, m_RecoilControls, 308)
		ADD_STRUCT(ScriptName, m_StandardReloadAnimName, 352)
		ADD_STRUCT(ScriptName, m_SkiingReloadName, 344)
		ADD_STRUCT(ScriptName, m_StandardFireAnimName, 336)
		ADD_STRUCT(ScriptName, m_SkiingFireName, 328)
		ADD_STRUCT(float, m_fRefireTimePreview, 324)
		ADD_BOOL(m_bCurrentDeviceSupportsAltSkiReloadAnims, 320, 0x10)
		ADD_BOOL(m_bCurrentDeviceSupportsAltSkiFireAnims, 320, 0x8)
		ADD_BOOL(m_bScalePutawayRetrieveAnims, 320, 0x4)
		ADD_BOOL(m_bFirePreview, 320, 0x2)
		ADD_BOOL(m_bScaleFireByRefireTime, 320, 0x1)
		ADD_OBJECT(TrPawn, m_TrPawn, 292)
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
			byte params[4] = { NULL };
			*(float*)&params[0] = RefireTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayPutaway(float PutAwayTime, float ForcedRateBuff)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAnimNodeBlendBy3pDevice.PlayPutaway");
			byte params[8] = { NULL };
			*(float*)&params[0] = PutAwayTime;
			*(float*)&params[4] = ForcedRateBuff;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayRetrieve(float RetrieveTime, float ForcedRateBuff)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAnimNodeBlendBy3pDevice.PlayRetrieve");
			byte params[8] = { NULL };
			*(float*)&params[0] = RetrieveTime;
			*(float*)&params[4] = ForcedRateBuff;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayReload(float ReloadTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAnimNodeBlendBy3pDevice.PlayReload");
			byte params[4] = { NULL };
			*(float*)&params[0] = ReloadTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayOffhand(ScriptName OffhandAnimName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAnimNodeBlendBy3pDevice.PlayOffhand");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = OffhandAnimName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
