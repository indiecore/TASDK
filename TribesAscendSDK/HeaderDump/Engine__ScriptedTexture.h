#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ScriptedTexture." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ScriptedTexture : public TextureRenderTarget2D
	{
	public:
		ADD_VAR(::BoolProperty, bSkipNextClear, 0x2)
		ADD_VAR(::BoolProperty, bNeedsUpdate, 0x1)
	};
}
#undef ADD_VAR
