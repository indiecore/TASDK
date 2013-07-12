#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " GameFramework.GameCrowdBehavior_PlayAnimation." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty GameFramework.GameCrowdBehavior_PlayAnimation." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty GameFramework.GameCrowdBehavior_PlayAnimation." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GameCrowdBehavior_PlayAnimation : public GameCrowdAgentBehavior
	{
	public:
			ADD_VAR( ::IntProperty, AnimationIndex, 0xFFFFFFFF )
			ADD_OBJECT( SeqAct_PlayAgentAnimation, AnimSequence )
			ADD_VAR( ::FloatProperty, LoopTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, LoopIndex, 0xFFFFFFFF )
			ADD_OBJECT( Actor, CustomActionTarget )
			ADD_VAR( ::BoolProperty, bBlendBetweenAnims, 0x8 )
			ADD_VAR( ::BoolProperty, bLooping, 0x4 )
			ADD_VAR( ::BoolProperty, bLookAtPlayer, 0x2 )
			ADD_VAR( ::BoolProperty, bUseRootMotion, 0x1 )
			ADD_VAR( ::FloatProperty, BlendOutTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BlendInTime, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
