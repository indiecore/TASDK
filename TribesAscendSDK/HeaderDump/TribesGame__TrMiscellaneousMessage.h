#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " TribesGame.TrMiscellaneousMessage." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty TribesGame.TrMiscellaneousMessage." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty TribesGame.TrMiscellaneousMessage." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrMiscellaneousMessage : public UTLocalMessage
	{
	public:
			ADD_VAR( ::StrProperty, EnemyTeamBoughtHerc, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, OurTeamBoughtHerc, 0xFFFFFFFF )
			ADD_OBJECT( SoundCue, DiamondSwordCloseToLoss )
			ADD_OBJECT( SoundCue, DiamondSwordCloseToWin )
			ADD_OBJECT( SoundCue, BloodEagleCloseToLoss )
			ADD_OBJECT( SoundCue, BloodEagleCloseToWin )
			ADD_OBJECT( SoundCue, FriendDiamondSwordBoughtHerc )
			ADD_OBJECT( SoundCue, FriendBloodEagleBoughtHerc )
			ADD_OBJECT( SoundCue, EnemyDiamondSwordBoughtHerc )
			ADD_OBJECT( SoundCue, EnemyBloodEagleBoughtHerc )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
