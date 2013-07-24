#pragma once
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.ActorFactoryAmbientSoundSimple." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class ActorFactoryAmbientSoundSimple : public ActorFactory
	{
	public:
		ADD_OBJECT(SoundNodeWave, SoundNodeWave)
	};
}
#undef ADD_OBJECT
