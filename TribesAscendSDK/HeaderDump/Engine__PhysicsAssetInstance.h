#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.PhysicsAssetInstance." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.PhysicsAssetInstance." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.PhysicsAssetInstance." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class PhysicsAssetInstance : public Object
	{
	public:
			ADD_VAR( ::BoolProperty, bInitBodies, 0x1 )
			ADD_VAR( ::FloatProperty, AngularForceLimitScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AngularDampingScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AngularSpringScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LinearForceLimitScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LinearDampingScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LinearSpringScale, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, RootBodyIndex, 0xFFFFFFFF )
			ADD_OBJECT( Actor, Owner )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
