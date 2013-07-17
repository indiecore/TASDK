#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " GameFramework.GameCrowdAgentSkeletal." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty GameFramework.GameCrowdAgentSkeletal." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty GameFramework.GameCrowdAgentSkeletal." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GameCrowdAgentSkeletal : public GameCrowdAgent
	{
	public:
			ADD_VAR( ::FloatProperty, MaxAnimationDistanceSq, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxAnimationDistance, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bAnimateThisTick, 0x8 )
			ADD_VAR( ::BoolProperty, bIsPlayingDeathAnimation, 0x4 )
			ADD_VAR( ::BoolProperty, bIsPlayingIdleAnimation, 0x2 )
			ADD_VAR( ::BoolProperty, bUseRootMotionVelocity, 0x1 )
			ADD_VAR( ::FloatProperty, MaxTargetAcquireTime, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, MoveSyncGroupName, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxSpeedBlendChangeSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AnimVelRate, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SpeedBlendEnd, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SpeedBlendStart, 0xFFFFFFFF )
			ADD_OBJECT( AnimTree, AgentTree )
			ADD_OBJECT( AnimNodeSequence, RunSeqNode )
			ADD_OBJECT( AnimNodeSequence, WalkSeqNode )
			ADD_OBJECT( AnimNodeSequence, ActionSeqNode )
			ADD_OBJECT( AnimNodeSlot, FullBodySlot )
			ADD_OBJECT( AnimNodeBlend, SpeedBlendNode )
			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdAgentSkeletal.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetLighting( bool bEnableLightEnvironment, void* AgentLightingChannel, bool bCastShadows )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdAgentSkeletal.SetLighting" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( bool* )( params + 0 ) = bEnableLightEnvironment;
				*( void** )( params + 4 ) = AgentLightingChannel;
				*( bool* )( params + 8 ) = bCastShadows;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayDeath( Vector KillMomentum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdAgentSkeletal.PlayDeath" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )( params + 0 ) = KillMomentum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetRootMotion( bool bRootMotionEnabled )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdAgentSkeletal.SetRootMotion" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bRootMotionEnabled;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnPlayAgentAnimation( class SeqAct_PlayAgentAnimation* Action )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdAgentSkeletal.OnPlayAgentAnimation" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SeqAct_PlayAgentAnimation** )( params + 0 ) = Action;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearLatentAnimation(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdAgentSkeletal.ClearLatentAnimation" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayIdleAnimation(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdAgentSkeletal.PlayIdleAnimation" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StopIdleAnimation(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdAgentSkeletal.StopIdleAnimation" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnAnimEnd( class AnimNodeSequence* SeqNode, float PlayedTime, float ExcessTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdAgentSkeletal.OnAnimEnd" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class AnimNodeSequence** )( params + 0 ) = SeqNode;
				*( float* )( params + 4 ) = PlayedTime;
				*( float* )( params + 8 ) = ExcessTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CreateAttachments(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameCrowdAgentSkeletal.CreateAttachments" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
