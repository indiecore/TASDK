#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.GFxTrReticules." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.GFxTrReticules." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.GFxTrReticules." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GFxTrReticules : public GFxObject
	{
	public:
			ADD_VAR( ::IntProperty, m_nCurrentReticuleIndex, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, m_bVisible, 0x1 )
			ADD_VAR( ::FloatProperty, LastReticuleDepth, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastHitEnemyTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastAccuracy, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, LastCrossMode, 0xFFFFFFFF )
			ADD_OBJECT( Weapon, LastWeapon )
			ADD_OBJECT( GFxObject, ActiveReticule )
			ADD_OBJECT( GFxObject, ReticulesMC )
			ADD_OBJECT( WorldInfo, ThisWorld )
			ADD_OBJECT( GfxTrHud, HUD )
			void CallShowReticule( int nIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrReticules.CallShowReticule" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = nIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CallSetReticuleColor( int nType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrReticules.CallSetReticuleColor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = nType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ASC_SetCustomReticule( class GFxObject* Data )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrReticules.ASC_SetCustomReticule" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GFxObject** )params = Data;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CallSetReticuleDepth( float fDepth )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrReticules.CallSetReticuleDepth" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = fDepth;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ChangeReticule( int nIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrReticules.ChangeReticule" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = nIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool SetCustomReticule(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrReticules.SetCustomReticule" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			int GetCurrentReticuleIndex(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrReticules.GetCurrentReticuleIndex" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void CallSetAccuracy( int nAccuracy )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrReticules.CallSetAccuracy" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = nAccuracy;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CallShowHit(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrReticules.CallShowHit" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DisableVehicleAmmoClip(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrReticules.DisableVehicleAmmoClip" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EnableVehicleAmmoClip(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrReticules.EnableVehicleAmmoClip" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetVehicleAmmoClip( ScriptArray< wchar_t > AmmoCount )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrReticules.SetVehicleAmmoClip" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = AmmoCount;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetPowerupPercentage( int pPercentage )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrReticules.SetPowerupPercentage" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = pPercentage;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetLaserPowerupPercentage( int pPercentage )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrReticules.SetLaserPowerupPercentage" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = pPercentage;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetVehiclePowerupPercentage( int pPercentage )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrReticules.SetVehiclePowerupPercentage" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = pPercentage;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetGenericPowerupPercentage( int pPercentage )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrReticules.SetGenericPowerupPercentage" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = pPercentage;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Init( class GfxTrHud* H )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrReticules.Init" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GfxTrHud** )params = H;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetReticuleVisible( bool bNewVisible )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrReticules.SetReticuleVisible" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bNewVisible;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateReticule( class Pawn* pPawn, bool bForceUpdate )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.GFxTrReticules.UpdateReticule" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Pawn** )params = pPawn;
				*( bool* )( params + 4 ) = bForceUpdate;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
