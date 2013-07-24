#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrDevice_RemoteArxBuster." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrDevice_RemoteArxBuster." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrDevice_RemoteArxBuster : public TrDevice
	{
	public:
		ADD_OBJECT(SoundCue, m_ArxIdleSound)
		ADD_OBJECT(AnimNodeAdditiveBlending, DetReadyAdditiveAnimNode)
		ADD_VAR(::BoolProperty, r_bIsLeftArmVisible, 0x1)
		ADD_OBJECT(SkelControlSingleBone, DetonatorChild)
		ADD_OBJECT(SkelControlSingleBone, DetonatorControl)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
