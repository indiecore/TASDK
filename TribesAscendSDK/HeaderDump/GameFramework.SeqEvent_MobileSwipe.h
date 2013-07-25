#pragma once
#include "GameFramework.SeqEvent_MobileRawInput.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.SeqEvent_MobileSwipe." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty GameFramework.SeqEvent_MobileSwipe." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqEvent_MobileSwipe : public SeqEvent_MobileRawInput
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D' for the property named 'InitialTouch'!
		ADD_VAR(::FloatProperty, MinDistance, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Tolerance, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
