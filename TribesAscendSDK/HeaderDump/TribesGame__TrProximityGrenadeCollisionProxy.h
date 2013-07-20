#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrProximityGrenadeCollisionProxy." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrProximityGrenadeCollisionProxy." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrProximityGrenadeCollisionProxy." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrProximityGrenadeCollisionProxy : public TrCollisionProxy
	{
	public:
			void OnPawnAdded( class Pawn* aPawn )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProximityGrenadeCollisionProxy.OnPawnAdded" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )params = aPawn;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnPawnRemoved( class Pawn* aPawn )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProximityGrenadeCollisionProxy.OnPawnRemoved" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )params = aPawn;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Touch( class Actor* Other, Vector HitLocation, Vector HitNormal )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProximityGrenadeCollisionProxy.Touch" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( class Actor** )params = Other;
				*( Vector* )( params + 8 ) = HitLocation;
				*( Vector* )( params + 20 ) = HitNormal;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
