#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.UTTeamInfo." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.UTTeamInfo." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.UTTeamInfo." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTTeamInfo : public TeamInfo
	{
	public:
			ADD_VAR( ::StrProperty, Faction, 0xFFFFFFFF )
			ADD_OBJECT( UTCarriedObject, TeamFlag )
			ADD_OBJECT( UTTeamAI, AI )
			ADD_OBJECT( UTGameObjective, HomeBase )
			ADD_VAR( ::StrProperty, TeamColorNames, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, DesiredTeamSize, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
