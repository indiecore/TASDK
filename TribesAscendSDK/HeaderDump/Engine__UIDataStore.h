#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.UIDataStore." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.UIDataStore." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.UIDataStore." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UIDataStore : public UIDataProvider
	{
	public:
			ADD_VAR( ::NameProperty, Tag, 0xFFFFFFFF )
			bool NotifyGameSessionEnded(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore.NotifyGameSessionEnded" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void OnDataStoreValueUpdated( class UIDataStore* SourceDataStore, bool bValuesInvalidated, ScriptName PropertyTag, class UIDataProvider* SourceProvider, int ArrayIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore.OnDataStoreValueUpdated" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( class UIDataStore** )( params + 0 ) = SourceDataStore;
				*( bool* )( params + 4 ) = bValuesInvalidated;
				*( ScriptName* )( params + 8 ) = PropertyTag;
				*( class UIDataProvider** )( params + 16 ) = SourceProvider;
				*( int* )( params + 20 ) = ArrayIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Registered( class LocalPlayer* PlayerOwner )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore.Registered" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class LocalPlayer** )( params + 0 ) = PlayerOwner;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Unregistered( class LocalPlayer* PlayerOwner )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore.Unregistered" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class LocalPlayer** )( params + 0 ) = PlayerOwner;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SubscriberAttached(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore.SubscriberAttached" );
				byte *params = ( byte* )( malloc( 8 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SubscriberDetached(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore.SubscriberDetached" );
				byte *params = ( byte* )( malloc( 8 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RefreshSubscribers( ScriptName PropertyTag, bool bInvalidateValues, class UIDataProvider* SourceProvider, int ArrayIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore.RefreshSubscribers" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptName* )( params + 0 ) = PropertyTag;
				*( bool* )( params + 8 ) = bInvalidateValues;
				*( class UIDataProvider** )( params + 12 ) = SourceProvider;
				*( int* )( params + 16 ) = ArrayIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnCommit(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore.OnCommit" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class DataStoreClient* GetDataStoreClient(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore.GetDataStoreClient" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class DataStoreClient** )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
