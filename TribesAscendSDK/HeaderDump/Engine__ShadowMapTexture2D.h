#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ShadowMapTexture2D." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ShadowMapTexture2D : public Texture2D
	{
	public:
		ADD_VAR(::IntProperty, ShadowmapFlags, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
