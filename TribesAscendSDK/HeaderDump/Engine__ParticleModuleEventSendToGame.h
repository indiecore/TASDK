#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.ParticleModuleEventSendToGame." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.ParticleModuleEventSendToGame." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.ParticleModuleEventSendToGame." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class ParticleModuleEventSendToGame : public Object
	{
	public:
			void DoEvent( Vector &InCollideDirection, Vector &InHitLocation, Vector &InHitNormal, ScriptName &InBoneName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ParticleModuleEventSendToGame.DoEvent" );
				byte *params = ( byte* )( malloc( 44 ) );
				*( Vector* )( params + 0 ) = InCollideDirection;
				*( Vector* )( params + 12 ) = InHitLocation;
				*( Vector* )( params + 24 ) = InHitNormal;
				*( ScriptName* )( params + 36 ) = InBoneName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				InCollideDirection = *( Vector* )( params + 0 );
				InHitLocation = *( Vector* )( params + 12 );
				InHitNormal = *( Vector* )( params + 24 );
				InBoneName = *( ScriptName* )( params + 36 );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
