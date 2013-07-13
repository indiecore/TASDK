#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " GameFramework.GameSpecialMove." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty GameFramework.GameSpecialMove." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty GameFramework.GameSpecialMove." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GameSpecialMove : public Object
	{
	public:
			ADD_STRUCT( ::RotatorProperty, PreciseRotation, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, PreciseRotationInterpolationTime, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, PreciseDestRelOffset, 0xFFFFFFFF )
			ADD_OBJECT( Actor, PreciseDestBase )
			ADD_STRUCT( ::VectorProperty, PreciseDestination, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bForcePrecisePosition, 0x20 )
			ADD_VAR( ::BoolProperty, bReachedPreciseRotation, 0x10 )
			ADD_VAR( ::BoolProperty, bReachPreciseRotation, 0x8 )
			ADD_VAR( ::BoolProperty, bReachedPreciseDestination, 0x4 )
			ADD_VAR( ::BoolProperty, bReachPreciseDestination, 0x2 )
			ADD_VAR( ::BoolProperty, bLastCanDoSpecialMove, 0x1 )
			ADD_VAR( ::FloatProperty, LastCanDoSpecialMoveTime, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, Handle, 0xFFFFFFFF )
			ADD_OBJECT( GamePawn, PawnOwner )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
