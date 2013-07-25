#pragma once
#include "Engine__CameraModifier.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.CameraModifier_CameraShake." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class CameraModifier_CameraShake : public CameraModifier
	{
	public:
		ADD_VAR(::FloatProperty, SplitScreenShakeScale, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
