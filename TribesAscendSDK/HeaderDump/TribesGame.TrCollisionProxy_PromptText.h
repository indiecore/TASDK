#pragma once
#include "TribesGame.TrCollisionProxy.h"
#include "Engine.Pawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrCollisionProxy_PromptText." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrCollisionProxy_PromptText." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrCollisionProxy_PromptText : public TrCollisionProxy
	{
	public:
		ADD_VAR(::FloatProperty, m_fPromptTextRemovalTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nPromptMessageIndex, 0xFFFFFFFF)
		ADD_OBJECT(Pawn, m_LocalPawn)
		ADD_VAR(::StrProperty, m_LastUpgradeMsg, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nLastUpgradeLevel, 0xFFFFFFFF)
		void OnPawnAdded(class Pawn* aPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCollisionProxy_PromptText.OnPawnAdded");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = aPawn;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RequestPromptText()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCollisionProxy_PromptText.RequestPromptText");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CheckForUpgradeLevel()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCollisionProxy_PromptText.CheckForUpgradeLevel");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TryTraceAgainTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCollisionProxy_PromptText.TryTraceAgainTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnPawnRemoved(class Pawn* aPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCollisionProxy_PromptText.OnPawnRemoved");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = aPawn;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
