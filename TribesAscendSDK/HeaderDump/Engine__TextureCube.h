#pragma once
#include "Engine__Texture2D.h"
#include "Engine__Texture.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.TextureCube." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.TextureCube." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TextureCube : public Texture
	{
	public:
		ADD_OBJECT(Texture2D, FaceNegZ)
		ADD_OBJECT(Texture2D, FacePosZ)
		ADD_OBJECT(Texture2D, FaceNegY)
		ADD_OBJECT(Texture2D, FacePosY)
		ADD_OBJECT(Texture2D, FaceNegX)
		ADD_OBJECT(Texture2D, FacePosX)
		ADD_VAR(::BoolProperty, bIsCubemapValid, 0x1)
		ADD_VAR(::IntProperty, NumMips, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, Format, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SizeY, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SizeX, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
