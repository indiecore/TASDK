#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.UIDataStore_OnlineGameSearch." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.UIDataStore_OnlineGameSearch." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.UIDataStore_OnlineGameSearch." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UIDataStore_OnlineGameSearch : public UIDataStore_Remote
	{
	public:
			ADD_VAR( ::IntProperty, ActiveSearchIndex, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, SelectedIndex, 0xFFFFFFFF )
			ADD_OBJECT( OnlineSubsystem, OnlineSub )
			ADD_VAR( ::NameProperty, SearchResultsName, 0xFFFFFFFF )
			void Init(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore_OnlineGameSearch.Init" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool InvalidateCurrentSearchResults(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore_OnlineGameSearch.InvalidateCurrentSearchResults" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool SubmitGameSearch( byte ControllerIndex, bool bInvalidateExistingSearchResults )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore_OnlineGameSearch.SubmitGameSearch" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( byte* )params = ControllerIndex;
				*( bool* )( params + 4 ) = bInvalidateExistingSearchResults;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool OverrideQuerySubmission( byte ControllerId, class OnlineGameSearch* Search )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore_OnlineGameSearch.OverrideQuerySubmission" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( byte* )params = ControllerId;
				*( class OnlineGameSearch** )( params + 4 ) = Search;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void OnSearchComplete( bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore_OnlineGameSearch.OnSearchComplete" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool GetSearchResultFromIndex( int ListIndex, void* &Result )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore_OnlineGameSearch.GetSearchResultFromIndex" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( int* )params = ListIndex;
				*( void** )( params + 4 ) = Result;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Result = *( void** )( params + 4 );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool ShowHostGamercard( byte ControllerIndex, int ListIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore_OnlineGameSearch.ShowHostGamercard" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( byte* )params = ControllerIndex;
				*( int* )( params + 4 ) = ListIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void BuildSearchResults(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore_OnlineGameSearch.BuildSearchResults" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class OnlineGameSearch* GetCurrentGameSearch(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore_OnlineGameSearch.GetCurrentGameSearch" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class OnlineGameSearch** )( params + function->return_val_offset() );
			}

			class OnlineGameSearch* GetActiveGameSearch(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore_OnlineGameSearch.GetActiveGameSearch" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class OnlineGameSearch** )( params + function->return_val_offset() );
			}

			int FindSearchConfigurationIndex( ScriptName SearchTag )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore_OnlineGameSearch.FindSearchConfigurationIndex" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = SearchTag;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void SetCurrentByIndex( int NewIndex, bool bInvalidateExistingSearchResults )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore_OnlineGameSearch.SetCurrentByIndex" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = NewIndex;
				*( bool* )( params + 4 ) = bInvalidateExistingSearchResults;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetCurrentByName( ScriptName SearchName, bool bInvalidateExistingSearchResults )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore_OnlineGameSearch.SetCurrentByName" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )params = SearchName;
				*( bool* )( params + 8 ) = bInvalidateExistingSearchResults;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void MoveToNext( bool bInvalidateExistingSearchResults )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore_OnlineGameSearch.MoveToNext" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bInvalidateExistingSearchResults;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void MoveToPrevious( bool bInvalidateExistingSearchResults )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore_OnlineGameSearch.MoveToPrevious" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bInvalidateExistingSearchResults;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearAllSearchResults(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataStore_OnlineGameSearch.ClearAllSearchResults" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
