#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrEmitCameraEffect_Speed." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrEmitCameraEffect_Speed." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrEmitCameraEffect_Speed." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrEmitCameraEffect_Speed : public UDKEmitCameraEffect
	{
	public:
			ADD_VAR( ::FloatProperty, m_fFadeOutWeatherSoundTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fFadeInWeatherSoundTime, 0xFFFFFFFF )
			ADD_OBJECT( SoundCue, m_WeatherSound )
			ADD_VAR( ::BoolProperty, m_bUpdateLocationBasedOnVelocity, 0x2 )
			ADD_VAR( ::BoolProperty, m_bUpdateRotation, 0x1 )
			void UpdateLocation( Vector &CamLoc, Rotator &CamRot, float CamFOVDeg )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrEmitCameraEffect_Speed.UpdateLocation" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( Vector* )params = CamLoc;
				*( Rotator* )( params + 12 ) = CamRot;
				*( float* )( params + 24 ) = CamFOVDeg;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				CamLoc = *( Vector* )params;
				CamRot = *( Rotator* )( params + 12 );
			}

			void Activate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrEmitCameraEffect_Speed.Activate" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Deactivate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrEmitCameraEffect_Speed.Deactivate" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
