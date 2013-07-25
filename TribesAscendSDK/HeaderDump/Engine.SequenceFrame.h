#pragma once
#include "Engine.Texture2D.h"
#include "Engine.SequenceObject.h"
#include "Engine.Material.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SequenceFrame." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.SequenceFrame." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.SequenceFrame." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SequenceFrame : public SequenceObject
	{
	public:
		ADD_OBJECT(Material, FillMaterial)
		ADD_OBJECT(Texture2D, FillTexture)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'FillColor'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'BorderColor'!
		ADD_VAR(::BoolProperty, bTileFill, 0x4)
		ADD_VAR(::BoolProperty, bFilled, 0x2)
		ADD_VAR(::BoolProperty, bDrawBox, 0x1)
		ADD_VAR(::IntProperty, BorderWidth, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SizeY, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SizeX, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
