#pragma once
#include "TribesGame.TrCollisionProxy.h"
#include "Engine.Pawn.h"
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
	class TrCollisionProxy_PromptText : public TrCollisionProxy
	{
	public:
		ADD_STRUCT(float, m_fPromptTextRemovalTime, 496)
		ADD_STRUCT(int, m_nPromptMessageIndex, 500)
		ADD_OBJECT(Pawn, m_LocalPawn, 520)
		ADD_STRUCT(ScriptString*, m_LastUpgradeMsg, 508)
		ADD_STRUCT(int, m_nLastUpgradeLevel, 504)
		void OnPawnAdded(class Pawn* aPawn)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74593);
			byte params[4] = { NULL };
			*(class Pawn**)params = aPawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RequestPromptText()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74596);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CheckForUpgradeLevel()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74601);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TryTraceAgainTimer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74604);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnPawnRemoved(class Pawn* aPawn)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74606);
			byte params[4] = { NULL };
			*(class Pawn**)params = aPawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
