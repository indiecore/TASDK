#pragma once
#include "TribesGame__TrCallIn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrCallIn_Support." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrCallIn_Support : public TrCallIn
	{
	public:
		ADD_VAR(::IntProperty, MaxDeployedLimit, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
