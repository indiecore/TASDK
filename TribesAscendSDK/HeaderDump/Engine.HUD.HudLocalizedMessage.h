#pragma once
#include "Core.Object.h"
#include "Engine.Font.h"
#include "Core.Object.Color.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " HUD.HudLocalizedMessage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty HUD.HudLocalizedMessage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty HUD.HudLocalizedMessage." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class HudLocalizedMessage
	{
	public:
		ADD_OBJECT(Object, OptionalObject)
		ADD_VAR(::IntProperty, Count, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, Drawn, 0x1)
		ADD_VAR(::FloatProperty, DY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DX, 0xFFFFFFFF)
		ADD_OBJECT(Font, StringFont)
		ADD_VAR(::IntProperty, FontSize, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Color>, DrawColor, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, PosY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Lifetime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, EndOfLife, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Switch, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, StringMessage, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, Message)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
