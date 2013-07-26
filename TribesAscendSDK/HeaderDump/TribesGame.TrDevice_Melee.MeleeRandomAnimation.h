#pragma once
#include "Engine.CameraAnim.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TrDevice_Melee.MeleeRandomAnimation." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TrDevice_Melee.MeleeRandomAnimation." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class MeleeRandomAnimation
	{
	public:
		ADD_OBJECT(CameraAnim, FireCameraAnim)
		ADD_VAR(::NameProperty, FireAnimName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
