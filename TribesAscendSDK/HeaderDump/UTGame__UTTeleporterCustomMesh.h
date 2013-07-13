#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.UTTeleporterCustomMesh." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.UTTeleporterCustomMesh." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.UTTeleporterCustomMesh." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTTeleporterCustomMesh : public Teleporter
	{
	public:
			ADD_VAR( ::FloatProperty, LastTime, 0xFFFFFFFF )
			ADD_OBJECT( UTPawn, LastPawn )
			ADD_OBJECT( SoundCue, TeleportingSound )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
