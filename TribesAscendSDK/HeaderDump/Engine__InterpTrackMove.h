#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.InterpTrackMove." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.InterpTrackMove." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.InterpTrackMove." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class InterpTrackMove : public InterpTrack
	{
	public:
			ADD_VAR( ::ByteProperty, RotMode, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, MoveFrame, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bHide3DTrack, 0x20 )
			ADD_VAR( ::BoolProperty, bShowRotationOnCurveEd, 0x10 )
			ADD_VAR( ::BoolProperty, bShowTranslationOnCurveEd, 0x8 )
			ADD_VAR( ::BoolProperty, bDisableMovement, 0x4 )
			ADD_VAR( ::BoolProperty, bShowArrowAtKeys, 0x2 )
			ADD_VAR( ::BoolProperty, bUseQuatInterpolation, 0x1 )
			ADD_VAR( ::FloatProperty, AngCurveTension, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LinCurveTension, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, LookAtGroupName, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
