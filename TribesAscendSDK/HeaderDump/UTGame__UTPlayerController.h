#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTPlayerController." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UTGame.UTPlayerController." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTPlayerController." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTPlayerController : public UDKPlayerController
	{
	public:
		ADD_VAR(::BoolProperty, bLateComer, 0x1)
		ADD_OBJECT(UTUIDataStore_StringAliasBindingsMap, BoundEventsStringDataStore)
		ADD_VAR(::BoolProperty, bQuittingToMainMenu, 0x20000)
		ADD_VAR(::BoolProperty, bJustFoundVehicle, 0x80000)
		ADD_VAR(::BoolProperty, bLandingShake, 0x4000)
		ADD_VAR(::FloatProperty, LastWarningTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastTauntAnimTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bIsTyping, 0x2)
		ADD_OBJECT(UTAnnouncer, Announcer)
		ADD_OBJECT(UTMusicManager, MusicManager)
		ADD_VAR(::BoolProperty, bBehindView, 0x80)
		ADD_VAR(::FloatProperty, LastKickWarningTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OnFootDefaultFOV, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, WeaponHandPreference, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bAutoTaunt, 0x4)
		ADD_VAR(::BoolProperty, bCenteredWeaponFire, 0x8000)
		ADD_VAR(::ByteProperty, AutoObjectivePreference, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, VehicleControlType, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, PawnShadowMode, 0xFFFFFFFF)
		ADD_OBJECT(Actor, LastAutoObjective)
		ADD_VAR(::FloatProperty, LastShowPathTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bUseVehicleRotationOnPossess, 0x8)
		ADD_VAR(::ByteProperty, IdentifiedTeam, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, WeaponHand, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastUseTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bAlreadyReset, 0x400000)
		ADD_OBJECT(Actor, CalcViewActor)
		ADD_VAR(::BoolProperty, bFreeCamera, 0x200)
		ADD_VAR(::FloatProperty, LastCameraTimeStamp, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bDebugFreeCam, 0x40000)
		ADD_STRUCT(::RotatorProperty, DebugFreeCamRot, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, CalcViewActorLocation, 0xFFFFFFFF
		ADD_STRUCT(::RotatorProperty, CalcViewActorRotation, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, CalcEyeHeight, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, CalcWalkBob, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, CalcViewLocation, 0xFFFFFFFF
		ADD_STRUCT(::RotatorProperty, CalcViewRotation, 0xFFFFFFFF
		ADD_OBJECT(CameraAnim, DamageCameraAnim)
		ADD_VAR(::BoolProperty, bCurrentCamAnimIsDamageShake, 0x1000)
		ADD_VAR(::BoolProperty, bCurrentCamAnimAffectsFOV, 0x2000)
		ADD_OBJECT(ForceFeedbackWaveform, CameraShakeShortWaveForm)
		ADD_OBJECT(ForceFeedbackWaveform, CameraShakeLongWaveForm)
		ADD_VAR(::BoolProperty, bCameraOutOfWorld, 0x20)
		ADD_VAR(::StrProperty, MsgPlayerNotFound, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bServerMutedText, 0x800000)
		ADD_VAR(::BoolProperty, bNonlinearZoomInterpolation, 0x10000)
		ADD_VAR(::FloatProperty, FOVNonlinearZoomInterpSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FOVLinearZoomRate, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastBullseyeTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastTeamChangeTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bNoTextToSpeechVoiceMessages, 0x400)
		ADD_VAR(::BoolProperty, bTextToSpeechTeamMessagesOnly, 0x800)
		ADD_VAR(::FloatProperty, NextAdminCmdTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bRotateMinimap, 0x10)
		ADD_VAR(::BoolProperty, bFirstPersonWeaponsSelfShadow, 0x40)
		ADD_VAR(::BoolProperty, bForceBehindView, 0x100)
		ADD_VAR(::BoolProperty, bNoCrosshair, 0x100000)
		ADD_VAR(::BoolProperty, bSimpleCrosshair, 0x200000)
		ADD_VAR(::BoolProperty, bHideObjectivePaths, 0x1000000)
		ADD_STRUCT(::VectorProperty, DesiredLocation, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, ZoomRotationModifier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OldMessageTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastFriendlyFireTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastIncomingMessageTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastCombatUpdateTime, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
