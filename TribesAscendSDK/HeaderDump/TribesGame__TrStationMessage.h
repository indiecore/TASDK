#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrStationMessage." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrStationMessage." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrStationMessage." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrStationMessage : public UTLocalMessage
	{
	public:
			ADD_OBJECT( SoundCue, EnemyStationSound )
			ADD_OBJECT( SoundCue, StationNotPoweredSound )
			ADD_VAR( ::StrProperty, MustBeHeld, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, ControlPoint, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, NeutralStation, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, EnemyStation, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, StationNotPowered, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
