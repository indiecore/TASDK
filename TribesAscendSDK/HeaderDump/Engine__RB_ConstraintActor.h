#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.RB_ConstraintActor." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.RB_ConstraintActor." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.RB_ConstraintActor." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class RB_ConstraintActor : public RigidBodyBase
	{
	public:
			ADD_OBJECT( Actor, PulleyPivotActor2 )
			ADD_OBJECT( Actor, PulleyPivotActor1 )
			ADD_VAR( ::BoolProperty, bUpdateActor2RefFrame, 0x4 )
			ADD_VAR( ::BoolProperty, bUpdateActor1RefFrame, 0x2 )
			ADD_VAR( ::BoolProperty, bDisableCollision, 0x1 )
			ADD_OBJECT( RB_ConstraintInstance, ConstraintInstance )
			ADD_OBJECT( RB_ConstraintSetup, ConstraintSetup )
			ADD_OBJECT( Actor, ConstraintActor2 )
			ADD_OBJECT( Actor, ConstraintActor1 )
			void SetDisableCollision( bool NewDisableCollision )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.RB_ConstraintActor.SetDisableCollision" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = NewDisableCollision;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void InitConstraint( class Actor* Actor1, class Actor* Actor2, ScriptName Actor1Bone, ScriptName Actor2Bone, float BreakThreshold )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.RB_ConstraintActor.InitConstraint" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( class Actor** )( params + 0 ) = Actor1;
				*( class Actor** )( params + 4 ) = Actor2;
				*( ScriptName* )( params + 8 ) = Actor1Bone;
				*( ScriptName* )( params + 16 ) = Actor2Bone;
				*( float* )( params + 24 ) = BreakThreshold;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TermConstraint(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.RB_ConstraintActor.TermConstraint" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnDestroy( class SeqAct_Destroy* Action )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.RB_ConstraintActor.OnDestroy" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SeqAct_Destroy** )( params + 0 ) = Action;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnToggle( class SeqAct_Toggle* Action )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.RB_ConstraintActor.OnToggle" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SeqAct_Toggle** )( params + 0 ) = Action;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnToggleConstraintDrive( class SeqAct_ToggleConstraintDrive* Action )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.RB_ConstraintActor.OnToggleConstraintDrive" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SeqAct_ToggleConstraintDrive** )( params + 0 ) = Action;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
