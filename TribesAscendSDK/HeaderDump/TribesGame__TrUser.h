#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrUser." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrUser." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrUser." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrUser : public Object
	{
	public:
			ADD_VAR( ::BoolProperty, m_DidLogin, 0x1 )
			ADD_VAR( ::IntProperty, m_ClassId, 0xFFFFFFFF )
			bool NeedsToSeeNewItemsClass( int ClassId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrUser.NeedsToSeeNewItemsClass" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = ClassId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool NeedsToSeeNewItemsType( int ClassId, int Type )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrUser.NeedsToSeeNewItemsType" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = ClassId;
				*( int* )( params + 4 ) = Type;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool NeedToSeeNewBundle( int ItemId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrUser.NeedToSeeNewBundle" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = ItemId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::StrProperty, CurrencyName, 0xFFFFFFFF )
			bool NeedsToSeeClanTags(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrUser.NeedsToSeeClanTags" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool NeedToSeeAnyNewItem(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrUser.NeedToSeeAnyNewItem" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::BoolProperty, m_SeenNewItemsMain, 0x20 )
			bool IsFavoriteServer( int ServerID )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrUser.IsFavoriteServer" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = ServerID;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool NeedsToSeeNewItem( int EquipId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrUser.NeedsToSeeNewItem" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = EquipId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::StrProperty, m_Username, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, m_Password, 0xFFFFFFFF )
			ScriptArray< wchar_t > DecryptPassword(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrUser.DecryptPassword" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::BoolProperty, m_ChoseRegion, 0x2 )
			ADD_VAR( ::BoolProperty, m_ChoseRegion2, 0x4 )
			ADD_VAR( ::BoolProperty, m_SeenNewBundlesMain, 0x40 )
			ADD_OBJECT( GFxTrMenuMoviePlayer, MainMenu )
			ADD_VAR( ::StrProperty, m_GameType, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, m_SeenNewGametype, 0x10 )
			ADD_VAR( ::BoolProperty, m_SeenClanTags, 0x8 )
			ADD_VAR( ::IntProperty, CurrencyCode, 0xFFFFFFFF )
			ScriptArray< wchar_t > EncryptPassword( ScriptArray< wchar_t > Password )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrUser.EncryptPassword" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = Password;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			void Initialize( class GFxTrMenuMoviePlayer* Movie )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrUser.Initialize" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GFxTrMenuMoviePlayer** )params = Movie;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SaveCredentials( ScriptArray< wchar_t > NewUserName, ScriptArray< wchar_t > NewPassword )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrUser.SaveCredentials" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptArray< wchar_t >* )params = NewUserName;
				*( ScriptArray< wchar_t >* )( params + 12 ) = NewPassword;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SaveClassId( int NewClassId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrUser.SaveClassId" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = NewClassId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SaveGameType( ScriptArray< wchar_t > NewGameType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrUser.SaveGameType" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = NewGameType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SaveDidLogin(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrUser.SaveDidLogin" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SaveChoseRegion(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrUser.SaveChoseRegion" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SeenNewGametype(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrUser.SeenNewGametype" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SeenNewItemsMain(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrUser.SeenNewItemsMain" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SeenNewBundlesMain(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrUser.SeenNewBundlesMain" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SeenClanTags(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrUser.SeenClanTags" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SeenNewBundle( int ItemId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrUser.SeenNewBundle" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = ItemId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SeenNewItemsClass( int ClassId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrUser.SeenNewItemsClass" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = ClassId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SeenNewItemsType( int ClassId, int Type )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrUser.SeenNewItemsType" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = ClassId;
				*( int* )( params + 4 ) = Type;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool NeedsToSeeNewBundle( int ItemId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrUser.NeedsToSeeNewBundle" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = ItemId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SetFavoriteServer( int ServerID )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrUser.SetFavoriteServer" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = ServerID;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
