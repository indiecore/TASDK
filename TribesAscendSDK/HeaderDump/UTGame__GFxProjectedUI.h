#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.GFxProjectedUI." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.GFxProjectedUI." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.GFxProjectedUI." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GFxProjectedUI : public UTGFxTweenableMoviePlayer
	{
	public:
			ADD_VAR( ::StrProperty, CancelString, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, AcceptString, 0xFFFFFFFF )
			ADD_STRUCT( ::RotatorProperty, StartRotation, 0xFFFFFFFF )
			ADD_OBJECT( ScriptClass, WeaponClass )
			ADD_VAR( ::FloatProperty, leftThreshold, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, rightThreshold, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, rotval, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Height, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Width, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Scale, 0xFFFFFFFF )
			ADD_OBJECT( GFxObject, InfoTitle )
			ADD_OBJECT( GFxObject, InfoText )
			ADD_OBJECT( GFxObject, InfoIconItem )
			ADD_OBJECT( GFxObject, InfoIconWeap )
			ADD_OBJECT( GFxObject, InfoMC )
			ADD_OBJECT( GFxObject, BG_Edge_RightBottom )
			ADD_OBJECT( GFxObject, BG_Edge_RightMiddle )
			ADD_OBJECT( GFxObject, BG_Edge_RightTop )
			ADD_OBJECT( GFxObject, BG_Edge_LeftTop )
			ADD_OBJECT( GFxObject, BG_Edge_LeftMiddle )
			ADD_OBJECT( GFxObject, BG_Edge_LeftBottom )
			ADD_OBJECT( GFxObject, BG_Optic4MC )
			ADD_OBJECT( GFxObject, BG_Optic3MC )
			ADD_OBJECT( GFxObject, BG_Optic2MC )
			ADD_OBJECT( GFxObject, BG_Optic1MC )
			ADD_OBJECT( GFxObject, BG_ArrowMC )
			ADD_OBJECT( GFxObject, BG_LineMC )
			ADD_OBJECT( GFxObject, StartUpTextMC )
			ADD_OBJECT( GFxObject, CPCLogoMC )
			ADD_OBJECT( GFxObject, BackgroundMC )
			ADD_OBJECT( GFxObject, LeftArrow01 )
			ADD_OBJECT( GFxObject, LeftArrow02 )
			ADD_OBJECT( GFxObject, ArsenalTabMC )
			ADD_OBJECT( GFxObject, BackpackTabMC )
			ADD_VAR( ::BoolProperty, bInitialized, 0x2 )
			ADD_VAR( ::BoolProperty, bArsenalTabFocused, 0x1 )
			ADD_OBJECT( GFxObject, EquippedWeaponText2 )
			ADD_OBJECT( GFxObject, EquippedWeaponText1 )
			ADD_OBJECT( GFxObject, EquippedWeaponOutline )
			ADD_OBJECT( GFxObject, EquippedWeapon )
			ADD_OBJECT( GFxObject, ArsenalMC )
			ADD_OBJECT( GFxObject, BackpackMC )
			ADD_OBJECT( GFxObject, MainMC )
			ADD_OBJECT( GFxObject, Window )
			ADD_OBJECT( GFxObject, Root )
			bool Start( bool StartPaused )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxProjectedUI.Start" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = StartPaused;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void ConfigureInventory(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxProjectedUI.ConfigureInventory" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddCaptureKeys(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxProjectedUI.AddCaptureKeys" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StartCloseAnimation(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxProjectedUI.StartCloseAnimation" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnCloseAnimComplete(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxProjectedUI.OnCloseAnimComplete" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetupBG(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxProjectedUI.SetupBG" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetupBorder(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxProjectedUI.SetupBorder" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetupArsenal(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxProjectedUI.SetupArsenal" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetupBackpack(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxProjectedUI.SetupBackpack" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetupInfo(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxProjectedUI.SetupInfo" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PopulateBackpackFake(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxProjectedUI.PopulateBackpackFake" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetupArsenalButtons(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxProjectedUI.SetupArsenalButtons" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetupBackpackButtons(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxProjectedUI.SetupBackpackButtons" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SwitchWeapon( byte Index )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxProjectedUI.SwitchWeapon" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = Index;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnFocusInSelection( void* ev )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxProjectedUI.OnFocusInSelection" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( void** )params = ev;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnFocusOutSelection( void* ev )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxProjectedUI.OnFocusOutSelection" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( void** )params = ev;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnClickWeaponButton( void* ev )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxProjectedUI.OnClickWeaponButton" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( void** )params = ev;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnFocusUpdateInfo( void* ev )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxProjectedUI.OnFocusUpdateInfo" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( void** )params = ev;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnFocusArsenalTab( void* ev )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxProjectedUI.OnFocusArsenalTab" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( void** )params = ev;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnFocusBackpackTab( void* ev )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxProjectedUI.OnFocusBackpackTab" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( void** )params = ev;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnClickFakeItem( void* ev )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxProjectedUI.OnClickFakeItem" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( void** )params = ev;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetInfo( int Index )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxProjectedUI.SetInfo" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = Index;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PopulateArsenal(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxProjectedUI.PopulateArsenal" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FakeUpdateEquippedWeapon( int Index )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxProjectedUI.FakeUpdateEquippedWeapon" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = Index;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateEquippedWeapon(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxProjectedUI.UpdateEquippedWeapon" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ProcessTweenCallback( ScriptArray< wchar_t > Callback, class GFxObject* TargetMC )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxProjectedUI.ProcessTweenCallback" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptArray< wchar_t >* )params = Callback;
				*( class GFxObject** )( params + 12 ) = TargetMC;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TweenTurbines( bool Toggle )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxProjectedUI.TweenTurbines" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = Toggle;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FloatSelectionUp( class GFxObject* ButtonIconMC )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxProjectedUI.FloatSelectionUp" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GFxObject** )params = ButtonIconMC;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FloatSelectionDown( class GFxObject* ButtonIconMC )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxProjectedUI.FloatSelectionDown" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GFxObject** )params = ButtonIconMC;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdatePos(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxProjectedUI.UpdatePos" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CreateItemData(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxProjectedUI.CreateItemData" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
