#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.OnlineGameSearch." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.OnlineGameSearch." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.OnlineGameSearch." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class OnlineGameSearch : public Settings
	{
	public:
			void SortSearchResults(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameSearch.SortSearchResults" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetSkillOverride( int LeaderboardId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineGameSearch.SetSkillOverride" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( int* )( params + 0 ) = LeaderboardId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::IntProperty, MaxSearchResults, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bIsLanQuery, 0x1 )
			ADD_VAR( ::BoolProperty, bUsesArbitration, 0x2 )
			ADD_VAR( ::BoolProperty, bIsSearchInProgress, 0x4 )
			ADD_OBJECT( ScriptClass, GameSettingsClass )
			ADD_VAR( ::StrProperty, AdditionalSearchCriteria, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, PingBucketSize, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
