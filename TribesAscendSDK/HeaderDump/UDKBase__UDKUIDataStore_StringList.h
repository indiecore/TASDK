#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UDKBase.UDKUIDataStore_StringList." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UDKBase.UDKUIDataStore_StringList." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UDKBase.UDKUIDataStore_StringList." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UDKUIDataStore_StringList : public UIDataStore_StringBase
	{
	public:
			void Registered( class LocalPlayer* PlayerOwner )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKUIDataStore_StringList.Registered" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class LocalPlayer** )params = PlayerOwner;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int GetFieldIndex( ScriptName FieldName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKUIDataStore_StringList.GetFieldIndex" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = FieldName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void AddStr( ScriptName FieldName, ScriptArray< wchar_t > NewString, bool bBatchOp )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKUIDataStore_StringList.AddStr" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptName* )params = FieldName;
				*( ScriptArray< wchar_t >* )( params + 8 ) = NewString;
				*( bool* )( params + 20 ) = bBatchOp;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void InsertStr( ScriptName FieldName, ScriptArray< wchar_t > NewString, int InsertIndex, bool bBatchOp )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKUIDataStore_StringList.InsertStr" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( ScriptName* )params = FieldName;
				*( ScriptArray< wchar_t >* )( params + 8 ) = NewString;
				*( int* )( params + 20 ) = InsertIndex;
				*( bool* )( params + 24 ) = bBatchOp;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RemoveStr( ScriptName FieldName, ScriptArray< wchar_t > StringToRemove, bool bBatchOp )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKUIDataStore_StringList.RemoveStr" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptName* )params = FieldName;
				*( ScriptArray< wchar_t >* )( params + 8 ) = StringToRemove;
				*( bool* )( params + 20 ) = bBatchOp;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RemoveStrByIndex( ScriptName FieldName, int Index, int Count, bool bBatchOp )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKUIDataStore_StringList.RemoveStrByIndex" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptName* )params = FieldName;
				*( int* )( params + 8 ) = Index;
				*( int* )( params + 12 ) = Count;
				*( bool* )( params + 16 ) = bBatchOp;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Empty( ScriptName FieldName, bool bBatchOp )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKUIDataStore_StringList.Empty" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )params = FieldName;
				*( bool* )( params + 8 ) = bBatchOp;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int FindStr( ScriptName FieldName, ScriptArray< wchar_t > SearchString )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKUIDataStore_StringList.FindStr" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptName* )params = FieldName;
				*( ScriptArray< wchar_t >* )( params + 8 ) = SearchString;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > GetStr( ScriptName FieldName, int StrIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKUIDataStore_StringList.GetStr" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )params = FieldName;
				*( int* )( params + 8 ) = StrIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			void* GetList( ScriptName FieldName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKUIDataStore_StringList.GetList" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = FieldName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			bool GetCurrentValue( ScriptName FieldName, ScriptArray< wchar_t > &out_Value )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKUIDataStore_StringList.GetCurrentValue" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptName* )params = FieldName;
				*( ScriptArray< wchar_t >* )( params + 8 ) = out_Value;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_Value = *( ScriptArray< wchar_t >* )( params + 8 );
				return *( bool* )( params + function->return_val_offset() );
			}

			int GetCurrentValueIndex( ScriptName FieldName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKUIDataStore_StringList.GetCurrentValueIndex" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = FieldName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			int SetCurrentValueIndex( ScriptName FieldName, int NewValueIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKUIDataStore_StringList.SetCurrentValueIndex" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )params = FieldName;
				*( int* )( params + 8 ) = NewValueIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			int Num( ScriptName FieldName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKUIDataStore_StringList.Num" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = FieldName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
