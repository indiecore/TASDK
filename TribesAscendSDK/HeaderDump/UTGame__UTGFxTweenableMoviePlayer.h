#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.UTGFxTweenableMoviePlayer." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.UTGFxTweenableMoviePlayer." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.UTGFxTweenableMoviePlayer." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTGFxTweenableMoviePlayer : public GFxMoviePlayer
	{
	public:
			void TweenTo( class GFxObject* MC, float Duration, ScriptArray< wchar_t > Member, float Target, byte NewTweenType, ScriptArray< wchar_t > Callback )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGFxTweenableMoviePlayer.TweenTo" );
				byte *params = ( byte* )( malloc( 37 ) );
				*( class GFxObject** )( params + 0 ) = MC;
				*( float* )( params + 4 ) = Duration;
				*( ScriptArray< wchar_t >* )( params + 8 ) = Member;
				*( float* )( params + 20 ) = Target;
				*( byte* )( params + 24 ) = NewTweenType;
				*( ScriptArray< wchar_t >* )( params + 28 ) = Callback;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ProcessTweenCallback( ScriptArray< wchar_t > Callback, class GFxObject* TargetMC )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGFxTweenableMoviePlayer.ProcessTweenCallback" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = Callback;
				*( class GFxObject** )( params + 12 ) = TargetMC;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Tick( float DeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGFxTweenableMoviePlayer.Tick" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = DeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearsTweensOnMovieClip( class GFxObject* MC, bool bReset )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGFxTweenableMoviePlayer.ClearsTweensOnMovieClip" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class GFxObject** )( params + 0 ) = MC;
				*( bool* )( params + 4 ) = bReset;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PrintTweensToLog(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGFxTweenableMoviePlayer.PrintTweensToLog" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TweenComplete( int Index )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTGFxTweenableMoviePlayer.TweenComplete" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = Index;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
