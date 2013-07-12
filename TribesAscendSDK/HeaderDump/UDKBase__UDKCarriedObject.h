#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " UDKBase.UDKCarriedObject." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty UDKBase.UDKCarriedObject." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty UDKBase.UDKCarriedObject." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UDKCarriedObject : public Actor
	{
	public:
			ADD_STRUCT( ::VectorProperty, HUDLocation, 0xFFFFFFFF )
			ADD_OBJECT( Actor, OldBaseBase )
			ADD_OBJECT( Actor, OldBase )
			ADD_STRUCT( ::VectorProperty, HomeBaseOffset, 0xFFFFFFFF )
			ADD_OBJECT( UDKGameObjective, HomeBase )
			ADD_VAR( ::BoolProperty, bHome, 0x1 )
			ADD_VAR( ::FloatProperty, LastValidAnchorTime, 0xFFFFFFFF )
			ADD_OBJECT( NavigationPoint, LastAnchor )
			ADD_OBJECT( TeamInfo, Team )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
