#pragma once
#include "Engine.MaterialExpressionTextureSampleParameter2D.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.MaterialExpressionAntialiasedTextureMask." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class MaterialExpressionAntialiasedTextureMask : public MaterialExpressionTextureSampleParameter2D
	{
	public:
		ADD_VAR(::ByteProperty, Channel, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Threshold, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
