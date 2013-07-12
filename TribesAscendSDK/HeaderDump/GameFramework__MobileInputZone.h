#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " GameFramework.MobileInputZone." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty GameFramework.MobileInputZone." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty GameFramework.MobileInputZone." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class MobileInputZone : public Object
	{
	public:
			ADD_VAR( ::BoolProperty, bIsInvisible, 0x200 )
			ADD_VAR( ::FloatProperty, AnimatingFadeOpacity, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, State, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, InactiveAlpha, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TransitionTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ActivateTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DeactivateTime, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, Type, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, X, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Y, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SizeX, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SizeY, 0xFFFFFFFF )
			ADD_OBJECT( Texture2D, OverrideTexture1 )
			ADD_OBJECT( Texture2D, OverrideTexture2 )
			ADD_VAR( ::FloatProperty, ActiveSizeX, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ActiveSizeY, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, Caption, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CaptionXAdjustment, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CaptionYAdjustment, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bRenderGuides, 0x8000 )
			ADD_VAR( ::ByteProperty, SlideType, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastWentActiveTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TotalActiveTime, 0xFFFFFFFF )
			ADD_OBJECT( MobilePlayerInput, InputOwner )
			ADD_VAR( ::FloatProperty, TimeSinceLastTapRepeat, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastTouchTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, PreviousLocationCount, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, PreviousMoveDeltaTimes, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, OverrideTexture2Name, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, OverrideTexture1Name, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TapDistanceConstraint, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ResetCenterAfterInactivityTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Border, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AuthoredGlobalScale, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bIsDoubleTapAndHold, 0x10000 )
			ADD_VAR( ::BoolProperty, bAllowFirstDeltaForTrackballZone, 0x4000 )
			ADD_VAR( ::BoolProperty, bUseGentleTransitions, 0x2000 )
			ADD_VAR( ::BoolProperty, bFloatingTiltZone, 0x1000 )
			ADD_VAR( ::BoolProperty, bCenterOnEvent, 0x800 )
			ADD_VAR( ::BoolProperty, bQuickDoubleTap, 0x400 )
			ADD_VAR( ::BoolProperty, bCenterY, 0x100 )
			ADD_VAR( ::BoolProperty, bCenterX, 0x80 )
			ADD_VAR( ::BoolProperty, bSizeYFromSizeX, 0x40 )
			ADD_VAR( ::BoolProperty, bActiveSizeYFromX, 0x20 )
			ADD_VAR( ::BoolProperty, bRelativeSizeY, 0x10 )
			ADD_VAR( ::BoolProperty, bRelativeSizeX, 0x8 )
			ADD_VAR( ::BoolProperty, bRelativeY, 0x4 )
			ADD_VAR( ::BoolProperty, bRelativeX, 0x2 )
			ADD_VAR( ::BoolProperty, bScalePawnMovement, 0x1 )
			ADD_VAR( ::FloatProperty, EscapeVelocityStrength, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Smoothing, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Acceleration, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, HorizMultiplier, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, VertMultiplier, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, DoubleTapInputKey, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, TapInputKey, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, HorizontalInputKey, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, InputKey, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
