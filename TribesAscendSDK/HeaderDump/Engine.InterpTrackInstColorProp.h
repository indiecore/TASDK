#pragma once
#include "Engine.InterpTrackInstProperty.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.InterpTrackInstColorProp." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class InterpTrackInstColorProp : public InterpTrackInstProperty
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'ResetColor'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'ColorProp'!
	};
}
#undef ADD_STRUCT
