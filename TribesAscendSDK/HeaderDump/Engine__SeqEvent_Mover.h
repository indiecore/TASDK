#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.SeqEvent_Mover." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.SeqEvent_Mover." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.SeqEvent_Mover." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SeqEvent_Mover : public SequenceEvent
	{
	public:
			ADD_VAR( ::FloatProperty, StayOpenTime, 0xFFFFFFFF )
			void RegisterEvent(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SeqEvent_Mover.RegisterEvent" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NotifyEncroachingOn( class Actor* Hit )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SeqEvent_Mover.NotifyEncroachingOn" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = Hit;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NotifyAttached( class Actor* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SeqEvent_Mover.NotifyAttached" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NotifyDetached( class Actor* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SeqEvent_Mover.NotifyDetached" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NotifyFinishedOpen(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SeqEvent_Mover.NotifyFinishedOpen" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
