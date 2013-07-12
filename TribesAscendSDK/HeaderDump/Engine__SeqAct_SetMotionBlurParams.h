#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.SeqAct_SetMotionBlurParams." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.SeqAct_SetMotionBlurParams." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.SeqAct_SetMotionBlurParams." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SeqAct_SetMotionBlurParams : public SeqAct_Latent
	{
	public:
			ADD_VAR( ::FloatProperty, OldMotionBlurAmount, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, InterpolateElapsed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, InterpolateSeconds, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MotionBlurAmount, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
