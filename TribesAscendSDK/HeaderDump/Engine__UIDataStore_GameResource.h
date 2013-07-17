#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.UIDataStore_GameResource." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.UIDataStore_GameResource." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.UIDataStore_GameResource." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UIDataStore_GameResource : public UIDataStore
	{
	public:
			int FindProviderTypeIndex( ScriptName ProviderTag )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore_GameResource.FindProviderTypeIndex" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = ProviderTag;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			ScriptName GenerateProviderAccessTag( int ProviderIndex, int InstanceIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore_GameResource.GenerateProviderAccessTag" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = ProviderIndex;
				*( int* )( params + 4 ) = InstanceIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptName* )( params + function->return_val_offset() );
			}

			int GetProviderCount( ScriptName ProviderTag )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore_GameResource.GetProviderCount" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = ProviderTag;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			bool GetResourceProviders( ScriptName ProviderTag )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore_GameResource.GetResourceProviders" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptName* )( params + 0 ) = ProviderTag;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool GetResourceProviderFields( ScriptName ProviderTag )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore_GameResource.GetResourceProviderFields" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptName* )( params + 0 ) = ProviderTag;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool GetProviderFieldValue( ScriptName ProviderTag, ScriptName SearchField, int ProviderIndex, void* &out_FieldValue )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore_GameResource.GetProviderFieldValue" );
				byte *params = ( byte* )( malloc( 104 ) );
				*( ScriptName* )( params + 0 ) = ProviderTag;
				*( ScriptName* )( params + 8 ) = SearchField;
				*( int* )( params + 16 ) = ProviderIndex;
				*( void** )( params + 20 ) = out_FieldValue;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_FieldValue = *( void** )( params + 20 );
				return *( bool* )( params + function->return_val_offset() );
			}

			int FindProviderIndexByFieldValue( ScriptName ProviderTag, ScriptName SearchField, void* &ValueToSearchFor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore_GameResource.FindProviderIndexByFieldValue" );
				byte *params = ( byte* )( malloc( 100 ) );
				*( ScriptName* )( params + 0 ) = ProviderTag;
				*( ScriptName* )( params + 8 ) = SearchField;
				*( void** )( params + 16 ) = ValueToSearchFor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				ValueToSearchFor = *( void** )( params + 16 );
				return *( int* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
