#pragma once
#include "Engine__Info.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.Route." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.Route." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class Route : public Info
	{
	public:
		ADD_VAR(::ByteProperty, RouteType, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTable_IEditorLinkSelectionInterface'!
		ADD_VAR(::FloatProperty, FudgeFactor, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, RouteIndexOffset, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
