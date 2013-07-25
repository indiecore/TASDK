#pragma once
#include "UTGame__UTMutator.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTMutator_SpeedFreak." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UTMutator_SpeedFreak : public UTMutator
	{
	public:
		ADD_VAR(::FloatProperty, GameSpeed, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'InitMutator'
	};
}
#undef ADD_VAR
