#pragma once
#include "Engine.PostProcessEffect.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.BlurEffect." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class BlurEffect : public PostProcessEffect
	{
	public:
		ADD_VAR(::IntProperty, BlurKernelSize, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
