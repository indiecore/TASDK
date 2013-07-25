#pragma once
#include "Core__Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.LocalMessage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.LocalMessage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class LocalMessage : public Object
	{
	public:
		ADD_VAR(::BoolProperty, bBeep, 0x10)
		ADD_VAR(::FloatProperty, Lifetime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bIsSpecial, 0x1)
		ADD_VAR(::BoolProperty, bIsUnique, 0x2)
		ADD_VAR(::BoolProperty, bCountInstances, 0x20)
		ADD_VAR(::BoolProperty, bIsPartiallyUnique, 0x4)
		ADD_VAR(::IntProperty, FontSize, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, PosY, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'DrawColor'!
		ADD_VAR(::BoolProperty, bIsConsoleMessage, 0x8)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
