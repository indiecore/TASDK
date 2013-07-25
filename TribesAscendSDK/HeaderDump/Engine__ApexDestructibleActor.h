#pragma once
#include "Engine__Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ApexDestructibleActor." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ApexDestructibleActor : public Actor
	{
	public:
		ADD_VAR(::BoolProperty, bFractureMaterialOverride, 0x1)
	};
}
#undef ADD_VAR
