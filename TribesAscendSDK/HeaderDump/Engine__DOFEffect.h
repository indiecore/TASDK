#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.DOFEffect." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.DOFEffect." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.DOFEffect." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class DOFEffect : public PostProcessEffect
	{
	public:
			ADD_VAR( ::FloatProperty, FalloffExponent, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BlurKernelSize, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxNearBlurAmount, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MinBlurAmount, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxFarBlurAmount, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, FocusType, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FocusInnerRadius, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FocusDistance, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, FocusPosition, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
