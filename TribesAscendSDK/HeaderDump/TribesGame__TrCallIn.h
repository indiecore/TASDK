#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrCallIn." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrCallIn." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrCallIn." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrCallIn : public Actor
	{
	public:
			ADD_OBJECT( TrPlayerController, OwningController )
			ADD_VAR( ::BoolProperty, IsInProgress, 0x4 )
			ADD_VAR( ::BoolProperty, PendingDelete, 0x2 )
			ADD_VAR( ::BoolProperty, CheckExtentsOnSpawn, 0x1 )
			ADD_VAR( ::FloatProperty, VehicleDist, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, GameObjectiveDist, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FlagStationDist, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, DisplayName, 0xFFFFFFFF )
			ADD_OBJECT( MaterialInstanceConstant, MICDisplay )
			ADD_VAR( ::IntProperty, CreditCost, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DegreeOfMovement, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CooldownTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CallTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BuildupTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, DatabaseId, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, CallInId, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
