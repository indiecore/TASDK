#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.SequenceEvent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.SequenceEvent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.SequenceEvent." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SequenceEvent : public SequenceOp
	{
	public:
			bool CheckActivate( class Actor* InOriginator, class Actor* InInstigator, bool bTest, bool bPushTop )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SequenceEvent.CheckActivate" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( class Actor** )params = InOriginator;
				*( class Actor** )( params + 4 ) = InInstigator;
				*( bool* )( params + 8 ) = bTest;
				*( bool* )( params + 24 ) = bPushTop;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::BoolProperty, bEnabled, 0x1 )
			ADD_VAR( ::IntProperty, MaxTriggerCount, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, TriggerCount, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bPlayerOnly, 0x2 )
			ADD_VAR( ::IntProperty, MaxWidth, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, Priority, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bClientSideOnly, 0x8 )
			ADD_VAR( ::BoolProperty, bRegistered, 0x4 )
			ADD_VAR( ::FloatProperty, ReTriggerDelay, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ActivationTime, 0xFFFFFFFF )
			ADD_OBJECT( Actor, Instigator )
			ADD_OBJECT( Actor, Originator )
			void RegisterEvent(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SequenceEvent.RegisterEvent" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Reset(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SequenceEvent.Reset" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Toggled(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SequenceEvent.Toggled" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
