#pragma once
#include "UTGame__UTMutator.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTMutator_FriendlyFire." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UTMutator_FriendlyFire : public UTMutator
	{
	public:
		ADD_VAR(::FloatProperty, FriendlyFireScale, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
