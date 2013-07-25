#pragma once
#include "Engine__PrimitiveComponent.h"
#include "Engine__Texture2D.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SpriteComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.SpriteComponent." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SpriteComponent : public PrimitiveComponent
	{
	public:
		ADD_VAR(::FloatProperty, VL, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, V, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, UL, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, U, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ScreenSize, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bIsScreenSizeScaled, 0x1)
		ADD_OBJECT(Texture2D, Sprite)
		// Here lies the not-yet-implemented method 'SetSprite'
		// Here lies the not-yet-implemented method 'SetUV'
		// Here lies the not-yet-implemented method 'SetSpriteAndUV'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
