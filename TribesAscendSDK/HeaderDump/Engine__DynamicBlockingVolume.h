#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.DynamicBlockingVolume." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.DynamicBlockingVolume." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.DynamicBlockingVolume." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class DynamicBlockingVolume : public BlockingVolume
	{
	public:
			ADD_VAR( ::BoolProperty, bEnabled, 0x1 )
			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.DynamicBlockingVolume.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CreateCheckpointRecord( void* &Record )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.DynamicBlockingVolume.CreateCheckpointRecord" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( void** )params = Record;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Record = *( void** )params;
			}

			void ApplyCheckpointRecord( void* &Record )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.DynamicBlockingVolume.ApplyCheckpointRecord" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( void** )params = Record;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Record = *( void** )params;
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
