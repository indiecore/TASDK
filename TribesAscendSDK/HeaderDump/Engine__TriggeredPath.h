#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.TriggeredPath." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.TriggeredPath." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.TriggeredPath." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TriggeredPath : public NavigationPoint
	{
	public:
			ADD_OBJECT( Actor, MyTrigger )
			ADD_VAR( ::BoolProperty, bOpen, 0x1 )
			void OnToggle( class SeqAct_Toggle* inAction )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.TriggeredPath.OnToggle" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SeqAct_Toggle** )params = inAction;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class Actor* SpecialHandling( class Pawn* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.TriggeredPath.SpecialHandling" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )params = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Actor** )( params + function->return_val_offset() );
			}

			bool SuggestMovePreparation( class Pawn* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.TriggeredPath.SuggestMovePreparation" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )params = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
