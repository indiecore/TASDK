#pragma once
#include "Engine__SequenceCondition.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqCond_IsLoggedIn." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqCond_IsLoggedIn : public SequenceCondition
	{
	public:
		ADD_VAR(::IntProperty, NumNeededLoggedIn, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'CheckLogins'
	};
}
#undef ADD_VAR
