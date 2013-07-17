#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " GameFramework.GameAIController." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty GameFramework.GameAIController." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty GameFramework.GameAIController." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GameAIController : public AIController
	{
	public:
			ADD_VAR( ::StrProperty, DemoActionString, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, CommandHistoryNum, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DebugTextMaxLen, 0xFFFFFFFF )
			ADD_OBJECT( FileLog, AILogFile )
			ADD_OBJECT( GameAICommand, CommandList )
			ADD_VAR( ::BoolProperty, bAIBroken, 0x80 )
			ADD_VAR( ::BoolProperty, bAIDrawDebug, 0x40 )
			ADD_VAR( ::BoolProperty, bMapBasedLogName, 0x20 )
			ADD_VAR( ::BoolProperty, bFlushAILogEachLine, 0x10 )
			ADD_VAR( ::BoolProperty, bAILogToWindow, 0x8 )
			ADD_VAR( ::BoolProperty, bAILogging, 0x4 )
			ADD_VAR( ::BoolProperty, bHasRunawayCommandList, 0x2 )
			ADD_VAR( ::BoolProperty, bUseAITree, 0x1 )
			ADD_OBJECT( AITree, AITree )
			void AllCommands( ScriptClass* BaseClass, class GameAICommand* &Cmd )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameAIController.AllCommands" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptClass** )( params + 0 ) = BaseClass;
				*( class GameAICommand** )( params + 4 ) = Cmd;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Cmd = *( class GameAICommand** )( params + 4 );
			}

			void PushCommand( class GameAICommand* NewCommand )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameAIController.PushCommand" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GameAICommand** )( params + 0 ) = NewCommand;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PopCommand( class GameAICommand* ToBePoppedCommand )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameAIController.PopCommand" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GameAICommand** )( params + 0 ) = ToBePoppedCommand;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool AbortCommand( class GameAICommand* AbortCmd, ScriptClass* AbortClass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameAIController.AbortCommand" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class GameAICommand** )( params + 0 ) = AbortCmd;
				*( ScriptClass** )( params + 4 ) = AbortClass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			class GameAICommand* GetActiveCommand(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameAIController.GetActiveCommand" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class GameAICommand** )( params + function->return_val_offset() );
			}

			void CheckCommandCount(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameAIController.CheckCommandCount" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DumpCommandStack(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameAIController.DumpCommandStack" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class GameAICommand* FindCommandOfClass( ScriptClass* SearchClass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameAIController.FindCommandOfClass" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )( params + 0 ) = SearchClass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class GameAICommand** )( params + function->return_val_offset() );
			}

			class GameAICommand* GetAICommandInStack( ScriptClass* InClass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameAIController.GetAICommandInStack" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )( params + 0 ) = InClass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class GameAICommand** )( params + function->return_val_offset() );
			}

			float GetDestinationOffset(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameAIController.GetDestinationOffset" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			void ReachedMoveGoal(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameAIController.ReachedMoveGoal" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ReachedIntermediateMoveGoal(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameAIController.ReachedIntermediateMoveGoal" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Destroyed(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameAIController.Destroyed" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RecordDemoAILog( ScriptArray< wchar_t > LogText )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameAIController.RecordDemoAILog" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = LogText;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AILog_Internal( ScriptArray< wchar_t > LogText, ScriptName LogCategory, bool bForce )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameAIController.AILog_Internal" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = LogText;
				*( ScriptName* )( params + 12 ) = LogCategory;
				*( bool* )( params + 20 ) = bForce;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetDesiredRotation( Rotator TargetDesiredRotation, bool InLockDesiredRotation, bool InUnlockWhenReached, float InterpolationTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameAIController.SetDesiredRotation" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Rotator* )( params + 0 ) = TargetDesiredRotation;
				*( bool* )( params + 12 ) = InLockDesiredRotation;
				*( bool* )( params + 16 ) = InUnlockWhenReached;
				*( float* )( params + 20 ) = InterpolationTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ScriptArray< wchar_t > GetActionString(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.GameAIController.GetActionString" );
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
