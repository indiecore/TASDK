#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.UIGameInfoSummary." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.UIGameInfoSummary." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.UIGameInfoSummary." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UIGameInfoSummary : public UIResourceDataProvider
	{
	public:
			ADD_VAR( ::StrProperty, Description, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, GameName, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, GameSettingsClassName, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bIsDisabled, 0x2 )
			ADD_VAR( ::BoolProperty, bIsTeamGame, 0x1 )
			ADD_VAR( ::StrProperty, MapPrefix, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, GameAcronym, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, ClassName, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
