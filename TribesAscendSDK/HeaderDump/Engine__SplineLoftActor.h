#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.SplineLoftActor." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.SplineLoftActor." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.SplineLoftActor." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SplineLoftActor : public SplineActor
	{
	public:
			ADD_VAR( ::FloatProperty, MeshMaxDrawDistance, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bAcceptsLights, 0x2 )
			ADD_VAR( ::BoolProperty, bSmoothInterpRollAndScale, 0x1 )
			ADD_STRUCT( ::VectorProperty, WorldXDir, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Roll, 0xFFFFFFFF )
			ADD_OBJECT( StaticMesh, DeformMesh )
			ADD_VAR( ::FloatProperty, ScaleY, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ScaleX, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
