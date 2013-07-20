#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.UIRoot." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.UIRoot." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.UIRoot." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UIRoot : public Object
	{
	public:
			bool GetDataStoreStringValue( ScriptArray< wchar_t > InDataStoreMarkup, ScriptArray< wchar_t > &OutStringValue, class LocalPlayer* OwnerPlayer )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIRoot.GetDataStoreStringValue" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( ScriptArray< wchar_t >* )params = InDataStoreMarkup;
				*( ScriptArray< wchar_t >* )( params + 12 ) = OutStringValue;
				*( class LocalPlayer** )( params + 24 ) = OwnerPlayer;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				OutStringValue = *( ScriptArray< wchar_t >* )( params + 12 );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool SetDataStoreStringValue( ScriptArray< wchar_t > InDataStoreMarkup, ScriptArray< wchar_t > InStringValue, class LocalPlayer* OwnerPlayer )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIRoot.SetDataStoreStringValue" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( ScriptArray< wchar_t >* )params = InDataStoreMarkup;
				*( ScriptArray< wchar_t >* )( params + 12 ) = InStringValue;
				*( class LocalPlayer** )( params + 24 ) = OwnerPlayer;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			byte GetInputPlatformType( class LocalPlayer* OwningPlayer )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIRoot.GetInputPlatformType" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class LocalPlayer** )params = OwningPlayer;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

			class UIInteraction* GetCurrentUIController(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIRoot.GetCurrentUIController" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class UIInteraction** )( params + function->return_val_offset() );
			}

			class GameUISceneClient* GetSceneClient(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIRoot.GetSceneClient" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class GameUISceneClient** )( params + function->return_val_offset() );
			}

			class UIDataStore* StaticResolveDataStore( ScriptName DataStoreTag, class LocalPlayer* InPlayerOwner )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIRoot.StaticResolveDataStore" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )params = DataStoreTag;
				*( class LocalPlayer** )( params + 8 ) = InPlayerOwner;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class UIDataStore** )( params + function->return_val_offset() );
			}

			bool SetDataStoreFieldValue( ScriptArray< wchar_t > InDataStoreMarkup, void* &InFieldValue, class LocalPlayer* OwnerPlayer )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIRoot.SetDataStoreFieldValue" );
				byte *params = ( byte* )( malloc( 104 ) );
				*( ScriptArray< wchar_t >* )params = InDataStoreMarkup;
				*( void** )( params + 12 ) = InFieldValue;
				*( class LocalPlayer** )( params + 100 ) = OwnerPlayer;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				InFieldValue = *( void** )( params + 12 );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool GetDataStoreFieldValue( ScriptArray< wchar_t > InDataStoreMarkup, void* &OutFieldValue, class LocalPlayer* OwnerPlayer )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIRoot.GetDataStoreFieldValue" );
				byte *params = ( byte* )( malloc( 104 ) );
				*( ScriptArray< wchar_t >* )params = InDataStoreMarkup;
				*( void** )( params + 12 ) = OutFieldValue;
				*( class LocalPlayer** )( params + 100 ) = OwnerPlayer;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				OutFieldValue = *( void** )( params + 12 );
				return *( bool* )( params + function->return_val_offset() );
			}

			void* GetOnlineGameInterface(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIRoot.GetOnlineGameInterface" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			void* GetOnlinePlayerInterface(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIRoot.GetOnlinePlayerInterface" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			void* GetOnlinePlayerInterfaceEx(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIRoot.GetOnlinePlayerInterfaceEx" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
