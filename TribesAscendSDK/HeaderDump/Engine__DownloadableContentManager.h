#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.DownloadableContentManager." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.DownloadableContentManager." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.DownloadableContentManager." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class DownloadableContentManager : public Object
	{
	public:
			ADD_OBJECT( GameEngine, GameEngine )
			bool InstallDLC( void* &DLCBundle )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.DownloadableContentManager.InstallDLC" );
				byte *params = ( byte* )( malloc( 68 ) );
				*( void** )params = DLCBundle;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				DLCBundle = *( void** )params;
				return *( bool* )( params + function->return_val_offset() );
			}

			void InstallDLCs(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.DownloadableContentManager.InstallDLCs" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearDLC(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.DownloadableContentManager.ClearDLC" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool GetDLCTextureCachePath( ScriptName TextureCacheName, ScriptArray< wchar_t > &Path )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.DownloadableContentManager.GetDLCTextureCachePath" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptName* )params = TextureCacheName;
				*( ScriptArray< wchar_t >* )( params + 8 ) = Path;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Path = *( ScriptArray< wchar_t >* )( params + 8 );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AddSectionToObjectList( ScriptArray< wchar_t > Section )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.DownloadableContentManager.AddSectionToObjectList" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = Section;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void MarkPerObjectConfigPendingKill( ScriptArray< wchar_t > Section )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.DownloadableContentManager.MarkPerObjectConfigPendingKill" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = Section;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateObjectLists(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.DownloadableContentManager.UpdateObjectLists" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void InstallPackages( void* &DLCBundle )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.DownloadableContentManager.InstallPackages" );
				byte *params = ( byte* )( malloc( 68 ) );
				*( void** )params = DLCBundle;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				DLCBundle = *( void** )params;
			}

			void InstallNonPackageFiles( void* &DLCBundle )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.DownloadableContentManager.InstallNonPackageFiles" );
				byte *params = ( byte* )( malloc( 68 ) );
				*( void** )params = DLCBundle;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				DLCBundle = *( void** )params;
			}

			void Init(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.DownloadableContentManager.Init" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnLoginChange( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.DownloadableContentManager.OnLoginChange" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnStorageDeviceChange(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.DownloadableContentManager.OnStorageDeviceChange" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnContentChange(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.DownloadableContentManager.OnContentChange" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RefreshDLC(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.DownloadableContentManager.RefreshDLC" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RefreshDLCEnumComplete(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.DownloadableContentManager.RefreshDLCEnumComplete" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddPackagesToFullyLoad( ScriptArray< wchar_t > Filename )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.DownloadableContentManager.AddPackagesToFullyLoad" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = Filename;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
