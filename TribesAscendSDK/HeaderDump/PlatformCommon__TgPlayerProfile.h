#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " PlatformCommon.TgPlayerProfile." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty PlatformCommon.TgPlayerProfile." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty PlatformCommon.TgPlayerProfile." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TgPlayerProfile : public OnlinePlayerStorage
	{
	public:
			ADD_VAR( ::StrProperty, PlayerName, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, PlayerID, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bBoost, 0x2 )
			ADD_VAR( ::BoolProperty, bVIP, 0x1 )
			ADD_VAR( ::IntProperty, ObjsDestroyed, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, GensDestroyed, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, FlagCaps, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, FlagGrabs, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, FastestSki, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, TotalAccolades, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, TimePlayed, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, InfoMask, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, BoostHoursRemaining, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, AverageScore, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, AssistPoints, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, XPPoints, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, HZPoints, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, XpLevel, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, Assists, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, Deaths, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, Kills, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, Rank, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
