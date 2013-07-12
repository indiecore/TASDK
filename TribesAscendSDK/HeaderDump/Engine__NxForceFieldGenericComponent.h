#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.NxForceFieldGenericComponent." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.NxForceFieldGenericComponent." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.NxForceFieldGenericComponent." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class NxForceFieldGenericComponent : public NxForceFieldComponent
	{
	public:
			ADD_VAR( ::FloatProperty, TorusRadius, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, FalloffQuadratic, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, FalloffLinear, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, Noise, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, VelocityTarget, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, VelocityMultiplierZ, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, VelocityMultiplierY, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, VelocityMultiplierX, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, PositionTarget, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, PositionMultiplierZ, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, PositionMultiplierY, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, PositionMultiplierX, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, Constant, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, Coordinates, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RoughExtentZ, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RoughExtentY, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RoughExtentX, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
