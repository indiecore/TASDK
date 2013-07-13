#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.ParticleModuleCollision." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.ParticleModuleCollision." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.ParticleModuleCollision." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class ParticleModuleCollision : public ParticleModuleCollisionBase
	{
	public:
			ADD_VAR( ::FloatProperty, VerticalFudgeFactor, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DirScalar, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bDropDetail, 0x8 )
			ADD_VAR( ::BoolProperty, bOnlyVerticalNormalsDecrementCount, 0x4 )
			ADD_VAR( ::BoolProperty, bPawnsDoNotDecrementCount, 0x2 )
			ADD_VAR( ::BoolProperty, bApplyPhysics, 0x1 )
			ADD_VAR( ::ByteProperty, CollisionCompletionOption, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
