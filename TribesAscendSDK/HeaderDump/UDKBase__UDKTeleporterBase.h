#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " UDKBase.UDKTeleporterBase." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty UDKBase.UDKTeleporterBase." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty UDKBase.UDKTeleporterBase." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UDKTeleporterBase : public Teleporter
	{
	public:
			ADD_OBJECT( SoundCue, TeleportingSound )
			ADD_VAR( ::NameProperty, PortalTextureParameter, 0xFFFFFFFF )
			ADD_OBJECT( MaterialInstanceConstant, PortalMaterialInstance )
			ADD_OBJECT( MaterialInterface, PortalMaterial )
			ADD_OBJECT( Actor, PortalViewTarget )
			ADD_VAR( ::IntProperty, TextureResolutionY, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, TextureResolutionX, 0xFFFFFFFF )
			ADD_OBJECT( TextureRenderTarget2D, TextureTarget )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
