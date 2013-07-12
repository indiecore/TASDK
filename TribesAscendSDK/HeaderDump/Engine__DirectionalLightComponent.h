#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.DirectionalLightComponent." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.DirectionalLightComponent." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.DirectionalLightComponent." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class DirectionalLightComponent : public LightComponent
	{
	public:
			ADD_VAR( ::FloatProperty, CascadeDistributionExponent, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, NumWholeSceneDynamicShadowCascades, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, WholeSceneDynamicShadowRadius, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TraceDistance, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
