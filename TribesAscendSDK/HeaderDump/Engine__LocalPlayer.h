#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.LocalPlayer." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.LocalPlayer." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.LocalPlayer." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class LocalPlayer : public Player
	{
	public:
		ADD_VAR(::IntProperty, ControllerId, 0xFFFFFFFF)
		ADD_OBJECT(GameViewportClient, ViewportClient)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D' for the property named 'Size'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D' for the property named 'Origin'!
		ADD_OBJECT(TranslationContext, TagContext)
		ADD_VAR(::BoolProperty, bSentSplitJoin, 0x2)
		ADD_VAR(::BoolProperty, bWantToResetToMapDefaultPP, 0x1)
		ADD_VAR(::StrProperty, LastMap, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, AspectRatioAxisConstraint, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Engine.LocalPlayer.CurrentPostProcessVolumeInfo' for the property named 'LevelPPInfo'!
		// WARNING: Unknown structure type 'ScriptStruct Engine.LocalPlayer.CurrentPostProcessVolumeInfo' for the property named 'CurrentPPInfo'!
		ADD_STRUCT(::VectorProperty, LastViewLocation, 0xFFFFFFFF
		// WARNING: Unknown structure type 'ScriptStruct Engine.LocalPlayer.SynchronizedActorVisibilityHistory' for the property named 'ActorVisibilityHistory'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'ViewState'!
		ADD_OBJECT(PostProcessChain, PlayerPostProcess)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
