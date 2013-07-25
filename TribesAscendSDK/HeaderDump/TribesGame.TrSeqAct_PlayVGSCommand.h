#pragma once
#include "Engine.SequenceAction.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrSeqAct_PlayVGSCommand." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrSeqAct_PlayVGSCommand : public SequenceAction
	{
	public:
		ADD_VAR(::StrProperty, CommandInstigatorName, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, VGSCommand, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
