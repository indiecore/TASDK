#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.PlayerInput." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.PlayerInput." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.PlayerInput." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class PlayerInput : public Input
	{
	public:
			ADD_VAR( ::FloatProperty, aTurn, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, aLookUp, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, aForward, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, aStrafe, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RawJoyUp, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RawJoyRight, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, aUp, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bUsingGamepad, 0x1 )
			ADD_VAR( ::FloatProperty, AutoUnlockTurnTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MouseSamplingTotal, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MouseSamples, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SmoothedMouse, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ZeroTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, FOVSetting, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, bYAxis, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, bXAxis, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, bStrafe, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LookUpScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LookRightScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MoveStrafeSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MoveForwardSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RawJoyLookUp, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RawJoyLookRight, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, aPS3Gyro, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, aPS3AccelZ, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, aPS3AccelY, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, aPS3AccelX, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, aLeftAnalogTrigger, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, aRightAnalogTrigger, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, aMouseY, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, aMouseX, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, aBaseZ, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, aBaseY, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, aBaseX, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FlyingYawSensitivity, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FlyingPitchSensitivity, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MouseSensitivity, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DoubleClickTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DoubleClickTimer, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, LastAxisKeyName, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bLockTurnUntilRelease, 0x8000 )
			ADD_VAR( ::BoolProperty, bEnableFOVScaling, 0x4000 )
			ADD_VAR( ::BoolProperty, bUseToggleZoom, 0x2000 )
			ADD_VAR( ::BoolProperty, bEnableMouseSmoothing, 0x1000 )
			ADD_VAR( ::BoolProperty, bEdgeRight, 0x800 )
			ADD_VAR( ::BoolProperty, bEdgeLeft, 0x400 )
			ADD_VAR( ::BoolProperty, bEdgeBack, 0x200 )
			ADD_VAR( ::BoolProperty, bEdgeForward, 0x100 )
			ADD_VAR( ::BoolProperty, bWasRight, 0x80 )
			ADD_VAR( ::BoolProperty, bWasLeft, 0x40 )
			ADD_VAR( ::BoolProperty, bWasBack, 0x20 )
			ADD_VAR( ::BoolProperty, bWasForward, 0x10 )
			ADD_VAR( ::BoolProperty, bInvertAirVehicles, 0x8 )
			ADD_VAR( ::BoolProperty, bInvertTurn, 0x4 )
			ADD_VAR( ::BoolProperty, bInvertMouse, 0x2 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
