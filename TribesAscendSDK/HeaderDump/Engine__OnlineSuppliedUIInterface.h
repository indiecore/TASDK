#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.OnlineSuppliedUIInterface." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.OnlineSuppliedUIInterface." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.OnlineSuppliedUIInterface." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class OnlineSuppliedUIInterface : public Interface
	{
	public:
			void OnShowOnlineStatsUIComplete(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineSuppliedUIInterface.OnShowOnlineStatsUIComplete" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool ShowOnlineStatsUI( class OnlineStatsRead* StatsRead )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineSuppliedUIInterface.ShowOnlineStatsUI" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class OnlineStatsRead** )( params + 12 ) = StatsRead;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AddShowOnlineStatsUICompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineSuppliedUIInterface.AddShowOnlineStatsUICompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearShowOnlineStatsUICompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineSuppliedUIInterface.ClearShowOnlineStatsUICompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool ShowMatchmakingUI( byte SearchingPlayerNum, class OnlineGameSearch* SearchSettings, class OnlineGameSettings* GameSettings )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineSuppliedUIInterface.ShowMatchmakingUI" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( byte* )params = SearchingPlayerNum;
				*( class OnlineGameSearch** )( params + 4 ) = SearchSettings;
				*( class OnlineGameSettings** )( params + 8 ) = GameSettings;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
