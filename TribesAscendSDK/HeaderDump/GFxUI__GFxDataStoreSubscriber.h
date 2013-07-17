#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " GFxUI.GFxDataStoreSubscriber." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty GFxUI.GFxDataStoreSubscriber." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty GFxUI.GFxDataStoreSubscriber." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GFxDataStoreSubscriber : public Object
	{
	public:
			ADD_OBJECT( GFxMoviePlayer, Movie )
			void PublishValues(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxDataStoreSubscriber.PublishValues" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetDataStoreBinding( ScriptArray< wchar_t > MarkupText, int BindingIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxDataStoreSubscriber.SetDataStoreBinding" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = MarkupText;
				*( int* )( params + 12 ) = BindingIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ScriptArray< wchar_t > GetDataStoreBinding( int BindingIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxDataStoreSubscriber.GetDataStoreBinding" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = BindingIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			bool RefreshSubscriberValue( int BindingIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxDataStoreSubscriber.RefreshSubscriberValue" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = BindingIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void NotifyDataStoreValueUpdated( class UIDataStore* SourceDataStore, bool bValuesInvalidated, ScriptName PropertyTag, class UIDataProvider* SourceProvider, int ArrayIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxDataStoreSubscriber.NotifyDataStoreValueUpdated" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( class UIDataStore** )( params + 0 ) = SourceDataStore;
				*( bool* )( params + 4 ) = bValuesInvalidated;
				*( ScriptName* )( params + 8 ) = PropertyTag;
				*( class UIDataProvider** )( params + 16 ) = SourceProvider;
				*( int* )( params + 20 ) = ArrayIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void GetBoundDataStores(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxDataStoreSubscriber.GetBoundDataStores" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearBoundDataStores(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxDataStoreSubscriber.ClearBoundDataStores" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool SaveSubscriberValue( int BindingIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxDataStoreSubscriber.SaveSubscriberValue" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( int* )( params + 12 ) = BindingIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
