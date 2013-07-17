#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.ForceFeedbackManager." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.ForceFeedbackManager." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.ForceFeedbackManager." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class ForceFeedbackManager : public Object
	{
	public:
			ADD_VAR( ::FloatProperty, ScaleAllWaveformsBy, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bAllowsForceFeedback, 0x1 )
			ADD_OBJECT( Actor, WaveformInstigator )
			ADD_VAR( ::FloatProperty, ElapsedTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, CurrentSample, 0xFFFFFFFF )
			ADD_OBJECT( ForceFeedbackWaveform, FFWaveform )
			ADD_VAR( ::BoolProperty, bIsPaused, 0x2 )
			void PlayForceFeedbackWaveform( class ForceFeedbackWaveform* WaveForm, class Actor* WaveInstigator )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ForceFeedbackManager.PlayForceFeedbackWaveform" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class ForceFeedbackWaveform** )( params + 0 ) = WaveForm;
				*( class Actor** )( params + 4 ) = WaveInstigator;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StopForceFeedbackWaveform( class ForceFeedbackWaveform* WaveForm )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ForceFeedbackManager.StopForceFeedbackWaveform" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class ForceFeedbackWaveform** )( params + 0 ) = WaveForm;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PauseWaveform( bool bPause )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ForceFeedbackManager.PauseWaveform" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bPause;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
