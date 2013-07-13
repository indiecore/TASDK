#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.DrawFrustumComponent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.DrawFrustumComponent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.DrawFrustumComponent." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class DrawFrustumComponent : public PrimitiveComponent
	{
	public:
			ADD_OBJECT( Texture, Texture )
			ADD_VAR( ::FloatProperty, FrustumEndDist, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FrustumStartDist, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FrustumAspectRatio, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FrustumAngle, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
