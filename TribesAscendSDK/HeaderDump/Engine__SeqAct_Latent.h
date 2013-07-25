#pragma once
#include "Engine__SequenceAction.h"
#include "Engine__Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqAct_Latent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqAct_Latent : public SequenceAction
	{
	public:
		ADD_VAR(::BoolProperty, bAborted, 0x1)
		// Here lies the not-yet-implemented method 'AbortFor'
		// Here lies the not-yet-implemented method 'Update'
	};
}
#undef ADD_VAR
