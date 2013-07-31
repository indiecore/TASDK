#pragma once
#include "TribesGame.TrVGSCommandList.h"
#include "Engine.SequenceAction.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class TrSeqAct_PlayVGSCommand : public SequenceAction
	{
	public:
		ADD_STRUCT(ScriptString*, CommandInstigatorName, 236)
		ADD_STRUCT(TrVGSCommandList::VGSCommandType, VGSCommand, 232)
	};
}
#undef ADD_STRUCT
