#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.RB_BodySetup." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.RB_BodySetup." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.RB_BodySetup." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class RB_BodySetup : public KMeshProps
	{
	public:
			ADD_VAR( ::IntProperty, PreCachedPhysDataVersion, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MassScale, 0xFFFFFFFF )
			ADD_OBJECT( PhysicalMaterial, PhysMaterial )
			ADD_VAR( ::BoolProperty, bConsiderForBounds, 0x40 )
			ADD_VAR( ::BoolProperty, bAlwaysFullAnimWeight, 0x20 )
			ADD_VAR( ::BoolProperty, bEnableContinuousCollisionDetection, 0x10 )
			ADD_VAR( ::BoolProperty, bBlockNonZeroExtent, 0x8 )
			ADD_VAR( ::BoolProperty, bBlockZeroExtent, 0x4 )
			ADD_VAR( ::BoolProperty, bNoCollision, 0x2 )
			ADD_VAR( ::BoolProperty, bFixed, 0x1 )
			ADD_VAR( ::NameProperty, BoneName, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, SleepFamily, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
