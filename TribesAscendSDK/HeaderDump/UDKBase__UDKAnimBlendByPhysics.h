#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " UDKBase.UDKAnimBlendByPhysics." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty UDKBase.UDKAnimBlendByPhysics." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty UDKBase.UDKAnimBlendByPhysics." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UDKAnimBlendByPhysics : public UDKAnimBlendBase
	{
	public:
			ADD_VAR( ::FloatProperty, PendingTimeToGo, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, PendingChildIndex, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LandBlendDelay, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, LastPhysics, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, PhysicsMap, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
