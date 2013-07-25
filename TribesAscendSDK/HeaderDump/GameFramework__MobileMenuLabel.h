#pragma once
#include "GameFramework__MobileMenuObject.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.MobileMenuLabel." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty GameFramework.MobileMenuLabel." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty GameFramework.MobileMenuLabel." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class MobileMenuLabel : public MobileMenuObject
	{
	public:
		ADD_VAR(::BoolProperty, bAutoSize, 0x1)
		ADD_VAR(::FloatProperty, TextYScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TextXScale, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'TouchedColor'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'TextColor'!
		ADD_OBJECT(Font, TextFont)
		ADD_VAR(::StrProperty, Caption, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
