#pragma once
#include "Core__Object.h"
#include "Engine__PlayerController.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.Player." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.Player." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.Player." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class Player : public Object
	{
	public:
		ADD_VAR(::IntProperty, CurrentNetSpeed, 0xFFFFFFFF)
		ADD_OBJECT(PlayerController, Actor)
		ADD_VAR(::FloatProperty, PP_ShadowsMultiplier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, PP_MidTonesMultiplier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, PP_HighlightsMultiplier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, PP_DesaturationMultiplier, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ConfiguredLanSpeed, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ConfiguredInternetSpeed, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTable_FExec'!
		// Here lies the not-yet-implemented method 'SwitchController'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
