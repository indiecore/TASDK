#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.MatineeActor." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.MatineeActor." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.MatineeActor." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class MatineeActor : public Actor
	{
	public:
			ADD_VAR( ::FloatProperty, ClientSidePositionErrorTolerance, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, AIGroupInitStage, 0xFFFFFFFF )
			ADD_OBJECT( Pawn, AIGroupPawns )
			ADD_VAR( ::NameProperty, AIGroupNames, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Position, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, PlayRate, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, AllAIGroupsInitialized, 0x8 )
			ADD_VAR( ::BoolProperty, bPaused, 0x4 )
			ADD_VAR( ::BoolProperty, bReversePlayback, 0x2 )
			ADD_VAR( ::BoolProperty, bIsPlaying, 0x1 )
			ADD_OBJECT( SeqAct_Interp, InterpAction )
			void AddAIGroupActor( class InterpGroupInstAI* AIGroupInst )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.MatineeActor.AddAIGroupActor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class InterpGroupInstAI** )( params + 0 ) = AIGroupInst;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Update(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.MatineeActor.Update" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CheckPriorityRefresh(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.MatineeActor.CheckPriorityRefresh" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
