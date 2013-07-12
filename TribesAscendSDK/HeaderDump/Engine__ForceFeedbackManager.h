#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.ForceFeedbackManager." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.ForceFeedbackManager." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.ForceFeedbackManager." #y ) ); \
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
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
