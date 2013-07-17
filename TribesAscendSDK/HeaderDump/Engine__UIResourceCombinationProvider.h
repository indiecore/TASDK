#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.UIResourceCombinationProvider." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.UIResourceCombinationProvider." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.UIResourceCombinationProvider." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UIResourceCombinationProvider : public UIDataProvider
	{
	public:
			ADD_OBJECT( UIDataProvider_OnlineProfileSettings, ProfileProvider )
			ADD_OBJECT( UIResourceDataProvider, StaticDataProvider )
			void InitializeProvider( bool bIsEditor, class UIResourceDataProvider* InStaticResourceProvider, class UIDataProvider_OnlineProfileSettings* InProfileProvider )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIResourceCombinationProvider.InitializeProvider" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( bool* )( params + 0 ) = bIsEditor;
				*( class UIResourceDataProvider** )( params + 4 ) = InStaticResourceProvider;
				*( class UIDataProvider_OnlineProfileSettings** )( params + 8 ) = InProfileProvider;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void* GetElementProviderTags(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIResourceCombinationProvider.GetElementProviderTags" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			int GetElementCount( ScriptName FieldName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIResourceCombinationProvider.GetElementCount" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = FieldName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			bool GetListElements( ScriptName FieldName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIResourceCombinationProvider.GetListElements" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptName* )( params + 0 ) = FieldName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool IsElementEnabled( ScriptName FieldName, int CollectionIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIResourceCombinationProvider.IsElementEnabled" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )( params + 0 ) = FieldName;
				*( int* )( params + 8 ) = CollectionIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool GetElementCellSchemaProvider( ScriptName FieldName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIResourceCombinationProvider.GetElementCellSchemaProvider" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptName* )( params + 0 ) = FieldName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool GetElementCellValueProvider( ScriptName FieldName, int ListIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIResourceCombinationProvider.GetElementCellValueProvider" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptName* )( params + 0 ) = FieldName;
				*( int* )( params + 8 ) = ListIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void GetElementCellTags( ScriptName FieldName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIResourceCombinationProvider.GetElementCellTags" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( ScriptName* )( params + 0 ) = FieldName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool GetCellFieldType( ScriptName FieldName, ScriptName CellTag, byte &FieldType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIResourceCombinationProvider.GetCellFieldType" );
				byte *params = ( byte* )( malloc( 17 ) );
				*( ScriptName* )( params + 0 ) = FieldName;
				*( ScriptName* )( params + 8 ) = CellTag;
				*( byte* )( params + 16 ) = FieldType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				FieldType = *( byte* )( params + 16 );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool GetCellFieldValue( ScriptName FieldName, ScriptName CellTag, int ListIndex, void* &out_FieldValue, int ArrayIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIResourceCombinationProvider.GetCellFieldValue" );
				byte *params = ( byte* )( malloc( 112 ) );
				*( ScriptName* )( params + 0 ) = FieldName;
				*( ScriptName* )( params + 8 ) = CellTag;
				*( int* )( params + 16 ) = ListIndex;
				*( void** )( params + 20 ) = out_FieldValue;
				*( int* )( params + 108 ) = ArrayIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_FieldValue = *( void** )( params + 20 );
				return *( bool* )( params + function->return_val_offset() );
			}

			void ClearProviderReferences(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIResourceCombinationProvider.ClearProviderReferences" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool ReplaceProviderValue( ScriptName TargetFieldTag, class UIDataProvider* ReplacementProvider )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIResourceCombinationProvider.ReplaceProviderValue" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptName* )( params + 12 ) = TargetFieldTag;
				*( class UIDataProvider** )( params + 20 ) = ReplacementProvider;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool ReplaceProviderCollection( ScriptName TargetFieldTag )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIResourceCombinationProvider.ReplaceProviderCollection" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( ScriptName* )( params + 12 ) = TargetFieldTag;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
