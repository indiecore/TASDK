#pragma once
#include "Engine.SequenceAction.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTSeqAct_AIFreeze." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UTSeqAct_AIFreeze : public SequenceAction
	{
	public:
		ADD_VAR(::BoolProperty, bAllowWeaponFiring, 0x1)
	};
}
#undef ADD_VAR
