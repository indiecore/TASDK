#pragma once
#include "GameFramework__SeqEvent_HudRender.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.SeqEvent_HudRenderImage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty GameFramework.SeqEvent_HudRenderImage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty GameFramework.SeqEvent_HudRenderImage." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SeqEvent_HudRenderImage : public SeqEvent_HudRender
	{
	public:
		ADD_VAR(::FloatProperty, VL, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, UL, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, V, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, U, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, YL, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, XL, 0xFFFFFFFF)
		ADD_OBJECT(Texture2D, DisplayTexture)
		ADD_STRUCT(::VectorProperty, DisplayLocation, 0xFFFFFFFF
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor' for the property named 'DisplayColor'!
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
