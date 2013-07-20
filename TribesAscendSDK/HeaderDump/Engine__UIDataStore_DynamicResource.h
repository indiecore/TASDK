#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.UIDataStore_DynamicResource." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.UIDataStore_DynamicResource." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.UIDataStore_DynamicResource." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UIDataStore_DynamicResource : public UIDataStore
	{
	public:
			ADD_OBJECT( UIDataStore_GameResource, GameResourceDataStore )
			ADD_OBJECT( UIDataProvider_OnlineProfileSettings, ProfileProvider )
			int FindProviderTypeIndex( ScriptName ProviderTag )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore_DynamicResource.FindProviderTypeIndex" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = ProviderTag;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			ScriptName GenerateProviderAccessTag( int ProviderIndex, int InstanceIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore_DynamicResource.GenerateProviderAccessTag" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = ProviderIndex;
				*( int* )( params + 4 ) = InstanceIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptName* )( params + function->return_val_offset() );
			}

			int GetProviderCount( ScriptName ProviderTag )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore_DynamicResource.GetProviderCount" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = ProviderTag;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			bool GetResourceProviders( ScriptName ProviderTag )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore_DynamicResource.GetResourceProviders" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptName* )params = ProviderTag;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool GetResourceProviderFields( ScriptName ProviderTag )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore_DynamicResource.GetResourceProviderFields" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptName* )params = ProviderTag;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool GetProviderFieldValue( ScriptName ProviderTag, ScriptName SearchField, int ProviderIndex, void* &out_FieldValue )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore_DynamicResource.GetProviderFieldValue" );
				byte *params = ( byte* )( malloc( 104 ) );
				*( ScriptName* )params = ProviderTag;
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
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore_DynamicResource.FindProviderIndexByFieldValue" );
				byte *params = ( byte* )( malloc( 100 ) );
				*( ScriptName* )params = ProviderTag;
				*( ScriptName* )( params + 8 ) = SearchField;
				*( void** )( params + 16 ) = ValueToSearchFor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				ValueToSearchFor = *( void** )( params + 16 );
				return *( int* )( params + function->return_val_offset() );
			}

			void OnLoginChange( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore_DynamicResource.OnLoginChange" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Registered( class LocalPlayer* PlayerOwner )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore_DynamicResource.Registered" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class LocalPlayer** )params = PlayerOwner;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Unregistered( class LocalPlayer* PlayerOwner )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore_DynamicResource.Unregistered" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class LocalPlayer** )params = PlayerOwner;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
