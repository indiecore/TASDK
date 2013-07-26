#pragma once
#include "Engine.K2Input.h"
#include "Core.Object.Rotator.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.K2Input_Rotator." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class K2Input_Rotator : public K2Input
	{
	public:
		ADD_STRUCT(::RotatorProperty, DefaultRotator, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT
