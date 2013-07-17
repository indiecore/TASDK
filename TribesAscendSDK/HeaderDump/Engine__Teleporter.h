#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.Teleporter." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.Teleporter." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.Teleporter." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class Teleporter : public NavigationPoint
	{
	public:
			ADD_VAR( ::FloatProperty, LastFired, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, TargetVelocity, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bCanTeleportVehicles, 0x40 )
			ADD_VAR( ::BoolProperty, bEnabled, 0x20 )
			ADD_VAR( ::BoolProperty, bReversesZ, 0x10 )
			ADD_VAR( ::BoolProperty, bReversesY, 0x8 )
			ADD_VAR( ::BoolProperty, bReversesX, 0x4 )
			ADD_VAR( ::BoolProperty, bChangesYaw, 0x2 )
			ADD_VAR( ::BoolProperty, bChangesVelocity, 0x1 )
			ADD_VAR( ::NameProperty, ProductRequired, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, URL, 0xFFFFFFFF )
			bool CanTeleport( class Actor* A )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Teleporter.CanTeleport" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )( params + 0 ) = A;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Teleporter.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool Accept( class Actor* Incoming, class Actor* Source )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Teleporter.Accept" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Actor** )( params + 0 ) = Incoming;
				*( class Actor** )( params + 4 ) = Source;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void Touch( class Actor* Other, Vector HitLocation, Vector HitNormal )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Teleporter.Touch" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( class Actor** )( params + 0 ) = Other;
				*( Vector* )( params + 8 ) = HitLocation;
				*( Vector* )( params + 20 ) = HitNormal;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostTouch( class Actor* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Teleporter.PostTouch" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )( params + 0 ) = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class Actor* SpecialHandling( class Pawn* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Teleporter.SpecialHandling" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )( params + 0 ) = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Actor** )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
