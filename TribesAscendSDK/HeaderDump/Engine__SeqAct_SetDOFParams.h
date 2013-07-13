#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.SeqAct_SetDOFParams." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.SeqAct_SetDOFParams." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.SeqAct_SetDOFParams." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SeqAct_SetDOFParams : public SeqAct_Latent
	{
	public:
			ADD_STRUCT( ::VectorProperty, OldFocusPosition, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, OldFocusDistance, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, OldFocusInnerRadius, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, OldMaxFarBlurAmount, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, OldMinBlurAmount, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, OldMaxNearBlurAmount, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, OldBlurKernelSize, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, OldFalloffExponent, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, InterpolateElapsed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, InterpolateSeconds, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, FocusPosition, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FocusDistance, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FocusInnerRadius, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxFarBlurAmount, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MinBlurAmount, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxNearBlurAmount, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BlurKernelSize, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FalloffExponent, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
