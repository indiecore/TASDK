#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.OnlineTitleFileInterface." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.OnlineTitleFileInterface." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.OnlineTitleFileInterface." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class OnlineTitleFileInterface : public Interface
	{
	public:
			bool ReadTitleFile( ScriptArray< wchar_t > FileToRead )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineTitleFileInterface.ReadTitleFile" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = FileToRead;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool GetTitleFileContents( ScriptArray< wchar_t > Filename )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineTitleFileInterface.GetTitleFileContents" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptArray< wchar_t >* )params = Filename;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool ClearDownloadedFiles(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineTitleFileInterface.ClearDownloadedFiles" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void OnReadTitleFileComplete( bool bWasSuccessful, ScriptArray< wchar_t > Filename )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineTitleFileInterface.OnReadTitleFileComplete" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( bool* )params = bWasSuccessful;
				*( ScriptArray< wchar_t >* )( params + 4 ) = Filename;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddReadTitleFileCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineTitleFileInterface.AddReadTitleFileCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearReadTitleFileCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineTitleFileInterface.ClearReadTitleFileCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			byte GetTitleFileState( ScriptArray< wchar_t > Filename )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineTitleFileInterface.GetTitleFileState" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = Filename;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

			bool ClearDownloadedFile( ScriptArray< wchar_t > Filename )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineTitleFileInterface.ClearDownloadedFile" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = Filename;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
