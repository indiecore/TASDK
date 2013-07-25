#pragma once
#include "Core__Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.InterpGroup." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.InterpGroup." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class InterpGroup : public Object
	{
	public:
		ADD_VAR(::BoolProperty, bIsSelected, 0x10)
		ADD_VAR(::BoolProperty, bIsParented, 0x8)
		ADD_VAR(::BoolProperty, bIsFolder, 0x4)
		ADD_VAR(::BoolProperty, bVisible, 0x2)
		ADD_VAR(::BoolProperty, bCollapsed, 0x1)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'GroupColor'!
		ADD_VAR(::NameProperty, GroupName, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTable_FInterpEdInputInterface'!
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
