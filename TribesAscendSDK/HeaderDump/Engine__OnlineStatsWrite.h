#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.OnlineStatsWrite." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.OnlineStatsWrite." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.OnlineStatsWrite." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class OnlineStatsWrite : public OnlineStats
	{
	public:
			void OnStatsWriteComplete(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineStatsWrite.OnStatsWriteComplete" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::IntProperty, RatingId, 0xFFFFFFFF )
			bool GetStatId( ScriptName StatName, int &StatId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineStatsWrite.GetStatId" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )params = StatName;
				*( int* )( params + 8 ) = StatId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				StatId = *( int* )( params + 8 );
				return *( bool* )( params + function->return_val_offset() );
			}

			ScriptName GetStatName( int StatId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineStatsWrite.GetStatName" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = StatId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptName* )( params + function->return_val_offset() );
			}

			void SetFloatStat( int StatId, float Value )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineStatsWrite.SetFloatStat" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = StatId;
				*( float* )( params + 4 ) = Value;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetIntStat( int StatId, int Value )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineStatsWrite.SetIntStat" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = StatId;
				*( int* )( params + 4 ) = Value;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void IncrementFloatStat( int StatId, float IncBy )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineStatsWrite.IncrementFloatStat" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = StatId;
				*( float* )( params + 4 ) = IncBy;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void IncrementIntStat( int StatId, int IncBy )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineStatsWrite.IncrementIntStat" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = StatId;
				*( int* )( params + 4 ) = IncBy;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DecrementFloatStat( int StatId, float DecBy )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineStatsWrite.DecrementFloatStat" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = StatId;
				*( float* )( params + 4 ) = DecBy;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DecrementIntStat( int StatId, int DecBy )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineStatsWrite.DecrementIntStat" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = StatId;
				*( int* )( params + 4 ) = DecBy;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
