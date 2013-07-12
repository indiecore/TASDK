#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.MatineeActor." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.MatineeActor." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.MatineeActor." #y ) ); \
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
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
