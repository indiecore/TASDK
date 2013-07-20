#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UDKBase.UDKTeleporterBase." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UDKBase.UDKTeleporterBase." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UDKBase.UDKTeleporterBase." #y ); \
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
			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKTeleporterBase.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void InitializePortalEffect( class Actor* Dest )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKTeleporterBase.InitializePortalEffect" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = Dest;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool Accept( class Actor* Incoming, class Actor* Source )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKTeleporterBase.Accept" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Actor** )params = Incoming;
				*( class Actor** )( params + 4 ) = Source;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
