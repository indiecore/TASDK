#pragma once
#include "Engine__SeqAct_Latent.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqAct_LevelStreamingBase." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqAct_LevelStreamingBase : public SeqAct_Latent
	{
	public:
		ADD_VAR(::BoolProperty, bShouldBlockOnLoad, 0x2)
		ADD_VAR(::BoolProperty, bMakeVisibleAfterLoad, 0x1)
	};
}
#undef ADD_VAR
