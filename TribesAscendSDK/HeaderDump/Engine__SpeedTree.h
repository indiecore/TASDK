#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.SpeedTree." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.SpeedTree." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.SpeedTree." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SpeedTree : public Object
	{
	public:
			ADD_STRUCT( ::VectorProperty, WindDirection, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, WindStrength, 0xFFFFFFFF )
			ADD_OBJECT( MaterialInterface, BillboardMaterial )
			ADD_OBJECT( MaterialInterface, LeafMeshMaterial )
			ADD_OBJECT( MaterialInterface, LeafCardMaterial )
			ADD_OBJECT( MaterialInterface, FrondMaterial )
			ADD_OBJECT( MaterialInterface, Branch2Material )
			ADD_OBJECT( MaterialInterface, Branch1Material )
			ADD_VAR( ::FloatProperty, LeafStaticShadowOpacity, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bLegacySpeedTree, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
