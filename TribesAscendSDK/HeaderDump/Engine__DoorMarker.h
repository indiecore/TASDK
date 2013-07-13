#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.DoorMarker." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.DoorMarker." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.DoorMarker." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class DoorMarker : public NavigationPoint
	{
	public:
			ADD_VAR( ::BoolProperty, bTempDisabledCollision, 0x10 )
			ADD_VAR( ::BoolProperty, bDoorOpen, 0x8 )
			ADD_VAR( ::BoolProperty, bBlockedWhenClosed, 0x4 )
			ADD_VAR( ::BoolProperty, bInitiallyClosed, 0x2 )
			ADD_VAR( ::BoolProperty, bWaitUntilCompletelyOpened, 0x1 )
			ADD_OBJECT( Actor, DoorTrigger )
			ADD_VAR( ::ByteProperty, DoorType, 0xFFFFFFFF )
			ADD_OBJECT( InterpActor, MyDoor )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
