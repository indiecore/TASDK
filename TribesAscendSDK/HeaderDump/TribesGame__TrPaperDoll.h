#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrPaperDoll." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrPaperDoll." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrPaperDoll." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrPaperDoll : public SkeletalMeshActorMAT
	{
	public:
		ADD_OBJECT(TrPlayerController, m_TrPlayerController)
		ADD_VAR(::FloatProperty, m_fLastStreamingCheckTimestamp, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fCheckStreamingFrequency, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct TribesGame.TrObject.PaperDollInfo' for the property named 'm_PendingPaperDollInfoSkin'!
		// WARNING: Unknown structure type 'ScriptStruct TribesGame.TrObject.PaperDollInfo' for the property named 'm_PendingPaperDollInfoDevice'!
		ADD_VAR(::IntProperty, m_LastSkinIdRequest, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bWasLastMeshSwapRequestNonWeapon, 0x1)
		// WARNING: Unknown structure type 'ScriptStruct TribesGame.TrObject.PaperDollInfo' for the property named 'm_CurrentPaperDollInfo'!
		ADD_VAR(::FloatProperty, m_fMaxCustomAnimTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fMinCustomAnimTime, 0xFFFFFFFF)
		ADD_OBJECT(AnimNodePlayCustomAnim, m_SidekickCustomAnimNode)
		ADD_OBJECT(AnimNodePlayCustomAnim, m_CharacterCustomAnimNode)
		ADD_STRUCT(::VectorProperty, m_vOffsetHeavy, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, m_vOffsetMedium, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, m_vOffsetLight, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, m_vBackdropOffset, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, m_fBackdropScale16x10, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fBackdropScale16x9, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fBackdropScale4x3, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInstanceConstant, m_DiamondSwordBackdropMaterial)
		ADD_OBJECT(MaterialInstanceConstant, m_BloodEagleBackdropMaterial)
		ADD_STRUCT(::VectorProperty, m_vViewOffset16x10, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, m_vViewOffset16x9, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, m_vViewOffset4x3, 0xFFFFFFFF
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
