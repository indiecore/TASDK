#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrFlagBase." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrFlagBase." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrFlagBase." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrFlagBase : public UTCarriedObject
	{
	public:
			ADD_VAR( ::FloatProperty, m_fRageRadius, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fDamageMomentumDampingWhileFalling, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nDropFlagPingThreshold, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fTeammatePassMaxDistanceSq, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nNumBounces, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nNumBouncesBeforeSlide, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fIgnoreSameTeamTouch, 0xFFFFFFFF )
			ADD_OBJECT( MaterialInstanceConstant, m_MarkerMIC )
			ADD_OBJECT( TrCollisionProxy, m_CollisionProxyLevel3 )
			ADD_OBJECT( TrCollisionProxy, m_CollisionProxyLevel2 )
			ADD_OBJECT( TrCollisionProxy, m_CollisionProxyLevel1 )
			ADD_VAR( ::FloatProperty, m_fBounceDampingPercent, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fForwardThrowVelocity, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fInheritVelocityPct, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_TimeAwaySeconds, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, LastCameraPos, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, LastCameraDir, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, LastScreenLoc, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_FlagIconAlpha, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fFriction, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fMass, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastLocationPingTime, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, HoverboardingClothVelClamp, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, RunningClothVelClamp, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, m_bPassToTeammatesEnabled, 0x80 )
			ADD_VAR( ::BoolProperty, m_bBounceSlideEnabled, 0x40 )
			ADD_VAR( ::BoolProperty, bWasFlagReturned, 0x20 )
			ADD_VAR( ::BoolProperty, bWasClothEnabled, 0x10 )
			ADD_VAR( ::BoolProperty, bRespawning, 0x8 )
			ADD_VAR( ::BoolProperty, bFadingOut, 0x4 )
			ADD_VAR( ::BoolProperty, bBringDownFromBright, 0x2 )
			ADD_VAR( ::BoolProperty, bBringUpBright, 0x1 )
			ADD_OBJECT( ParticleSystem, RespawnEffect )
			void ReplicatedEvent( ScriptName VarName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrFlagBase.ReplicatedEvent" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = VarName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrFlagBase.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Tick( float DeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrFlagBase.Tick" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = DeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnBaseChainChanged(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrFlagBase.OnBaseChainChanged" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool ShouldMinimapRenderFor( class PlayerController* PC )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrFlagBase.ShouldMinimapRenderFor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerController** )( params + 0 ) = PC;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void ClientReturnedHome(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrFlagBase.ClientReturnedHome" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetHolder( class Controller* C )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrFlagBase.SetHolder" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Controller** )( params + 0 ) = C;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool ValidHolder( class Actor* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrFlagBase.ValidHolder" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )( params + 0 ) = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SameTeamTouch( class Controller* C )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrFlagBase.SameTeamTouch" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Controller** )( params + 0 ) = C;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CustomRespawnEffects(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrFlagBase.CustomRespawnEffects" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void bringUpBrightOff(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrFlagBase.bringUpBrightOff" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CustomFadeOutEffects(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrFlagBase.CustomFadeOutEffects" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Landed( Vector HitNormal, class Actor* FloorActor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrFlagBase.Landed" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Vector* )( params + 0 ) = HitNormal;
				*( class Actor** )( params + 12 ) = FloorActor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EncroachedBy( class Actor* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrFlagBase.EncroachedBy" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )( params + 0 ) = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Drop( class Controller* Killer, bool bNoThrow )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrFlagBase.Drop" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Controller** )( params + 0 ) = Killer;
				*( bool* )( params + 4 ) = bNoThrow;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetFlagPropertiesToStationaryFlagState(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrFlagBase.SetFlagPropertiesToStationaryFlagState" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetFlagDynamicLightToNotBeDynamic(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrFlagBase.SetFlagDynamicLightToNotBeDynamic" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Destroyed(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrFlagBase.Destroyed" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostRenderFor( class PlayerController* PC, class Canvas* Canvas, Vector CameraPosition, Vector CameraDir )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrFlagBase.PostRenderFor" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( class PlayerController** )( params + 0 ) = PC;
				*( class Canvas** )( params + 4 ) = Canvas;
				*( Vector* )( params + 8 ) = CameraPosition;
				*( Vector* )( params + 20 ) = CameraDir;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DisplayDebug( class HUD* HUD, float &out_YL, float &out_YPos )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrFlagBase.DisplayDebug" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class HUD** )( params + 0 ) = HUD;
				*( float* )( params + 4 ) = out_YL;
				*( float* )( params + 8 ) = out_YPos;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_YL = *( float* )( params + 4 );
				out_YPos = *( float* )( params + 8 );
			}

			ScriptArray< wchar_t > GetSpectatorName(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrFlagBase.GetSpectatorName" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > GetSpectatorDescription(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrFlagBase.GetSpectatorDescription" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			void OnCollisionProxyTouched( class TrPawn* TRP )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrFlagBase.OnCollisionProxyTouched" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrPawn** )( params + 0 ) = TRP;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
