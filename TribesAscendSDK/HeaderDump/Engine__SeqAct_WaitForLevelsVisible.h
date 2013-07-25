#pragma once
#include "Engine__SeqAct_Latent.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqAct_WaitForLevelsVisible." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqAct_WaitForLevelsVisible : public SeqAct_Latent
	{
	public:
		ADD_VAR(::BoolProperty, bShouldBlockOnLoad, 0x1)
	};
}
#undef ADD_VAR
