#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.SeqAct_ParticleEventGenerator." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.SeqAct_ParticleEventGenerator." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.SeqAct_ParticleEventGenerator." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SeqAct_ParticleEventGenerator : public SequenceAction
	{
	public:
			ADD_STRUCT( ::VectorProperty, EventNormal, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, EventVelocity, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, EventDirection, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, EventLocation, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, EventTime, 0xFFFFFFFF )
			ADD_OBJECT( Actor, Instigator )
			ADD_VAR( ::BoolProperty, bUseEmitterLocation, 0x2 )
			ADD_VAR( ::BoolProperty, bEnabled, 0x1 )
			int GetObjClassVersion(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SeqAct_ParticleEventGenerator.GetObjClassVersion" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
