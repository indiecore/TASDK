#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.OnlineStatsRead." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.OnlineStatsRead." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.OnlineStatsRead." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class OnlineStatsRead : public OnlineStats
	{
	public:
			ADD_VAR( ::IntProperty, TitleId, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, ViewName, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, TotalRowsInView, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, SortColumnId, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, ViewId, 0xFFFFFFFF )
			void OnReadComplete(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineStatsRead.OnReadComplete" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool GetIntStatValueForPlayer( void* PlayerID, int StatColumnNo, int &StatValue )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineStatsRead.GetIntStatValueForPlayer" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( void** )( params + 0 ) = PlayerID;
				*( int* )( params + 8 ) = StatColumnNo;
				*( int* )( params + 12 ) = StatValue;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				StatValue = *( int* )( params + 12 );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool SetIntStatValueForPlayer( void* PlayerID, int StatColumnNo, int StatValue )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineStatsRead.SetIntStatValueForPlayer" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( void** )( params + 0 ) = PlayerID;
				*( int* )( params + 8 ) = StatColumnNo;
				*( int* )( params + 12 ) = StatValue;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool GetFloatStatValueForPlayer( void* PlayerID, int StatColumnNo, float &StatValue )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineStatsRead.GetFloatStatValueForPlayer" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( void** )( params + 0 ) = PlayerID;
				*( int* )( params + 8 ) = StatColumnNo;
				*( float* )( params + 12 ) = StatValue;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				StatValue = *( float* )( params + 12 );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool SetFloatStatValueForPlayer( void* PlayerID, int StatColumnNo, float StatValue )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineStatsRead.SetFloatStatValueForPlayer" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( void** )( params + 0 ) = PlayerID;
				*( int* )( params + 8 ) = StatColumnNo;
				*( float* )( params + 12 ) = StatValue;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AddPlayer( ScriptArray< wchar_t > PlayerName, void* PlayerID )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineStatsRead.AddPlayer" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = PlayerName;
				*( void** )( params + 12 ) = PlayerID;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int GetRankForPlayer( void* PlayerID )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineStatsRead.GetRankForPlayer" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( void** )( params + 0 ) = PlayerID;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
