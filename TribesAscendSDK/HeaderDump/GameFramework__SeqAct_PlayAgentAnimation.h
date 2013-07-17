#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " GameFramework.SeqAct_PlayAgentAnimation." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty GameFramework.SeqAct_PlayAgentAnimation." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty GameFramework.SeqAct_PlayAgentAnimation." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SeqAct_PlayAgentAnimation : public SeqAct_Latent
	{
	public:
			ADD_OBJECT( Actor, ActionTarget )
			ADD_VAR( ::FloatProperty, LoopTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, LoopIndex, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bBlendBetweenAnims, 0x8 )
			ADD_VAR( ::BoolProperty, bLooping, 0x4 )
			ADD_VAR( ::BoolProperty, bFaceActionTargetFirst, 0x2 )
			ADD_VAR( ::BoolProperty, bUseRootMotion, 0x1 )
			ADD_VAR( ::FloatProperty, BlendOutTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BlendInTime, 0xFFFFFFFF )
			int GetObjClassVersion(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.SeqAct_PlayAgentAnimation.GetObjClassVersion" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void SetCurrentAnimationActionFor( class GameCrowdAgentSkeletal* Agent )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.SeqAct_PlayAgentAnimation.SetCurrentAnimationActionFor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GameCrowdAgentSkeletal** )( params + 0 ) = Agent;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
