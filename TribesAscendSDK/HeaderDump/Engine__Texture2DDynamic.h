#pragma once
#include "Engine__Texture.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.Texture2DDynamic." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class Texture2DDynamic : public Texture
	{
	public:
		ADD_VAR(::BoolProperty, bIsResolveTarget, 0x1)
		ADD_VAR(::IntProperty, NumMips, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, Format, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SizeY, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SizeX, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
