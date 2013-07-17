#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrStreamManager." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrStreamManager." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrStreamManager." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrStreamManager : public Object
	{
	public:
			ScriptArray< wchar_t > GetTitleAtIndex( int Index )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrStreamManager.GetTitleAtIndex" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = Index;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			bool IsLiveAtIndex( int Index )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrStreamManager.IsLiveAtIndex" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = Index;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > GetViewersAtIndex( int Index )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrStreamManager.GetViewersAtIndex" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = Index;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > GetDescriptionAtIndex( int Index )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrStreamManager.GetDescriptionAtIndex" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = Index;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			bool HaveFeature(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrStreamManager.HaveFeature" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > GetFeatureName( int Count )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrStreamManager.GetFeatureName" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = Count;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			bool IsStream( int Index )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrStreamManager.IsStream" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = Index;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			int GetTypeCountWatching( byte Type )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrStreamManager.GetTypeCountWatching" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = Type;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			int GetTypeCount( byte Type )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrStreamManager.GetTypeCount" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = Type;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > GetFeatureDescription( int Count )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrStreamManager.GetFeatureDescription" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = Count;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			int ViewerSort( void* A, void* B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrStreamManager.ViewerSort" );
				byte *params = ( byte* )( malloc( 136 ) );
				*( void** )( params + 0 ) = A;
				*( void** )( params + 68 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::StrProperty, StreamServer, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, StreamPath, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, StreamURL, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, WatchEnd, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, WatchStart, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, TokViewers, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, TokTitle, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, TokName, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, NewsIndex, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bUpdateReady, 0x1 )
			void LoadStreams(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrStreamManager.LoadStreams" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void GetStreamData(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrStreamManager.GetStreamData" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OpenStream( ScriptArray< wchar_t > URL )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrStreamManager.OpenStream" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = URL;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Initialize(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrStreamManager.Initialize" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ViewStreamIndex( int Index )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrStreamManager.ViewStreamIndex" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = Index;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ViewVideoIndex( int Index )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrStreamManager.ViewVideoIndex" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = Index;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StartTVTimer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrStreamManager.StartTVTimer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateStreams( bool bForce )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrStreamManager.UpdateStreams" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bForce;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CheckForUpdate( bool bRunIfReady )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrStreamManager.CheckForUpdate" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bRunIfReady;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void GetLatestNews(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrStreamManager.GetLatestNews" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CompleteUpdate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrStreamManager.CompleteUpdate" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
