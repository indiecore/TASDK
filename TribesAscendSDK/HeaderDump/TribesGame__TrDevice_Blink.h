#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrDevice_Blink." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrDevice_Blink." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrDevice_Blink." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrDevice_Blink : public TrDevice_Pack
	{
	public:
			Vector GetBlinkImpulse(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice_Blink.GetBlinkImpulse" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::FloatProperty, m_fMinZImpulse, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fPowerPoolCost, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fSpeedCapThresholdStart, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fSpeedCapPct, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fSpeedCapThreshold, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fLastActivationTimestamp, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fCooldownTime, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, m_vBlinkImpulse, 0xFFFFFFFF )
			void ToggleActivate(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice_Blink.ToggleActivate" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnBlink( float PercentEffectiveness )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice_Blink.OnBlink" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = PercentEffectiveness;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
