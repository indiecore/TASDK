#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " TribesGame.TrCaHMessage." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty TribesGame.TrCaHMessage." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty TribesGame.TrCaHMessage." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrCaHMessage : public UTLocalMessage
	{
	public:
			ADD_VAR( ::StrProperty, Points, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, WeHave, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, TheEnemyHas, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, MorePointsToWin, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, WeNeed, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, TheEnemyNeeds, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, ControlPointCaptured, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, CaptureAndHoldTheControlPoints, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
