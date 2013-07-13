#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " GameFramework.GameAICommand." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty GameFramework.GameAICommand." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty GameFramework.GameAICommand." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GameAICommand : public AICommandBase
	{
	public:
			ADD_VAR( ::BoolProperty, bPendingPop, 0x20 )
			ADD_VAR( ::BoolProperty, bIgnoreStepAside, 0x10 )
			ADD_VAR( ::BoolProperty, bIgnoreNotifies, 0x8 )
			ADD_VAR( ::BoolProperty, bAborted, 0x4 )
			ADD_VAR( ::BoolProperty, bReplaceActiveSameClassInstance, 0x2 )
			ADD_VAR( ::BoolProperty, bAllowNewSameClassInstance, 0x1 )
			ADD_VAR( ::NameProperty, Status, 0xFFFFFFFF )
			ADD_OBJECT( GameAIController, GameAIOwner )
			ADD_VAR( ::NameProperty, ChildStatus, 0xFFFFFFFF )
			ADD_OBJECT( GameAICommand, ChildCommand )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
