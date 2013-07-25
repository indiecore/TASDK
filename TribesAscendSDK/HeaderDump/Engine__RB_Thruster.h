#pragma once
#include "Engine__RigidBodyBase.h"
#include "Engine__SeqAct_Toggle.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.RB_Thruster." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class RB_Thruster : public RigidBodyBase
	{
	public:
		ADD_VAR(::FloatProperty, ThrustStrength, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bThrustEnabled, 0x1)
		// Here lies the not-yet-implemented method 'OnToggle'
	};
}
#undef ADD_VAR
