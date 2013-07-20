#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.ParticleEventManager." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.ParticleEventManager." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.ParticleEventManager." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class ParticleEventManager : public Actor
	{
	public:
			void HandleParticleModuleEventSendToGame( class ParticleModuleEventSendToGame* InEvent, Vector &InCollideDirection, Vector &InHitLocation, Vector &InHitNormal, ScriptName &InBoneName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ParticleEventManager.HandleParticleModuleEventSendToGame" );
				byte *params = ( byte* )( malloc( 48 ) );
				*( class ParticleModuleEventSendToGame** )params = InEvent;
				*( Vector* )( params + 4 ) = InCollideDirection;
				*( Vector* )( params + 16 ) = InHitLocation;
				*( Vector* )( params + 28 ) = InHitNormal;
				*( ScriptName* )( params + 40 ) = InBoneName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				InCollideDirection = *( Vector* )( params + 4 );
				InHitLocation = *( Vector* )( params + 16 );
				InHitNormal = *( Vector* )( params + 28 );
				InBoneName = *( ScriptName* )( params + 40 );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
