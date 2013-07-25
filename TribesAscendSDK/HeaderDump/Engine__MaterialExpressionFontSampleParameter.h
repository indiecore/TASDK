#pragma once
#include "Engine__MaterialExpressionFontSample.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.MaterialExpressionFontSampleParameter." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.MaterialExpressionFontSampleParameter." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class MaterialExpressionFontSampleParameter : public MaterialExpressionFontSample
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Guid' for the property named 'ExpressionGUID'!
		ADD_VAR(::NameProperty, ParameterName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
