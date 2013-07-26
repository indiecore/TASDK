#pragma once
#include "Engine.Texture2D.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Texture2DComposite.SourceTexture2DRegion." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Texture2DComposite.SourceTexture2DRegion." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SourceTexture2DRegion
	{
	public:
		ADD_OBJECT(Texture2D, Texture2D)
		ADD_VAR(::IntProperty, SizeY, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SizeX, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, OffsetY, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, OffsetX, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
