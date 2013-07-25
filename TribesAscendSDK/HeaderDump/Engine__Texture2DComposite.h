#pragma once
#include "Engine__Texture.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.Texture2DComposite." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class Texture2DComposite : public Texture
	{
	public:
		ADD_VAR(::IntProperty, MaxTextureSize, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
