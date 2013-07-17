#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.PortalTeleporter." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.PortalTeleporter." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.PortalTeleporter." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class PortalTeleporter : public SceneCapturePortalActor
	{
	public:
			ADD_VAR( ::BoolProperty, bCanTeleportVehicles, 0x4 )
			ADD_VAR( ::BoolProperty, bAlwaysTeleportNonPawns, 0x2 )
			ADD_VAR( ::BoolProperty, bMovablePortal, 0x1 )
			ADD_OBJECT( PortalMarker, MyMarker )
			ADD_VAR( ::IntProperty, TextureResolutionY, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, TextureResolutionX, 0xFFFFFFFF )
			ADD_OBJECT( PortalTeleporter, SisterPortal )
			bool TransformActor( class Actor* A )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PortalTeleporter.TransformActor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )( params + 0 ) = A;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			Vector TransformVectorDir( Vector V )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PortalTeleporter.TransformVectorDir" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )( params + 0 ) = V;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			Vector TransformHitLocation( Vector HitLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PortalTeleporter.TransformHitLocation" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )( params + 0 ) = HitLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			class TextureRenderTarget2D* CreatePortalTexture(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PortalTeleporter.CreatePortalTexture" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class TextureRenderTarget2D** )( params + function->return_val_offset() );
			}

			bool StopsProjectile( class Projectile* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PortalTeleporter.StopsProjectile" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Projectile** )( params + 0 ) = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
