#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrCTFMessage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrCTFMessage." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrCTFMessage : public UTLocalMessage
	{
	public:
		ADD_VAR(::StrProperty, DiamondSwordFlagAbandoned, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, BloodEagleFlagAbandoned, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, DiamondSwordFlagDropped, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, BloodEagleFlagDropped, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, DiamondSwordFlagReturned, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, BloodEagleFlagReturned, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, DiamondSwordFlagCaptured, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, BloodEagleFlagCaptured, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, DiamondSwordFlagPickupAwayFromBase, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, BloodEagleFlagPickupAwayFromBase, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, DiamondSwordFlagTaken, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, BloodEagleFlagTaken, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, FriendlyFlagAbandoned, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, EnemyFlagAbandoned, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, FriendlyFlagDropped, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, EnemyFlagDropped, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, FriendlyFlagReturned, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, EnemyFlagReturned, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, FriendlyFlagCaptured, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, EnemyFlagCaptured, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, FriendlyFlagPickupAwayFromBase, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, EnemyFlagPickupAwayFromBase, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, FriendlyFlagTaken, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, EnemyFlagTaken, 0xFFFFFFFF)
		ADD_OBJECT(SoundCue, m_sBECapturedDSFlag)
		ADD_OBJECT(SoundCue, m_sDSCapturedBEFlag)
		ADD_OBJECT(SoundCue, m_sBETookDSFlag)
		ADD_OBJECT(SoundCue, m_sDSTookBEFlag)
		ADD_OBJECT(SoundCue, m_sBEFlagSecured)
		ADD_OBJECT(SoundCue, m_sDSFlagSecured)
		ADD_OBJECT(SoundCue, m_sBELostDSFlag)
		ADD_OBJECT(SoundCue, m_sDSLostBEFlag)
		ADD_OBJECT(SoundCue, m_sDSFlagCaptured)
		ADD_OBJECT(SoundCue, m_sDSFlagTaken)
		ADD_OBJECT(SoundCue, m_sBEFlagCaptured)
		ADD_OBJECT(SoundCue, m_sBEFlagTaken)
		ADD_OBJECT(SoundNodeWave, m_CapturedSounds)
		ADD_OBJECT(SoundNodeWave, m_TakenSounds)
		ADD_OBJECT(SoundNodeWave, m_DroppedSounds)
		ADD_OBJECT(SoundNodeWave, m_ReturnSounds)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
