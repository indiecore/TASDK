#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.SeqAct_AIMoveToActor." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.SeqAct_AIMoveToActor." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.SeqAct_AIMoveToActor." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SeqAct_AIMoveToActor : public SeqAct_Latent
	{
	public:
			class Actor* PickDestination( class Actor* Requestor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SeqAct_AIMoveToActor.PickDestination" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = Requestor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Actor** )( params + function->return_val_offset() );
			}

			ADD_VAR( ::IntProperty, LastDestinationChoice, 0xFFFFFFFF )
			ADD_OBJECT( Actor, LookAt )
			ADD_VAR( ::FloatProperty, MovementSpeedModifier, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bPickClosest, 0x2 )
			ADD_VAR( ::BoolProperty, bInterruptable, 0x1 )
			int GetObjClassVersion(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SeqAct_AIMoveToActor.GetObjClassVersion" );
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
