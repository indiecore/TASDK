#pragma once
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.WaterVolume." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class WaterVolume : public PhysicsVolume
	{
	public:
		ADD_OBJECT(SoundCue, ExitSound)
		ADD_OBJECT(SoundCue, EntrySound)
	};
}
#undef ADD_OBJECT
