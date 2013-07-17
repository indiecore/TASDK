#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.OnlineContentInterface." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.OnlineContentInterface." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.OnlineContentInterface." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class OnlineContentInterface : public Interface
	{
	public:
			void OnContentChange(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineContentInterface.OnContentChange" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnWriteSaveGameDataComplete( bool bWasSuccessful, byte LocalUserNum, int DeviceID, ScriptArray< wchar_t > FriendlyName, ScriptArray< wchar_t > Filename, ScriptArray< wchar_t > SaveFileName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineContentInterface.OnWriteSaveGameDataComplete" );
				byte *params = ( byte* )( malloc( 45 ) );
				*( bool* )( params + 0 ) = bWasSuccessful;
				*( byte* )( params + 4 ) = LocalUserNum;
				*( int* )( params + 8 ) = DeviceID;
				*( ScriptArray< wchar_t >* )( params + 12 ) = FriendlyName;
				*( ScriptArray< wchar_t >* )( params + 24 ) = Filename;
				*( ScriptArray< wchar_t >* )( params + 36 ) = SaveFileName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnReadSaveGameDataComplete( bool bWasSuccessful, byte LocalUserNum, int DeviceID, ScriptArray< wchar_t > FriendlyName, ScriptArray< wchar_t > Filename, ScriptArray< wchar_t > SaveFileName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineContentInterface.OnReadSaveGameDataComplete" );
				byte *params = ( byte* )( malloc( 45 ) );
				*( bool* )( params + 0 ) = bWasSuccessful;
				*( byte* )( params + 4 ) = LocalUserNum;
				*( int* )( params + 8 ) = DeviceID;
				*( ScriptArray< wchar_t >* )( params + 12 ) = FriendlyName;
				*( ScriptArray< wchar_t >* )( params + 24 ) = Filename;
				*( ScriptArray< wchar_t >* )( params + 36 ) = SaveFileName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnQueryAvailableDownloadsComplete( bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineContentInterface.OnQueryAvailableDownloadsComplete" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnReadContentComplete( bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineContentInterface.OnReadContentComplete" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddContentChangeDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineContentInterface.AddContentChangeDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 12 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearContentChangeDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineContentInterface.ClearContentChangeDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 12 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddReadContentComplete( byte LocalUserNum, byte ContentType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineContentInterface.AddReadContentComplete" );
				byte *params = ( byte* )( malloc( 14 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				*( byte* )( params + 1 ) = ContentType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearReadContentComplete( byte LocalUserNum, byte ContentType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineContentInterface.ClearReadContentComplete" );
				byte *params = ( byte* )( malloc( 14 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				*( byte* )( params + 1 ) = ContentType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool ReadContentList( byte LocalUserNum, byte ContentType, int DeviceID )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineContentInterface.ReadContentList" );
				byte *params = ( byte* )( malloc( 6 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				*( byte* )( params + 1 ) = ContentType;
				*( int* )( params + 4 ) = DeviceID;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void ClearContentList( byte LocalUserNum, byte ContentType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineContentInterface.ClearContentList" );
				byte *params = ( byte* )( malloc( 2 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				*( byte* )( params + 1 ) = ContentType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			byte GetContentList( byte LocalUserNum, byte ContentType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineContentInterface.GetContentList" );
				byte *params = ( byte* )( malloc( 14 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				*( byte* )( params + 1 ) = ContentType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

			bool QueryAvailableDownloads( byte LocalUserNum, int CategoryMask )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineContentInterface.QueryAvailableDownloads" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				*( int* )( params + 4 ) = CategoryMask;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AddQueryAvailableDownloadsComplete( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineContentInterface.AddQueryAvailableDownloadsComplete" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearQueryAvailableDownloadsComplete( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineContentInterface.ClearQueryAvailableDownloadsComplete" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void GetAvailableDownloadCounts( byte LocalUserNum, int &NewDownloads, int &TotalDownloads )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineContentInterface.GetAvailableDownloadCounts" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				*( int* )( params + 4 ) = NewDownloads;
				*( int* )( params + 8 ) = TotalDownloads;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				NewDownloads = *( int* )( params + 4 );
				TotalDownloads = *( int* )( params + 8 );
			}

			bool ReadSaveGameData( byte LocalUserNum, int DeviceID, ScriptArray< wchar_t > FriendlyName, ScriptArray< wchar_t > Filename, ScriptArray< wchar_t > SaveFileName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineContentInterface.ReadSaveGameData" );
				byte *params = ( byte* )( malloc( 41 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				*( int* )( params + 4 ) = DeviceID;
				*( ScriptArray< wchar_t >* )( params + 8 ) = FriendlyName;
				*( ScriptArray< wchar_t >* )( params + 20 ) = Filename;
				*( ScriptArray< wchar_t >* )( params + 32 ) = SaveFileName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool GetSaveGameData( byte LocalUserNum, int DeviceID, ScriptArray< wchar_t > FriendlyName, ScriptArray< wchar_t > Filename, ScriptArray< wchar_t > SaveFileName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineContentInterface.GetSaveGameData" );
				byte *params = ( byte* )( malloc( 53 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				*( int* )( params + 4 ) = DeviceID;
				*( ScriptArray< wchar_t >* )( params + 8 ) = FriendlyName;
				*( ScriptArray< wchar_t >* )( params + 20 ) = Filename;
				*( ScriptArray< wchar_t >* )( params + 32 ) = SaveFileName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AddReadSaveGameDataComplete( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineContentInterface.AddReadSaveGameDataComplete" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearReadSaveGameDataComplete( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineContentInterface.ClearReadSaveGameDataComplete" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool WriteSaveGameData( byte LocalUserNum, int DeviceID, ScriptArray< wchar_t > FriendlyName, ScriptArray< wchar_t > Filename, ScriptArray< wchar_t > SaveFileName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineContentInterface.WriteSaveGameData" );
				byte *params = ( byte* )( malloc( 53 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				*( int* )( params + 4 ) = DeviceID;
				*( ScriptArray< wchar_t >* )( params + 8 ) = FriendlyName;
				*( ScriptArray< wchar_t >* )( params + 20 ) = Filename;
				*( ScriptArray< wchar_t >* )( params + 32 ) = SaveFileName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AddWriteSaveGameDataComplete( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineContentInterface.AddWriteSaveGameDataComplete" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearWriteSaveGameDataComplete( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineContentInterface.ClearWriteSaveGameDataComplete" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool DeleteSaveGame( byte LocalUserNum, int DeviceID, ScriptArray< wchar_t > FriendlyName, ScriptArray< wchar_t > Filename )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineContentInterface.DeleteSaveGame" );
				byte *params = ( byte* )( malloc( 29 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				*( int* )( params + 4 ) = DeviceID;
				*( ScriptArray< wchar_t >* )( params + 8 ) = FriendlyName;
				*( ScriptArray< wchar_t >* )( params + 20 ) = Filename;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool ClearSaveGames( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineContentInterface.ClearSaveGames" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
