#pragma once
#include "TribesGame__TrPlayerController.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrConsolePlayerController." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrConsolePlayerController : public TrPlayerController
	{
	public:
		ADD_VAR(::BoolProperty, bDebugTargetAdhesion, 0x2)
		ADD_VAR(::BoolProperty, bTargetAdhesionEnabled, 0x1)
	};
}
#undef ADD_VAR
