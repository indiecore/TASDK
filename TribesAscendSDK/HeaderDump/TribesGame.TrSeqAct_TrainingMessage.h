#pragma once
#include "Engine.SequenceAction.h"
#include "TribesGame.TrHelpTextManager_Training.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class TrSeqAct_TrainingMessage : public SequenceAction
	{
	public:
		ADD_STRUCT(TrHelpTextManager_Training::EHelpTextTrainingType, m_MessageType, 232)
		void Activated()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(110921);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
