#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrLoadingData." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrLoadingData." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrLoadingData." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrLoadingData : public Object
	{
	public:
			ADD_VAR( ::StrProperty, RulesForBlitz, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, RulesForCaH, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, RulesForDaD, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, RulesForArena, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, RulesForRabbit, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, RulesForTDM, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, RulesForCTF, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, GameType, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, MapName, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, MapURL, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, Rules, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, Tip, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
