#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.DrawSphereComponent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.DrawSphereComponent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.DrawSphereComponent." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class DrawSphereComponent : public PrimitiveComponent
	{
	public:
			ADD_VAR( ::BoolProperty, bDrawOnlyIfSelected, 0x4 )
			ADD_VAR( ::BoolProperty, bDrawLitSphere, 0x2 )
			ADD_VAR( ::BoolProperty, bDrawWireSphere, 0x1 )
			ADD_VAR( ::IntProperty, SphereSides, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SphereRadius, 0xFFFFFFFF )
			ADD_OBJECT( Material, SphereMaterial )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
