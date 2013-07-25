#pragma once
#include "GameFramework__MobileHUD.h"
#include "Engine__Font.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKHUD." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UDKBase.UDKHUD." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UDKBase.UDKHUD." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UDKHUD : public MobileHUD
	{
	public:
		ADD_OBJECT(Font, BindTextFont)
		ADD_OBJECT(Font, ConsoleIconFont)
		// WARNING: Unknown structure type 'ScriptStruct Engine.Canvas.FontRenderInfo' for the property named 'TextRenderInfo'!
		ADD_VAR(::FloatProperty, PulseMultiplier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, PulseSplit, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, PulseDuration, 0xFFFFFFFF)
		ADD_OBJECT(Font, GlowFonts)
		// Here lies the not-yet-implemented method 'DrawGlowText'
		// Here lies the not-yet-implemented method 'TranslateBindToFont'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
