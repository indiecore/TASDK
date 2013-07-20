#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.GFxTrPage_PlayNow." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.GFxTrPage_PlayNow." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.GFxTrPage_PlayNow." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GFxTrPage_PlayNow : public GFxTrPage
	{
	public:
			ADD_VAR( ::StrProperty, SeasonUpcomingSubtext, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, NoFriendsOnlineLabel, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, RegionsSubtext, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, RegionsLabel, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, RankedLabel, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, CustomServerLabel, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, JoinFriendLabel, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, JoinFriendInGameSubLabel, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, JoinFriendSubLabel, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, CustomServerSubtext, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, ComingSoonSubtext, 0xFFFFFFFF )
			int GetMeshEnumFromVV( int InVal )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage_PlayNow.GetMeshEnumFromVV" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = InVal;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void Initialize(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage_PlayNow.Initialize" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SpecialAction( class GFxTrAction* Action )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage_PlayNow.SpecialAction" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GFxTrAction** )params = Action;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int TakeAction( int ActionIndex, class GFxObject* DataList )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage_PlayNow.TakeAction" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = ActionIndex;
				*( class GFxObject** )( params + 4 ) = DataList;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void RefreshButtons(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage_PlayNow.RefreshButtons" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FillData( class GFxObject* DataList )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage_PlayNow.FillData" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GFxObject** )params = DataList;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RemoveDuplicateQueues(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage_PlayNow.RemoveDuplicateQueues" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool HaveDuplicates( int Index )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage_PlayNow.HaveDuplicates" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = Index;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			class GFxObject* FillOption( int ActionIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage_PlayNow.FillOption" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = ActionIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class GFxObject** )( params + function->return_val_offset() );
			}

			int TakeFocus( int ActionIndex, class GFxObject* DataList )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrPage_PlayNow.TakeFocus" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = ActionIndex;
				*( class GFxObject** )( params + 4 ) = DataList;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
