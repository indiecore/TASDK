#pragma once
#include "TribesGame.TrCollisionProxy.h"
#include "Engine.Pawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrCollisionProxy_HelpText." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrCollisionProxy_HelpText." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrCollisionProxy_HelpText : public TrCollisionProxy
	{
	public:
		ADD_VAR(::ByteProperty, m_HelpTextType, 0xFFFFFFFF)
		ADD_OBJECT(Pawn, m_LocalPawn)
		ADD_VAR(::FloatProperty, m_fHelpTextRemovalTime, 0xFFFFFFFF)
		bool ShouldShowHelpText_Delegate(byte HelpTextType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCollisionProxy_HelpText.ShouldShowHelpText_Delegate");
			byte* params = (byte*)malloc(5);
			*params = HelpTextType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void OnPawnAdded(class Pawn* aPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCollisionProxy_HelpText.OnPawnAdded");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = aPawn;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RequestHelpText()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCollisionProxy_HelpText.RequestHelpText");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TryTraceAgainTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCollisionProxy_HelpText.TryTraceAgainTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnPawnRemoved(class Pawn* aPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCollisionProxy_HelpText.OnPawnRemoved");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = aPawn;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
