#pragma once
#include "Engine.Font.h"
#include "Core.Object.Vector2D.h"
#include "Core.Object.Color.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " HUD.KismetDrawTextInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty HUD.KismetDrawTextInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty HUD.KismetDrawTextInfo." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class KismetDrawTextInfo
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<Vector2D>, MessageOffset, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MessageEndTime, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Color>, MessageColor, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Vector2D>, MessageFontScale, 0xFFFFFFFF)
		ADD_OBJECT(Font, MessageFont)
		ADD_VAR(::StrProperty, AppendedText, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, MessageText, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
