#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " GameFramework.GamePlayerController." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty GameFramework.GamePlayerController." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty GameFramework.GamePlayerController." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GamePlayerController : public PlayerController
	{
	public:
			ADD_VAR( ::NameProperty, CurrentSoundMode, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AgentAwareRadius, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bIsWarmupPaused, 0x4 )
			ADD_VAR( ::BoolProperty, bDebugCrowdAwareness, 0x2 )
			ADD_VAR( ::BoolProperty, bWarnCrowdMembers, 0x1 )
			int GetUIPlayerIndex(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GamePlayerController.GetUIPlayerIndex" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void NotifyCrowdAgentRefresh(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GamePlayerController.NotifyCrowdAgentRefresh" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NotifyCrowdAgentInRadius( class GameCrowdAgent* Agent )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GamePlayerController.NotifyCrowdAgentInRadius" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GameCrowdAgent** )params = Agent;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DoForceFeedbackForScreenShake( class CameraShake* ShakeData, float Scale )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GamePlayerController.DoForceFeedbackForScreenShake" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class CameraShake** )params = ShakeData;
				*( float* )( params + 4 ) = Scale;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetSoundMode( ScriptName InSoundModeName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GamePlayerController.SetSoundMode" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = InSoundModeName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ShowLoadingMovie( bool bShowMovie, bool bPauseAfterHide, float PauseDuration, float KeepPlayingDuration, bool bOverridePreviousDelays )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GamePlayerController.ShowLoadingMovie" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( bool* )params = bShowMovie;
				*( bool* )( params + 4 ) = bPauseAfterHide;
				*( float* )( params + 8 ) = PauseDuration;
				*( float* )( params + 12 ) = KeepPlayingDuration;
				*( bool* )( params + 16 ) = bOverridePreviousDelays;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void KeepPlayingLoadingMovie(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GamePlayerController.KeepPlayingLoadingMovie" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientPlayMovie( ScriptArray< wchar_t > MovieName, int InStartOfRenderingMovieFrame, int InEndOfRenderingMovieFrame )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GamePlayerController.ClientPlayMovie" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptArray< wchar_t >* )params = MovieName;
				*( int* )( params + 12 ) = InStartOfRenderingMovieFrame;
				*( int* )( params + 16 ) = InEndOfRenderingMovieFrame;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientStopMovie( float DelayInSeconds, bool bAllowMovieToFinish, bool bForceStopNonSkippable, bool bForceStopLoadingMovie )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GamePlayerController.ClientStopMovie" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( float* )params = DelayInSeconds;
				*( bool* )( params + 4 ) = bAllowMovieToFinish;
				*( bool* )( params + 8 ) = bForceStopNonSkippable;
				*( bool* )( params + 12 ) = bForceStopLoadingMovie;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void GetCurrentMovie( ScriptArray< wchar_t > &MovieName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GamePlayerController.GetCurrentMovie" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = MovieName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				MovieName = *( ScriptArray< wchar_t >* )params;
			}

			bool CanUnpauseWarmup(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GamePlayerController.CanUnpauseWarmup" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void WarmupPause( bool bDesiredPauseState )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GamePlayerController.WarmupPause" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bDesiredPauseState;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DoMemLeakChecking( float InTimeBetweenMemLeakChecks )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GamePlayerController.DoMemLeakChecking" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = InTimeBetweenMemLeakChecks;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StopMemLeakChecking(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GamePlayerController.StopMemLeakChecking" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CallMemLeakCheck(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GamePlayerController.CallMemLeakCheck" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientColorFade( void* FadeColor, byte FromAlpha, byte ToAlpha, float FadeTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GamePlayerController.ClientColorFade" );
				byte *params = ( byte* )( malloc( 10 ) );
				*( void** )params = FadeColor;
				*( byte* )( params + 4 ) = FromAlpha;
				*( byte* )( params + 5 ) = ToAlpha;
				*( float* )( params + 8 ) = FadeTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
