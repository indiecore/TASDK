#pragma once
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrDevice_HeavyBoltLauncher." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrDevice_HeavyBoltLauncher : public TrDevice
	{
	public:
		ADD_OBJECT(SoundCue, m_BoltIdleSound)
	};
}
#undef ADD_OBJECT
