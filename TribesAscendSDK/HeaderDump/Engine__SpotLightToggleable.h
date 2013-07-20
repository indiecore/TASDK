#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.SpotLightToggleable." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.SpotLightToggleable." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.SpotLightToggleable." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SpotLightToggleable : public SpotLight
	{
	public:
			bool ShouldSaveForCheckpoint(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SpotLightToggleable.ShouldSaveForCheckpoint" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void CreateCheckpointRecord( void* &Record )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SpotLightToggleable.CreateCheckpointRecord" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( void** )params = Record;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Record = *( void** )params;
			}

			void ApplyCheckpointRecord( void* &Record )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SpotLightToggleable.ApplyCheckpointRecord" );
				byte *params = ( byte* )( malloc( 4 ) );
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
