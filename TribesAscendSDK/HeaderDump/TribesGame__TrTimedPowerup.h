#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrTimedPowerup." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrTimedPowerup." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrTimedPowerup." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrTimedPowerup : public TrInventory
	{
	public:
		ADD_VAR(::FloatProperty, PP_Scene_Desaturation, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, PP_Scene_HighLights, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, WarningTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TransitionDuration, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TransitionTime, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Engine.UIRoot.TextureCoordinates' for the property named 'IconCoords'!
		ADD_VAR(::NameProperty, PowerupStatName, 0xFFFFFFFF)
		ADD_OBJECT(SoundCue, PowerupOverSound)
		ADD_VAR(::IntProperty, HudIndex, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TimeRemaining, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
