#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrAnimNodeBlendByDeviceAnim." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrAnimNodeBlendByDeviceAnim." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrAnimNodeBlendByDeviceAnim : public TrAnimNodeBlendList
	{
	public:
		ADD_VAR(::IntProperty, m_nSocketIndex, 0xFFFFFFFF)
		ADD_OBJECT(TrAnimNodeBlendByDeviceAnim, m_SecondaryDeviceBlendNode)
		ADD_VAR(::NameProperty, m_SecondaryDeviceBlendNodeName, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, m_StandardReloadAnimName, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, m_ReloadPartialClipAnimName, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, m_StandardFireAnimName, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, m_DryFireAnimName, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, m_FireFinalRoundAnimName, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bScalePutawayRetrieveAnims, 0x8)
		ADD_VAR(::BoolProperty, m_bScaleFireByRefireTime, 0x4)
		ADD_VAR(::BoolProperty, m_bPlayFire, 0x2)
		ADD_VAR(::BoolProperty, m_bPlayBuildUp, 0x1)
		ADD_OBJECT(TrSkelControl_SpinControl, m_BuildupFireSpinControl)
		ADD_VAR(::NameProperty, m_nmBuildupFireSpinControlName, 0xFFFFFFFF)
		ADD_OBJECT(TrDevice, m_Device)
		ADD_OBJECT(TrPawn, m_TrPawn)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
