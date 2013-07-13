#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.UTCarriedObjectMessage." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.UTCarriedObjectMessage." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.UTCarriedObjectMessage." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTCarriedObjectMessage : public UTLocalMessage
	{
	public:
			ADD_OBJECT( SoundNodeWave, TakenSounds )
			ADD_OBJECT( SoundNodeWave, DroppedSounds )
			ADD_OBJECT( SoundNodeWave, ReturnSounds )
			ADD_VAR( ::StrProperty, KilledRed, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, KilledBlue, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, HasRed, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, HasBlue, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, DroppedRed, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, DroppedBlue, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, CaptureRed, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, CaptureBlue, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, ReturnedRed, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, ReturnedBlue, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, ReturnRed, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, ReturnBlue, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
