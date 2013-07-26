#pragma once
#include "Engine.MaterialInstanceConstant.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Landscape.LandscapeLayerInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Landscape.LandscapeLayerInfo." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class LandscapeLayerInfo
	{
	public:
		ADD_OBJECT(MaterialInstanceConstant, ThumbnailMIC)
		ADD_VAR(::BoolProperty, bNoWeightBlend, 0x1)
		ADD_VAR(::FloatProperty, Hardness, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, LayerName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
