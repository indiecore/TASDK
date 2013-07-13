#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.ShadowMap2D." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.ShadowMap2D." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.ShadowMap2D." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class ShadowMap2D : public Object
	{
	public:
			ADD_VAR( ::IntProperty, InstanceIndex, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bIsShadowFactorTexture, 0x1 )
			ADD_OBJECT( ShadowMapTexture2D, Texture )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
