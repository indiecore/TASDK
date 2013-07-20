#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UDKBase.UDKParticleSystemComponent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UDKBase.UDKParticleSystemComponent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UDKBase.UDKParticleSystemComponent." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UDKParticleSystemComponent : public ParticleSystemComponent
	{
	public:
			ADD_STRUCT( ::VectorProperty, SavedScale3D, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bHasSavedScale3D, 0x1 )
			ADD_VAR( ::FloatProperty, FOV, 0xFFFFFFFF )
			void SetFOV( float NewFOV )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKParticleSystemComponent.SetFOV" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = NewFOV;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
