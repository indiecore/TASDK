#pragma once
#include "TribesGame.TrCollisionProxy.h"
#include "TribesGame.TrHelpTextManager.h"
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
	class TrCollisionProxy_HelpText : public TrCollisionProxy
	{
	public:
		ADD_STRUCT(TrHelpTextManager::EHelpTextType, m_HelpTextType, 496)
		ADD_OBJECT(Pawn, m_LocalPawn, 504)
		ADD_STRUCT(float, m_fHelpTextRemovalTime, 500)
		bool ShouldShowHelpText_Delegate(TrHelpTextManager::EHelpTextType HelpTextType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCollisionProxy_HelpText.ShouldShowHelpText_Delegate");
			byte params[5] = { NULL };
			*(TrHelpTextManager::EHelpTextType*)&params[0] = HelpTextType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void OnPawnAdded(class Pawn* aPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCollisionProxy_HelpText.OnPawnAdded");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = aPawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = aPawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
