#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.OnlinePlayerInterfaceEx." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.OnlinePlayerInterfaceEx." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.OnlinePlayerInterfaceEx." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class OnlinePlayerInterfaceEx : public Interface
	{
	public:
			bool ShowFeedbackUI( byte LocalUserNum, void* PlayerID )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterfaceEx.ShowFeedbackUI" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( byte* )params = LocalUserNum;
				*( void** )( params + 4 ) = PlayerID;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool ShowGamerCardUI( byte LocalUserNum, void* PlayerID )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterfaceEx.ShowGamerCardUI" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( byte* )params = LocalUserNum;
				*( void** )( params + 4 ) = PlayerID;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool ShowMessagesUI( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterfaceEx.ShowMessagesUI" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool ShowAchievementsUI( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterfaceEx.ShowAchievementsUI" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool ShowInviteUI( byte LocalUserNum, ScriptArray< wchar_t > InviteText )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterfaceEx.ShowInviteUI" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )params = LocalUserNum;
				*( ScriptArray< wchar_t >* )( params + 4 ) = InviteText;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool ShowContentMarketplaceUI( byte LocalUserNum, int CategoryMask, int OfferId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterfaceEx.ShowContentMarketplaceUI" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( byte* )params = LocalUserNum;
				*( int* )( params + 4 ) = CategoryMask;
				*( int* )( params + 8 ) = OfferId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool ShowMembershipMarketplaceUI( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterfaceEx.ShowMembershipMarketplaceUI" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool ShowDeviceSelectionUI( byte LocalUserNum, int SizeNeeded, bool bManageStorage )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterfaceEx.ShowDeviceSelectionUI" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( byte* )params = LocalUserNum;
				*( int* )( params + 4 ) = SizeNeeded;
				*( bool* )( params + 8 ) = bManageStorage;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void OnDeviceSelectionComplete( bool bWasSuccessful )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterfaceEx.OnDeviceSelectionComplete" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bWasSuccessful;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnProfileDataChanged(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterfaceEx.OnProfileDataChanged" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddDeviceSelectionDoneDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterfaceEx.AddDeviceSelectionDoneDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )params = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearDeviceSelectionDoneDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterfaceEx.ClearDeviceSelectionDoneDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )params = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int GetDeviceSelectionResults( byte LocalUserNum, ScriptArray< wchar_t > &DeviceName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterfaceEx.GetDeviceSelectionResults" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )params = LocalUserNum;
				*( ScriptArray< wchar_t >* )( params + 4 ) = DeviceName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				DeviceName = *( ScriptArray< wchar_t >* )( params + 4 );
				return *( int* )( params + function->return_val_offset() );
			}

			bool IsDeviceValid( int DeviceID, int SizeNeeded )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterfaceEx.IsDeviceValid" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = DeviceID;
				*( int* )( params + 4 ) = SizeNeeded;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool UnlockGamerPicture( byte LocalUserNum, int PictureId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterfaceEx.UnlockGamerPicture" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( byte* )params = LocalUserNum;
				*( int* )( params + 4 ) = PictureId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AddProfileDataChangedDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterfaceEx.AddProfileDataChangedDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )params = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearProfileDataChangedDelegate( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterfaceEx.ClearProfileDataChangedDelegate" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )params = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool ShowFriendsInviteUI( byte LocalUserNum, void* PlayerID )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterfaceEx.ShowFriendsInviteUI" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( byte* )params = LocalUserNum;
				*( void** )( params + 4 ) = PlayerID;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool ShowPlayersUI( byte LocalUserNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterfaceEx.ShowPlayersUI" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = LocalUserNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool ShowCustomPlayersUI( byte LocalUserNum, ScriptArray< wchar_t > Title, ScriptArray< wchar_t > Description )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterfaceEx.ShowCustomPlayersUI" );
				byte *params = ( byte* )( malloc( 37 ) );
				*( byte* )params = LocalUserNum;
				*( ScriptArray< wchar_t >* )( params + 16 ) = Title;
				*( ScriptArray< wchar_t >* )( params + 28 ) = Description;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool UnlockAvatarAward( byte LocalUserNum, int AvatarItemId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlinePlayerInterfaceEx.UnlockAvatarAward" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( byte* )params = LocalUserNum;
				*( int* )( params + 4 ) = AvatarItemId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
