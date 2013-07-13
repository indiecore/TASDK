#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.Inventory." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.Inventory." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.Inventory." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class Inventory : public Actor
	{
	public:
			ADD_VAR( ::StrProperty, PickupForce, 0xFFFFFFFF )
			ADD_OBJECT( SoundCue, PickupSound )
			ADD_VAR( ::StrProperty, PickupMessage, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxDesireability, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RespawnTime, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bPredictRespawns, 0x4 )
			ADD_VAR( ::BoolProperty, bDelayedSpawn, 0x2 )
			ADD_VAR( ::BoolProperty, bDropOnDeath, 0x1 )
			ADD_VAR( ::StrProperty, ItemName, 0xFFFFFFFF )
			ADD_OBJECT( InventoryManager, InvManager )
			ADD_OBJECT( Inventory, Inventory )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
