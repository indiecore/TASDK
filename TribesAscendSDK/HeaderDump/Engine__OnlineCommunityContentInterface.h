#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.OnlineCommunityContentInterface." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.OnlineCommunityContentInterface." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.OnlineCommunityContentInterface." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class OnlineCommunityContentInterface : public Interface
	{
	public:
			bool Init(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineCommunityContentInterface.Init" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void Exit(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineCommunityContentInterface.Exit" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool ReadContentList( byte PlayerNum, int StartAt, int NumToRead )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineCommunityContentInterface.ReadContentList" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( byte* )params = PlayerNum;
				*( int* )( params + 4 ) = StartAt;
				*( int* )( params + 8 ) = NumToRead;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void OnReadContentListComplete( bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineCommunityContentInterface.OnReadContentListComplete" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnGetContentPayloadComplete( bool bWasSuccessful, void* FileDownloaded )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineCommunityContentInterface.OnGetContentPayloadComplete" );
				byte *params = ( byte* )( malloc( 68 ) );
				*( bool* )params = bWasSuccessful;
				*( void** )( params + 4 ) = FileDownloaded;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnDownloadContentComplete( bool bWasSuccessful, void* FileDownloaded )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineCommunityContentInterface.OnDownloadContentComplete" );
				byte *params = ( byte* )( malloc( 56 ) );
				*( bool* )params = bWasSuccessful;
				*( void** )( params + 4 ) = FileDownloaded;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnUploadContentComplete( bool bWasSuccessful, void* UploadedFile )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineCommunityContentInterface.OnUploadContentComplete" );
				byte *params = ( byte* )( malloc( 56 ) );
				*( bool* )params = bWasSuccessful;
				*( void** )( params + 4 ) = UploadedFile;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnReadFriendsContentListComplete( bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineCommunityContentInterface.OnReadFriendsContentListComplete" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddReadContentListCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineCommunityContentInterface.AddReadContentListCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearReadContentListCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineCommunityContentInterface.ClearReadContentListCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool GetContentList( byte PlayerNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineCommunityContentInterface.GetContentList" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )params = PlayerNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool ReadFriendsContentList( byte PlayerNum, int StartAt, int NumToRead )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineCommunityContentInterface.ReadFriendsContentList" );
				byte *params = ( byte* )( malloc( 21 ) );
				*( byte* )params = PlayerNum;
				*( int* )( params + 16 ) = StartAt;
				*( int* )( params + 20 ) = NumToRead;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AddReadFriendsContentListCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineCommunityContentInterface.AddReadFriendsContentListCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearReadFriendsContentListCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineCommunityContentInterface.ClearReadFriendsContentListCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool GetFriendsContentList( byte PlayerNum, void* &Friend )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineCommunityContentInterface.GetFriendsContentList" );
				byte *params = ( byte* )( malloc( 61 ) );
				*( byte* )params = PlayerNum;
				*( void** )( params + 4 ) = Friend;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Friend = *( void** )( params + 4 );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool UploadContent( byte PlayerNum, void* &MetaData )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineCommunityContentInterface.UploadContent" );
				byte *params = ( byte* )( malloc( 29 ) );
				*( byte* )params = PlayerNum;
				*( void** )( params + 16 ) = MetaData;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				MetaData = *( void** )( params + 16 );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AddUploadContentCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineCommunityContentInterface.AddUploadContentCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearUploadContentCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineCommunityContentInterface.ClearUploadContentCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool DownloadContent( byte PlayerNum, void* &FileToDownload )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineCommunityContentInterface.DownloadContent" );
				byte *params = ( byte* )( malloc( 53 ) );
				*( byte* )params = PlayerNum;
				*( void** )( params + 4 ) = FileToDownload;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				FileToDownload = *( void** )( params + 4 );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AddDownloadContentCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineCommunityContentInterface.AddDownloadContentCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearDownloadContentCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineCommunityContentInterface.ClearDownloadContentCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool GetContentPayload( byte PlayerNum, void* &FileDownloaded )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineCommunityContentInterface.GetContentPayload" );
				byte *params = ( byte* )( malloc( 53 ) );
				*( byte* )params = PlayerNum;
				*( void** )( params + 4 ) = FileDownloaded;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				FileDownloaded = *( void** )( params + 4 );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AddGetContentPayloadCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineCommunityContentInterface.AddGetContentPayloadCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearGetContentPayloadCompleteDelegate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineCommunityContentInterface.ClearGetContentPayloadCompleteDelegate" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RateContent( byte PlayerNum, void* &FileToRate, int NewRating )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineCommunityContentInterface.RateContent" );
				byte *params = ( byte* )( malloc( 57 ) );
				*( byte* )params = PlayerNum;
				*( void** )( params + 4 ) = FileToRate;
				*( int* )( params + 56 ) = NewRating;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				FileToRate = *( void** )( params + 4 );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
