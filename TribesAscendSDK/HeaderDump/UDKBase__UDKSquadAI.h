#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UDKBase.UDKSquadAI." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UDKBase.UDKSquadAI." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UDKBase.UDKSquadAI." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UDKSquadAI : public UDKTeamOwnedInfo
	{
	public:
			ADD_VAR( ::IntProperty, MaxSquadRoutes, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, SquadRouteIteration, 0xFFFFFFFF )
			ADD_OBJECT( UDKBot, PendingSquadRouteMaker )
			ADD_OBJECT( NavigationPoint, RouteObjective )
			ADD_OBJECT( UDKGameObjective, SquadObjective )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
