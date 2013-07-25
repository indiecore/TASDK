#pragma once
#include "Core__Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.Canvas." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.Canvas." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.Canvas." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class Canvas : public Object
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'DrawColor'!
		ADD_OBJECT(Font, Font)
		ADD_OBJECT(Texture2D, DefaultTexture)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Plane' for the property named 'ColorModulate'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'SceneView'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'Canvas'!
		ADD_VAR(::IntProperty, SizeY, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SizeX, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bNoSmooth, 0x2)
		ADD_VAR(::BoolProperty, bCenter, 0x1)
		ADD_VAR(::FloatProperty, CurYL, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CurZ, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CurY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CurX, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ClipY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ClipX, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OrgY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OrgX, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
