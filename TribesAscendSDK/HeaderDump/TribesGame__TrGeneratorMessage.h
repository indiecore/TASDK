#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrGeneratorMessage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrGeneratorMessage." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrGeneratorMessage : public UTLocalMessage
	{
	public:
		ADD_VAR(::StrProperty, OurGeneratorRestored, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, EnemyGeneratorDestroyed, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, OurGeneratorDestroyed, 0xFFFFFFFF)
		ADD_OBJECT(SoundCue, DiamondSwordSounds)
		ADD_OBJECT(SoundCue, BloodEagleSounds)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
