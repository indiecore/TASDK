#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.AudioComponent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.AudioComponent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.AudioComponent." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class AudioComponent : public ActorComponent
	{
	public:
			ADD_VAR( ::BoolProperty, bUseOwnerLocation, 0x1 )
			ADD_STRUCT( ::VectorProperty, Location, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bAllowSpatialization, 0x100 )
			ADD_VAR( ::FloatProperty, VolumeMultiplier, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, PitchMultiplier, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bAutoDestroy, 0x4 )
			ADD_VAR( ::FloatProperty, SubtitlePriority, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bSuppressSubtitles, 0x40 )
			ADD_OBJECT( SoundCue, SoundCue )
			ADD_VAR( ::FloatProperty, LastOcclusionCheckTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, OcclusionCheckInterval, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, HighFrequencyGainMultiplier, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, LastReverbVolumeIndex, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, LastLocation, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CurrentInteriorLPF, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CurrentInteriorVolume, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SourceInteriorLPF, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SourceInteriorVolume, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CurrentRadioFilterVolumeThreshold, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CurrentRadioFilterVolume, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CurrentVoiceCenterChannelVolume, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CurrentHighFrequencyGainMultiplier, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CurrentPitchMultiplier, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CurrentVolumeMultiplier, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, CurrentNotifyOnLoop, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, CurrentUseSpatialization, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CurrentHighFrequencyGain, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CurrentPitch, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CurrentVolume, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, CurrentLocation, 0xFFFFFFFF )
			ADD_OBJECT( SoundNode, CurrentNotifyBufferFinishedHook )
			ADD_VAR( ::FloatProperty, CurrAdjustVolumeTargetVolume, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AdjustVolumeTargetVolume, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AdjustVolumeStopTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AdjustVolumeStartTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FadeOutTargetVolume, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FadeOutStopTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FadeOutStartTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FadeInTargetVolume, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FadeInStopTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FadeInStartTime, 0xFFFFFFFF )
			ADD_OBJECT( Actor, LastOwner )
			ADD_STRUCT( ::VectorProperty, ComponentLocation, 0xFFFFFFFF )
			ADD_OBJECT( PortalVolume, PortalVolume )
			ADD_VAR( ::FloatProperty, PlaybackTime, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bBassBoost, 0x40 )
			ADD_VAR( ::BoolProperty, bCenterChannelOnly, 0x20 )
			ADD_VAR( ::BoolProperty, bReverb, 0x10 )
			ADD_VAR( ::BoolProperty, bIsMusic, 0x8 )
			ADD_VAR( ::BoolProperty, bIsUISound, 0x4 )
			ADD_VAR( ::BoolProperty, bAlwaysPlay, 0x2 )
			ADD_VAR( ::BoolProperty, bEQFilterApplied, 0x1 )
			ADD_VAR( ::FloatProperty, LFEBleed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, StereoBleed, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bIgnoreForFlushing, 0x800 )
			ADD_VAR( ::BoolProperty, bPreviewComponent, 0x400 )
			ADD_VAR( ::BoolProperty, bFinished, 0x200 )
			ADD_VAR( ::BoolProperty, bWasPlaying, 0x80 )
			ADD_VAR( ::BoolProperty, bWasOccluded, 0x20 )
			ADD_VAR( ::BoolProperty, bShouldRemainActiveIfDropped, 0x10 )
			ADD_VAR( ::BoolProperty, bStopWhenOwnerDestroyed, 0x8 )
			ADD_VAR( ::BoolProperty, bAutoPlay, 0x2 )
			ADD_OBJECT( SoundNode, CueFirstNode )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
