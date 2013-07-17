#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.ParticleSystemComponent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.ParticleSystemComponent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.ParticleSystemComponent." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class ParticleSystemComponent : public PrimitiveComponent
	{
	public:
			void SetTemplate( class ParticleSystem* NewTemplate )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ParticleSystemComponent.SetTemplate" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class ParticleSystem** )( params + 0 ) = NewTemplate;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ActivateSystem( bool bFlagAsJustAttached )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ParticleSystemComponent.ActivateSystem" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bFlagAsJustAttached;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetActive( bool bNowActive, bool bFlagAsJustAttached )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ParticleSystemComponent.SetActive" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( bool* )( params + 0 ) = bNowActive;
				*( bool* )( params + 4 ) = bFlagAsJustAttached;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnSystemFinished(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ParticleSystemComponent.OnSystemFinished" );
				byte *params = ( byte* )( malloc( 4 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DeactivateSystem(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ParticleSystemComponent.DeactivateSystem" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void KillParticlesForced(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ParticleSystemComponent.KillParticlesForced" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void KillParticlesInEmitter( ScriptName InEmitterName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ParticleSystemComponent.KillParticlesInEmitter" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = InEmitterName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetSkipUpdateDynamicDataDuringTick( bool bInSkipUpdateDynamicDataDuringTick )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ParticleSystemComponent.SetSkipUpdateDynamicDataDuringTick" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bInSkipUpdateDynamicDataDuringTick;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool GetSkipUpdateDynamicDataDuringTick(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ParticleSystemComponent.GetSkipUpdateDynamicDataDuringTick" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SetKillOnDeactivate( int EmitterIndex, bool bKill )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ParticleSystemComponent.SetKillOnDeactivate" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = EmitterIndex;
				*( bool* )( params + 4 ) = bKill;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetKillOnCompleted( int EmitterIndex, bool bKill )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ParticleSystemComponent.SetKillOnCompleted" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = EmitterIndex;
				*( bool* )( params + 4 ) = bKill;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RewindEmitterInstance( int EmitterIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ParticleSystemComponent.RewindEmitterInstance" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = EmitterIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RewindEmitterInstances(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ParticleSystemComponent.RewindEmitterInstances" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetBeamType( int EmitterIndex, int NewMethod )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ParticleSystemComponent.SetBeamType" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = EmitterIndex;
				*( int* )( params + 4 ) = NewMethod;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetBeamTessellationFactor( int EmitterIndex, float NewFactor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ParticleSystemComponent.SetBeamTessellationFactor" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = EmitterIndex;
				*( float* )( params + 4 ) = NewFactor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetBeamEndPoint( int EmitterIndex, Vector NewEndPoint )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ParticleSystemComponent.SetBeamEndPoint" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( int* )( params + 0 ) = EmitterIndex;
				*( Vector* )( params + 4 ) = NewEndPoint;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetBeamDistance( int EmitterIndex, float Distance )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ParticleSystemComponent.SetBeamDistance" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = EmitterIndex;
				*( float* )( params + 4 ) = Distance;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetBeamSourcePoint( int EmitterIndex, Vector NewSourcePoint, int SourceIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ParticleSystemComponent.SetBeamSourcePoint" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( int* )( params + 0 ) = EmitterIndex;
				*( Vector* )( params + 4 ) = NewSourcePoint;
				*( int* )( params + 16 ) = SourceIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetBeamSourceTangent( int EmitterIndex, Vector NewTangentPoint, int SourceIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ParticleSystemComponent.SetBeamSourceTangent" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( int* )( params + 0 ) = EmitterIndex;
				*( Vector* )( params + 4 ) = NewTangentPoint;
				*( int* )( params + 16 ) = SourceIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetBeamSourceStrength( int EmitterIndex, float NewSourceStrength, int SourceIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ParticleSystemComponent.SetBeamSourceStrength" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( int* )( params + 0 ) = EmitterIndex;
				*( float* )( params + 4 ) = NewSourceStrength;
				*( int* )( params + 8 ) = SourceIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetBeamTargetPoint( int EmitterIndex, Vector NewTargetPoint, int TargetIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ParticleSystemComponent.SetBeamTargetPoint" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( int* )( params + 0 ) = EmitterIndex;
				*( Vector* )( params + 4 ) = NewTargetPoint;
				*( int* )( params + 16 ) = TargetIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetBeamTargetTangent( int EmitterIndex, Vector NewTangentPoint, int TargetIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ParticleSystemComponent.SetBeamTargetTangent" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( int* )( params + 0 ) = EmitterIndex;
				*( Vector* )( params + 4 ) = NewTangentPoint;
				*( int* )( params + 16 ) = TargetIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetBeamTargetStrength( int EmitterIndex, float NewTargetStrength, int TargetIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ParticleSystemComponent.SetBeamTargetStrength" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( int* )( params + 0 ) = EmitterIndex;
				*( float* )( params + 4 ) = NewTargetStrength;
				*( int* )( params + 8 ) = TargetIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int DetermineLODLevelForLocation( Vector &EffectLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ParticleSystemComponent.DetermineLODLevelForLocation" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )( params + 0 ) = EffectLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				EffectLocation = *( Vector* )( params + 0 );
				return *( int* )( params + function->return_val_offset() );
			}

			void SetLODLevel( int InLODLevel )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ParticleSystemComponent.SetLODLevel" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = InLODLevel;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetEditorLODLevel( int InLODLevel )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ParticleSystemComponent.SetEditorLODLevel" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = InLODLevel;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int GetLODLevel(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ParticleSystemComponent.GetLODLevel" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			int GetEditorLODLevel(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ParticleSystemComponent.GetEditorLODLevel" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void SetFloatParameter( ScriptName ParameterName, float Param )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ParticleSystemComponent.SetFloatParameter" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )( params + 0 ) = ParameterName;
				*( float* )( params + 8 ) = Param;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetFloatRandParameter( ScriptName ParameterName, float Param, float ParamLow )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ParticleSystemComponent.SetFloatRandParameter" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptName* )( params + 0 ) = ParameterName;
				*( float* )( params + 8 ) = Param;
				*( float* )( params + 12 ) = ParamLow;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetVectorParameter( ScriptName ParameterName, Vector Param )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ParticleSystemComponent.SetVectorParameter" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptName* )( params + 0 ) = ParameterName;
				*( Vector* )( params + 8 ) = Param;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetVectorRandParameter( ScriptName ParameterName, Vector &Param, Vector &ParamLow )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ParticleSystemComponent.SetVectorRandParameter" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( ScriptName* )( params + 0 ) = ParameterName;
				*( Vector* )( params + 8 ) = Param;
				*( Vector* )( params + 20 ) = ParamLow;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Param = *( Vector* )( params + 8 );
				ParamLow = *( Vector* )( params + 20 );
			}

			void SetColorParameter( ScriptName ParameterName, void* Param )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ParticleSystemComponent.SetColorParameter" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )( params + 0 ) = ParameterName;
				*( void** )( params + 8 ) = Param;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetActorParameter( ScriptName ParameterName, class Actor* Param )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ParticleSystemComponent.SetActorParameter" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )( params + 0 ) = ParameterName;
				*( class Actor** )( params + 8 ) = Param;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetMaterialParameter( ScriptName ParameterName, class MaterialInterface* Param )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ParticleSystemComponent.SetMaterialParameter" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )( params + 0 ) = ParameterName;
				*( class MaterialInterface** )( params + 8 ) = Param;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool GetFloatParameter( ScriptName InName, float &OutFloat )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ParticleSystemComponent.GetFloatParameter" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )( params + 0 ) = InName;
				*( float* )( params + 8 ) = OutFloat;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				OutFloat = *( float* )( params + 8 );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool GetVectorParameter( ScriptName InName, Vector &OutVector )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ParticleSystemComponent.GetVectorParameter" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptName* )( params + 0 ) = InName;
				*( Vector* )( params + 8 ) = OutVector;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				OutVector = *( Vector* )( params + 8 );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool GetColorParameter( ScriptName InName, void* &OutColor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ParticleSystemComponent.GetColorParameter" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )( params + 0 ) = InName;
				*( void** )( params + 8 ) = OutColor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				OutColor = *( void** )( params + 8 );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool GetActorParameter( ScriptName InName, class Actor* &OutActor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ParticleSystemComponent.GetActorParameter" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )( params + 0 ) = InName;
				*( class Actor** )( params + 8 ) = OutActor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				OutActor = *( class Actor** )( params + 8 );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool GetMaterialParameter( ScriptName InName, class MaterialInterface* &OutMaterial )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ParticleSystemComponent.GetMaterialParameter" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )( params + 0 ) = InName;
				*( class MaterialInterface** )( params + 8 ) = OutMaterial;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				OutMaterial = *( class MaterialInterface** )( params + 8 );
				return *( bool* )( params + function->return_val_offset() );
			}

			void ClearParameter( ScriptName ParameterName, byte ParameterType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ParticleSystemComponent.ClearParameter" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( ScriptName* )( params + 0 ) = ParameterName;
				*( byte* )( params + 8 ) = ParameterType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ResetToDefaults(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ParticleSystemComponent.ResetToDefaults" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetStopSpawning( int InEmitterIndex, bool bInStopSpawning )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.ParticleSystemComponent.SetStopSpawning" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = InEmitterIndex;
				*( bool* )( params + 4 ) = bInStopSpawning;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_OBJECT( ParticleSystem, Template )
			ADD_OBJECT( ScriptClass, LightEnvironmentClass )
			ADD_VAR( ::BoolProperty, bAutoActivate, 0x1 )
			ADD_VAR( ::BoolProperty, bWasCompleted, 0x2 )
			ADD_VAR( ::BoolProperty, bSuppressSpawning, 0x4 )
			ADD_VAR( ::BoolProperty, bWasDeactivated, 0x8 )
			ADD_VAR( ::BoolProperty, bResetOnDetach, 0x10 )
			ADD_VAR( ::BoolProperty, bUpdateOnDedicatedServer, 0x20 )
			ADD_VAR( ::BoolProperty, bJustAttached, 0x40 )
			ADD_VAR( ::BoolProperty, bIsActive, 0x80 )
			ADD_VAR( ::BoolProperty, bWarmingUp, 0x100 )
			ADD_VAR( ::BoolProperty, bIsCachedInPool, 0x200 )
			ADD_VAR( ::BoolProperty, bOverrideLODMethod, 0x400 )
			ADD_VAR( ::BoolProperty, bSkipUpdateDynamicDataDuringTick, 0x800 )
			ADD_VAR( ::BoolProperty, bUpdateComponentInTick, 0x1000 )
			ADD_VAR( ::BoolProperty, bDeferredBeamUpdate, 0x2000 )
			ADD_VAR( ::BoolProperty, bForcedInActive, 0x4000 )
			ADD_VAR( ::BoolProperty, bIsWarmingUp, 0x8000 )
			ADD_VAR( ::BoolProperty, bIsViewRelevanceDirty, 0x10000 )
			ADD_VAR( ::BoolProperty, bRecacheViewRelevance, 0x20000 )
			ADD_VAR( ::BoolProperty, bLODUpdatePending, 0x40000 )
			ADD_VAR( ::BoolProperty, bSkipSpawnCountCheck, 0x80000 )
			ADD_STRUCT( ::VectorProperty, OldPosition, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, PartSysVelocity, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, WarmupTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, LODLevel, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SecondsBeforeInactive, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TimeSinceLastForceUpdateTransform, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxTimeBeforeForceUpdateTransform, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, EditorLODLevel, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AccumTickTime, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, LODMethod, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, ReplayState, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, ReplayClipIDNumber, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, ReplayFrameIndex, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AccumLODDistanceCheckTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CustomTimeDilation, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, EmitterDelay, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
