#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.PickupFactory." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.PickupFactory." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.PickupFactory." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class PickupFactory : public NavigationPoint
	{
	public:
			ADD_OBJECT( PickupFactory, OriginalFactory )
			ADD_OBJECT( PickupFactory, ReplacementFactory )
			ADD_VAR( ::FloatProperty, MaxDesireability, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RespawnEffectTime, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bRespawnPaused, 0x10 )
			ADD_VAR( ::BoolProperty, bIsSuperItem, 0x8 )
			ADD_VAR( ::BoolProperty, bPredictRespawns, 0x4 )
			ADD_VAR( ::BoolProperty, bPickupHidden, 0x2 )
			ADD_VAR( ::BoolProperty, bOnlyReplicateHidden, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
