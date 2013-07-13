#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.LadderVolume." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.LadderVolume." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.LadderVolume." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class LadderVolume : public PhysicsVolume
	{
	public:
			ADD_STRUCT( ::VectorProperty, ClimbDir, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bAllowLadderStrafing, 0x4 )
			ADD_OBJECT( Pawn, PendingClimber )
			ADD_VAR( ::BoolProperty, bAutoPath, 0x2 )
			ADD_VAR( ::BoolProperty, bNoPhysicalLadder, 0x1 )
			ADD_OBJECT( Ladder, LadderList )
			ADD_STRUCT( ::VectorProperty, LookDir, 0xFFFFFFFF )
			ADD_STRUCT( ::RotatorProperty, WallDir, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
