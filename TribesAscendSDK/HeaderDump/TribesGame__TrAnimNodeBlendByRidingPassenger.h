#pragma once
#include "TribesGame__TrAnimNodeBlendList.h"
#include "TribesGame__TrPawn.h"
#include "Engine__AnimNodeSequence.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrAnimNodeBlendByRidingPassenger." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrAnimNodeBlendByRidingPassenger." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrAnimNodeBlendByRidingPassenger : public TrAnimNodeBlendList
	{
	public:
		ADD_OBJECT(AnimNodeSequence, m_FireAnimSeqNode)
		ADD_VAR(::NameProperty, m_nmFireAnimSeqNodeName, 0xFFFFFFFF)
		ADD_OBJECT(TrPawn, m_TrPawn)
		void PlayIdle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAnimNodeBlendByRidingPassenger.PlayIdle");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayFire(float RefireTime, ScriptName FireAnimName, float ReloadTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAnimNodeBlendByRidingPassenger.PlayFire");
			byte* params = (byte*)malloc(16);
			*(float*)params = RefireTime;
			*(ScriptName*)(params + 4) = FireAnimName;
			*(float*)(params + 12) = ReloadTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayReload(float ReloadTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAnimNodeBlendByRidingPassenger.PlayReload");
			byte* params = (byte*)malloc(4);
			*(float*)params = ReloadTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayOffhand()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAnimNodeBlendByRidingPassenger.PlayOffhand");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
