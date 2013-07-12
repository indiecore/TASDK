#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.ParticleModuleTypeDataMeshPhysX." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.ParticleModuleTypeDataMeshPhysX." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.ParticleModuleTypeDataMeshPhysX." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class ParticleModuleTypeDataMeshPhysX : public ParticleModuleTypeDataMesh
	{
	public:
			ADD_VAR( ::FloatProperty, FluidRotationCoefficient, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, PhysXRotationMethod, 0xFFFFFFFF )
			ADD_OBJECT( PhysXParticleSystem, PhysXParSys )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
