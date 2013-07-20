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
			bool InitCommandUserActor( class GameAIController* AI, class Actor* UserActor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameAICommand.InitCommandUserActor" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class GameAIController** )params = AI;
				*( class Actor** )( params + 4 ) = UserActor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool InitCommand( class GameAIController* AI )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameAICommand.InitCommand" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GameAIController** )params = AI;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void InternalPrePushed( class GameAIController* AI )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameAICommand.InternalPrePushed" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GameAIController** )params = AI;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void InternalPushed(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameAICommand.InternalPushed" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void InternalPopped(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameAICommand.InternalPopped" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void InternalPaused( class GameAICommand* NewCommand )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameAICommand.InternalPaused" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GameAICommand** )params = NewCommand;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void InternalResumed( ScriptName OldCommandName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameAICommand.InternalResumed" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = OldCommandName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void InternalTick( float DeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameAICommand.InternalTick" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = DeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool ShouldIgnoreNotifies(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameAICommand.ShouldIgnoreNotifies" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void Tick( float DeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameAICommand.Tick" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = DeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool AllowTransitionTo( ScriptClass* AttemptCommand )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameAICommand.AllowTransitionTo" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )params = AttemptCommand;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool AllowStateTransitionTo( ScriptName StateName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameAICommand.AllowStateTransitionTo" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = StateName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void PrePushed( class GameAIController* AI )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameAICommand.PrePushed" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GameAIController** )params = AI;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostPopped(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameAICommand.PostPopped" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Pushed(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameAICommand.Pushed" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Popped(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameAICommand.Popped" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Paused( class GameAICommand* NewCommand )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameAICommand.Paused" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GameAICommand** )params = NewCommand;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Resumed( ScriptName OldCommandName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameAICommand.Resumed" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = OldCommandName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ScriptArray< wchar_t > GetDumpString(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameAICommand.GetDumpString" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			void DrawDebug( class HUD* H, ScriptName Category )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameAICommand.DrawDebug" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class HUD** )params = H;
				*( ScriptName* )( params + 4 ) = Category;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void GetDebugOverheadText( class PlayerController* PC )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameAICommand.GetDebugOverheadText" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class PlayerController** )params = PC;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ScriptArray< wchar_t > GetDebugVerboseText(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameAICommand.GetDebugVerboseText" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
