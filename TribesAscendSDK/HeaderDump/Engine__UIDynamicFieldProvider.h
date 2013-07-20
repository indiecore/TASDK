#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.UIDynamicFieldProvider." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.UIDynamicFieldProvider." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.UIDynamicFieldProvider." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UIDynamicFieldProvider : public UIDataProvider
	{
	public:
			void InitializeRuntimeFields(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDynamicFieldProvider.InitializeRuntimeFields" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool AddField( ScriptName FieldName, byte FieldType, bool bPersistent, int &out_InsertPosition )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDynamicFieldProvider.AddField" );
				byte *params = ( byte* )( malloc( 17 ) );
				*( ScriptName* )params = FieldName;
				*( byte* )( params + 8 ) = FieldType;
				*( bool* )( params + 12 ) = bPersistent;
				*( int* )( params + 16 ) = out_InsertPosition;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_InsertPosition = *( int* )( params + 16 );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool RemoveField( ScriptName FieldName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDynamicFieldProvider.RemoveField" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = FieldName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			int FindFieldIndex( ScriptName FieldName, bool bSearchPersistentFields )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDynamicFieldProvider.FindFieldIndex" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )params = FieldName;
				*( bool* )( params + 8 ) = bSearchPersistentFields;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			bool ClearFields( bool bReinitializeRuntimeFields )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDynamicFieldProvider.ClearFields" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bReinitializeRuntimeFields;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool GetField( ScriptName FieldName, void* &out_Field )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDynamicFieldProvider.GetField" );
				byte *params = ( byte* )( malloc( 92 ) );
				*( ScriptName* )params = FieldName;
				*( void** )( params + 8 ) = out_Field;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_Field = *( void** )( params + 8 );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool SetField( ScriptName FieldName, void* &FieldValue, bool bChangeExistingOnly )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDynamicFieldProvider.SetField" );
				byte *params = ( byte* )( malloc( 96 ) );
				*( ScriptName* )params = FieldName;
				*( void** )( params + 8 ) = FieldValue;
				*( bool* )( params + 92 ) = bChangeExistingOnly;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				FieldValue = *( void** )( params + 8 );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SavePersistentProviderData(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDynamicFieldProvider.SavePersistentProviderData" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool GetCollectionValueSchema( ScriptName FieldName, bool bPersistent )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDynamicFieldProvider.GetCollectionValueSchema" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptName* )params = FieldName;
				*( bool* )( params + 20 ) = bPersistent;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool GetCollectionValueArray( ScriptName FieldName, bool bPersistent, ScriptName CellTag )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDynamicFieldProvider.GetCollectionValueArray" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( ScriptName* )params = FieldName;
				*( bool* )( params + 20 ) = bPersistent;
				*( ScriptName* )( params + 24 ) = CellTag;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool SetCollectionValueArray( ScriptName FieldName, bool bClearExisting, int InsertIndex, bool bPersistent, ScriptName CellTag )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDynamicFieldProvider.SetCollectionValueArray" );
				byte *params = ( byte* )( malloc( 40 ) );
				*( ScriptName* )params = FieldName;
				*( bool* )( params + 20 ) = bClearExisting;
				*( int* )( params + 24 ) = InsertIndex;
				*( bool* )( params + 28 ) = bPersistent;
				*( ScriptName* )( params + 32 ) = CellTag;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool InsertCollectionValue( ScriptName FieldName, ScriptArray< wchar_t > &NewValue, int InsertIndex, bool bPersistent, bool bAllowDuplicateValues, ScriptName CellTag )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDynamicFieldProvider.InsertCollectionValue" );
				byte *params = ( byte* )( malloc( 40 ) );
				*( ScriptName* )params = FieldName;
				*( ScriptArray< wchar_t >* )( params + 8 ) = NewValue;
				*( int* )( params + 20 ) = InsertIndex;
				*( bool* )( params + 24 ) = bPersistent;
				*( bool* )( params + 28 ) = bAllowDuplicateValues;
				*( ScriptName* )( params + 32 ) = CellTag;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				NewValue = *( ScriptArray< wchar_t >* )( params + 8 );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool RemoveCollectionValue( ScriptName FieldName, ScriptArray< wchar_t > &ValueToRemove, bool bPersistent, ScriptName CellTag )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDynamicFieldProvider.RemoveCollectionValue" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( ScriptName* )params = FieldName;
				*( ScriptArray< wchar_t >* )( params + 8 ) = ValueToRemove;
				*( bool* )( params + 20 ) = bPersistent;
				*( ScriptName* )( params + 24 ) = CellTag;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				ValueToRemove = *( ScriptArray< wchar_t >* )( params + 8 );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool RemoveCollectionValueByIndex( ScriptName FieldName, int ValueIndex, bool bPersistent, ScriptName CellTag )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDynamicFieldProvider.RemoveCollectionValueByIndex" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptName* )params = FieldName;
				*( int* )( params + 8 ) = ValueIndex;
				*( bool* )( params + 12 ) = bPersistent;
				*( ScriptName* )( params + 16 ) = CellTag;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool ReplaceCollectionValue( ScriptName FieldName, ScriptArray< wchar_t > &CurrentValue, ScriptArray< wchar_t > &NewValue, bool bPersistent, ScriptName CellTag )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDynamicFieldProvider.ReplaceCollectionValue" );
				byte *params = ( byte* )( malloc( 44 ) );
				*( ScriptName* )params = FieldName;
				*( ScriptArray< wchar_t >* )( params + 8 ) = CurrentValue;
				*( ScriptArray< wchar_t >* )( params + 20 ) = NewValue;
				*( bool* )( params + 32 ) = bPersistent;
				*( ScriptName* )( params + 36 ) = CellTag;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				CurrentValue = *( ScriptArray< wchar_t >* )( params + 8 );
				NewValue = *( ScriptArray< wchar_t >* )( params + 20 );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool ReplaceCollectionValueByIndex( ScriptName FieldName, int ValueIndex, ScriptArray< wchar_t > &NewValue, bool bPersistent, ScriptName CellTag )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDynamicFieldProvider.ReplaceCollectionValueByIndex" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( ScriptName* )params = FieldName;
				*( int* )( params + 8 ) = ValueIndex;
				*( ScriptArray< wchar_t >* )( params + 12 ) = NewValue;
				*( bool* )( params + 24 ) = bPersistent;
				*( ScriptName* )( params + 28 ) = CellTag;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				NewValue = *( ScriptArray< wchar_t >* )( params + 12 );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool ClearCollectionValueArray( ScriptName FieldName, bool bPersistent, ScriptName CellTag )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDynamicFieldProvider.ClearCollectionValueArray" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptName* )params = FieldName;
				*( bool* )( params + 8 ) = bPersistent;
				*( ScriptName* )( params + 12 ) = CellTag;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool GetCollectionValue( ScriptName FieldName, int ValueIndex, ScriptArray< wchar_t > &out_Value, bool bPersistent, ScriptName CellTag )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDynamicFieldProvider.GetCollectionValue" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( ScriptName* )params = FieldName;
				*( int* )( params + 8 ) = ValueIndex;
				*( ScriptArray< wchar_t >* )( params + 12 ) = out_Value;
				*( bool* )( params + 24 ) = bPersistent;
				*( ScriptName* )( params + 28 ) = CellTag;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_Value = *( ScriptArray< wchar_t >* )( params + 12 );
				return *( bool* )( params + function->return_val_offset() );
			}

			int FindCollectionValueIndex( ScriptName FieldName, ScriptArray< wchar_t > &ValueToFind, bool bPersistent, ScriptName CellTag )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDynamicFieldProvider.FindCollectionValueIndex" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( ScriptName* )params = FieldName;
				*( ScriptArray< wchar_t >* )( params + 8 ) = ValueToFind;
				*( bool* )( params + 20 ) = bPersistent;
				*( ScriptName* )( params + 24 ) = CellTag;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				ValueToFind = *( ScriptArray< wchar_t >* )( params + 8 );
				return *( int* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
