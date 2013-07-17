#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.UTHUDBase." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.UTHUDBase." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.UTHUDBase." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTHUDBase : public UDKHUD
	{
	public:
			ADD_VAR( ::BoolProperty, bCrosshairShow, 0x4 )
			ADD_OBJECT( Texture2D, IconHudTexture )
			ADD_VAR( ::BoolProperty, bCrosshairOnFriendly, 0x8 )
			ADD_VAR( ::FloatProperty, ResolutionScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastPickupTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ConfiguredCrosshairScaling, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bGreenCrosshair, 0x10 )
			ADD_VAR( ::BoolProperty, bIsSplitScreen, 0x1 )
			ADD_VAR( ::IntProperty, ViewY, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, ViewX, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ResolutionScaleX, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, ConsoleIconFontClassName, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastTimeTooltipDrawn, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bEnableActorOverlays, 0x2 )
			ADD_OBJECT( UTGameReplicationInfo, UTGRI )
			ADD_OBJECT( UTPlayerController, UTPlayerOwner )
			ADD_OBJECT( ScriptClass, MusicManagerClass )
			ADD_OBJECT( GFxUI_PauseMenu, PauseMenuMovie )
			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTHUDBase.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Timer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTHUDBase.Timer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ShowMenu(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTHUDBase.ShowMenu" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ResolutionChanged(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTHUDBase.ResolutionChanged" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DisplayHit( Vector HitDir, int Damage, ScriptClass* DamageType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTHUDBase.DisplayHit" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( Vector* )( params + 0 ) = HitDir;
				*( int* )( params + 12 ) = Damage;
				*( ScriptClass** )( params + 16 ) = DamageType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostRender(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTHUDBase.PostRender" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RemoveMovies(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTHUDBase.RemoveMovies" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetVisible( bool bNewVisible )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTHUDBase.SetVisible" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bNewVisible;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CloseOtherMenus(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTHUDBase.CloseOtherMenus" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TogglePauseMenu(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTHUDBase.TogglePauseMenu" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CompletePauseMenuClose(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTHUDBase.CompletePauseMenuClose" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ReleaseShowScores(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTHUDBase.ReleaseShowScores" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int GetLocalPlayerOwnerIndex(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTHUDBase.GetLocalPlayerOwnerIndex" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void DrawToolTip( class Canvas* Cvs, class PlayerController* PC, ScriptArray< wchar_t > Command, float X, float Y, float U, float V, float UL, float VL, float ResScale, class Texture2D* IconTexture, float Alpha )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTHUDBase.DrawToolTip" );
				byte *params = ( byte* )( malloc( 56 ) );
				*( class Canvas** )( params + 0 ) = Cvs;
				*( class PlayerController** )( params + 4 ) = PC;
				*( ScriptArray< wchar_t >* )( params + 8 ) = Command;
				*( float* )( params + 20 ) = X;
				*( float* )( params + 24 ) = Y;
				*( float* )( params + 28 ) = U;
				*( float* )( params + 32 ) = V;
				*( float* )( params + 36 ) = UL;
				*( float* )( params + 40 ) = VL;
				*( float* )( params + 44 ) = ResScale;
				*( class Texture2D** )( params + 48 ) = IconTexture;
				*( float* )( params + 52 ) = Alpha;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool CheckCrosshairOnFriendly(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTHUDBase.CheckCrosshairOnFriendly" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void ClearCrosshairOnFriendly(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTHUDBase.ClearCrosshairOnFriendly" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DrawShadowedTile( class Texture2D* Tex, float X, float Y, float XL, float YL, float U, float V, float UL, float VL, void* TileColor, bool bScaleToRes )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTHUDBase.DrawShadowedTile" );
				byte *params = ( byte* )( malloc( 44 ) );
				*( class Texture2D** )( params + 0 ) = Tex;
				*( float* )( params + 4 ) = X;
				*( float* )( params + 8 ) = Y;
				*( float* )( params + 12 ) = XL;
				*( float* )( params + 16 ) = YL;
				*( float* )( params + 20 ) = U;
				*( float* )( params + 24 ) = V;
				*( float* )( params + 28 ) = UL;
				*( float* )( params + 32 ) = VL;
				*( void** )( params + 36 ) = TileColor;
				*( bool* )( params + 40 ) = bScaleToRes;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DrawShadowedStretchedTile( class Texture2D* Tex, float X, float Y, float XL, float YL, float U, float V, float UL, float VL, void* TileColor, bool bScaleToRes )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTHUDBase.DrawShadowedStretchedTile" );
				byte *params = ( byte* )( malloc( 44 ) );
				*( class Texture2D** )( params + 0 ) = Tex;
				*( float* )( params + 4 ) = X;
				*( float* )( params + 8 ) = Y;
				*( float* )( params + 12 ) = XL;
				*( float* )( params + 16 ) = YL;
				*( float* )( params + 20 ) = U;
				*( float* )( params + 24 ) = V;
				*( float* )( params + 28 ) = UL;
				*( float* )( params + 32 ) = VL;
				*( void** )( params + 36 ) = TileColor;
				*( bool* )( params + 40 ) = bScaleToRes;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DrawShadowedRotatedTile( class Texture2D* Tex, Rotator Rot, float X, float Y, float XL, float YL, float U, float V, float UL, float VL, void* TileColor, bool bScaleToRes )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTHUDBase.DrawShadowedRotatedTile" );
				byte *params = ( byte* )( malloc( 56 ) );
				*( class Texture2D** )( params + 0 ) = Tex;
				*( Rotator* )( params + 4 ) = Rot;
				*( float* )( params + 16 ) = X;
				*( float* )( params + 20 ) = Y;
				*( float* )( params + 24 ) = XL;
				*( float* )( params + 28 ) = YL;
				*( float* )( params + 32 ) = U;
				*( float* )( params + 36 ) = V;
				*( float* )( params + 40 ) = UL;
				*( float* )( params + 44 ) = VL;
				*( void** )( params + 48 ) = TileColor;
				*( bool* )( params + 52 ) = bScaleToRes;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
