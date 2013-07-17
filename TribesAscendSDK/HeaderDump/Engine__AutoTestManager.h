#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.AutoTestManager." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.AutoTestManager." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.AutoTestManager." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class AutoTestManager : public Info
	{
	public:
			ADD_VAR( ::StrProperty, CommandStringToExec, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, NumMinutesPerMap, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, TravelPointsIncrement, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, NumRotationsIncrement, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, SentinelIdx, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, SentinelNavigationIdx, 0xFFFFFFFF )
			ADD_OBJECT( PlayerController, SentinelPC )
			ADD_VAR( ::StrProperty, SentinelTagDesc, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, SentinelTaskParameter, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, SentinelTaskDescription, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, AutomatedMapTestingTransitionMap, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, AutomatedTestingExecCommandToRunAtStartMatch, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, NumMapListCyclesDone, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, NumberOfMatchesPlayed, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, NumAutomatedMapTestingCycles, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, AutomatedTestingMapIndex, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, AutomatedPerfRemainingTime, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bSentinelStreamingLevelStillLoading, 0x100 )
			ADD_VAR( ::BoolProperty, bDoingASentinelRun, 0x80 )
			ADD_VAR( ::BoolProperty, bCheckingForMemLeaks, 0x40 )
			ADD_VAR( ::BoolProperty, bCheckingForFragmentation, 0x20 )
			ADD_VAR( ::BoolProperty, bExitOnCyclesComplete, 0x10 )
			ADD_VAR( ::BoolProperty, bAutomatedTestingWithOpen, 0x8 )
			ADD_VAR( ::BoolProperty, bUsingAutomatedTestingMapList, 0x4 )
			ADD_VAR( ::BoolProperty, bAutoContinueToNextRound, 0x2 )
			ADD_VAR( ::BoolProperty, bAutomatedPerfTesting, 0x1 )
			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AutoTestManager.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Timer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AutoTestManager.Timer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void InitializeOptions( ScriptArray< wchar_t > Options )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AutoTestManager.InitializeOptions" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = Options;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void BeginSentinelRun( ScriptArray< wchar_t > TaskDescription, ScriptArray< wchar_t > TaskParameter, ScriptArray< wchar_t > TagDesc )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AutoTestManager.BeginSentinelRun" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = TaskDescription;
				*( ScriptArray< wchar_t >* )( params + 12 ) = TaskParameter;
				*( ScriptArray< wchar_t >* )( params + 24 ) = TagDesc;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddSentinelPerTimePeriodStats( Vector InLocation, Rotator InRotation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AutoTestManager.AddSentinelPerTimePeriodStats" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )( params + 0 ) = InLocation;
				*( Rotator* )( params + 12 ) = InRotation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EndSentinelRun( byte RunResult )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AutoTestManager.EndSentinelRun" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = RunResult;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DoTravelTheWorld(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AutoTestManager.DoTravelTheWorld" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DoSentinelActionPerLoadedMap(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AutoTestManager.DoSentinelActionPerLoadedMap" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void HandlePerLoadedMapAudioStats(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AutoTestManager.HandlePerLoadedMapAudioStats" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void GetTravelLocations( ScriptName LevelName, class PlayerController* PC )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AutoTestManager.GetTravelLocations" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( ScriptName* )( params + 0 ) = LevelName;
				*( class PlayerController** )( params + 8 ) = PC;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DoSentinel_MemoryAtSpecificLocation( Vector InLocation, Rotator InRotation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AutoTestManager.DoSentinel_MemoryAtSpecificLocation" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )( params + 0 ) = InLocation;
				*( Rotator* )( params + 12 ) = InRotation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DoSentinel_PerfAtSpecificLocation( Vector &InLocation, Rotator &InRotation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AutoTestManager.DoSentinel_PerfAtSpecificLocation" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )( params + 0 ) = InLocation;
				*( Rotator* )( params + 12 ) = InRotation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				InLocation = *( Vector* )( params + 0 );
				InRotation = *( Rotator* )( params + 12 );
			}

			void DoSentinel_ViewDependentMemoryAtSpecificLocation( Vector &InLocation, Rotator &InRotation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AutoTestManager.DoSentinel_ViewDependentMemoryAtSpecificLocation" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )( params + 0 ) = InLocation;
				*( Rotator* )( params + 12 ) = InRotation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				InLocation = *( Vector* )( params + 0 );
				InRotation = *( Rotator* )( params + 12 );
			}

			void DoTimeBasedSentinelStatGathering(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AutoTestManager.DoTimeBasedSentinelStatGathering" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DoMemoryTracking(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AutoTestManager.DoMemoryTracking" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StartAutomatedMapTestTimer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AutoTestManager.StartAutomatedMapTestTimer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StartAutomatedMapTestTimerWorker(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AutoTestManager.StartAutomatedMapTestTimerWorker" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CloseAutomatedMapTestTimer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AutoTestManager.CloseAutomatedMapTestTimer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void IncrementAutomatedTestingMapIndex(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AutoTestManager.IncrementAutomatedTestingMapIndex" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void IncrementNumberOfMatchesPlayed(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AutoTestManager.IncrementNumberOfMatchesPlayed" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ScriptArray< wchar_t > GetNextAutomatedTestingMap(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AutoTestManager.GetNextAutomatedTestingMap" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			void StartMatch(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AutoTestManager.StartMatch" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool CheckForSentinelRun(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AutoTestManager.CheckForSentinelRun" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
