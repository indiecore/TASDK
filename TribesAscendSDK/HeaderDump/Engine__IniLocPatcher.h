#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.IniLocPatcher." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.IniLocPatcher." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.IniLocPatcher." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class IniLocPatcher : public Object
	{
	public:
			void OnReadTitleFileComplete( bool bWasSuccessful, ScriptArray< wchar_t > Filename )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.IniLocPatcher.OnReadTitleFileComplete" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( bool* )params = bWasSuccessful;
				*( ScriptArray< wchar_t >* )( params + 4 ) = Filename;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Init(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.IniLocPatcher.Init" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DownloadFiles(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.IniLocPatcher.DownloadFiles" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnReadFileComplete( bool bWasSuccessful, ScriptArray< wchar_t > Filename )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.IniLocPatcher.OnReadFileComplete" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( bool* )params = bWasSuccessful;
				*( ScriptArray< wchar_t >* )( params + 4 ) = Filename;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ProcessIniLocFile( ScriptArray< wchar_t > Filename )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.IniLocPatcher.ProcessIniLocFile" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptArray< wchar_t >* )params = Filename;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddFileToDownload( ScriptArray< wchar_t > Filename )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.IniLocPatcher.AddFileToDownload" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = Filename;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddReadFileDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.IniLocPatcher.AddReadFileDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearReadFileDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.IniLocPatcher.ClearReadFileDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearCachedFiles(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.IniLocPatcher.ClearCachedFiles" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ScriptArray< wchar_t > UpdateLocFileName( ScriptArray< wchar_t > Filename )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.IniLocPatcher.UpdateLocFileName" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = Filename;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
