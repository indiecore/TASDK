#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqAct_StreamInTextures." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.SeqAct_StreamInTextures." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqAct_StreamInTextures : public SeqAct_Latent
	{
	public:
		ADD_VAR(::IntProperty, SelectedCinematicTextureGroups, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Engine.Texture.TextureGroupContainer' for the property named 'CinematicTextureGroups'!
		ADD_VAR(::FloatProperty, StopTimestamp, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Seconds, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bStreamingActive, 0x2)
		ADD_VAR(::BoolProperty, bLocationBased, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
