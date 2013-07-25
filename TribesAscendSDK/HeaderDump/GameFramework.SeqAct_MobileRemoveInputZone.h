#pragma once
#include "Engine.SequenceAction.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.SeqAct_MobileRemoveInputZone." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqAct_MobileRemoveInputZone : public SequenceAction
	{
	public:
		ADD_VAR(::StrProperty, ZoneName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
