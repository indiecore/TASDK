#pragma once
#include "Core__Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.Font." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.Font." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class Font : public Object
	{
	public:
		ADD_VAR(::IntProperty, NumCharacters, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Engine.FontImportOptions.FontImportOptionsData' for the property named 'ImportOptions'!
		ADD_VAR(::IntProperty, Kerning, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Leading, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Descent, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Ascent, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, EmScale, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, IsRemapped, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'GetResolutionPageIndex'
		// Here lies the not-yet-implemented method 'GetScalingFactor'
		// Here lies the not-yet-implemented method 'GetAuthoredViewportHeight'
		// Here lies the not-yet-implemented method 'GetMaxCharHeight'
		// Here lies the not-yet-implemented method 'GetStringHeightAndWidth'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
