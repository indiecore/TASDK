#pragma once
#include "Engine__Volume.h"
#include "Engine__Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ColorScaleVolume." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.ColorScaleVolume." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ColorScaleVolume : public Volume
	{
	public:
		ADD_VAR(::FloatProperty, InterpTime, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, ColorScale, 0xFFFFFFFF
		// Here lies the not-yet-implemented method 'Touch'
		// Here lies the not-yet-implemented method 'UnTouch'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
