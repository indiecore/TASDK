#pragma once
#include "Engine.Actor.h"
#include "Engine.Model.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.Brush." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.Brush." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.Brush." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class Brush : public Actor
	{
	public:
		ADD_OBJECT(Model, Brush)
		ADD_VAR(::BoolProperty, bPlaceableFromClassBrowser, 0x4)
		ADD_VAR(::BoolProperty, bSolidWhenSelected, 0x2)
		ADD_VAR(::BoolProperty, bColored, 0x1)
		ADD_VAR(::IntProperty, PolyFlags, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'BrushColor'!
		ADD_VAR(::ByteProperty, CsgOper, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
