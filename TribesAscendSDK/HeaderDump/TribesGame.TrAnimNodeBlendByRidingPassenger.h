#pragma once
#include "Engine.AnimNodeSequence.h"
#include "TribesGame.TrAnimNodeBlendList.h"
#include "TribesGame.TrPawn.h"
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
	class TrAnimNodeBlendByRidingPassenger : public TrAnimNodeBlendList
	{
	public:
		ADD_OBJECT(AnimNodeSequence, m_FireAnimSeqNode, 304)
		ADD_STRUCT(ScriptName, m_nmFireAnimSeqNodeName, 296)
		ADD_OBJECT(TrPawn, m_TrPawn, 292)
		void PlayIdle()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(66456);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayFire(float RefireTime, ScriptName FireAnimName, float ReloadTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(66457);
			byte params[16] = { NULL };
			*(float*)params = RefireTime;
			*(ScriptName*)&params[4] = FireAnimName;
			*(float*)&params[12] = ReloadTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayReload(float ReloadTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(66461);
			byte params[4] = { NULL };
			*(float*)params = ReloadTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayOffhand()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(66463);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
