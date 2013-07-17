#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.SkeletalMeshActor." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.SkeletalMeshActor." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.SkeletalMeshActor." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SkeletalMeshActor : public Actor
	{
	public:
			ADD_VAR( ::FloatProperty, SavedCurrentTime, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, SavedAnimSeqName, 0xFFFFFFFF )
			ADD_OBJECT( MaterialInterface, ReplicatedMaterial )
			ADD_OBJECT( SkeletalMesh, ReplicatedMesh )
			ADD_VAR( ::BoolProperty, bCollideActors_OldValue, 0x8 )
			ADD_VAR( ::BoolProperty, bForceSaveInCheckpoint, 0x4 )
			ADD_VAR( ::BoolProperty, bShouldDoAnimNotifies, 0x2 )
			ADD_VAR( ::BoolProperty, bDamageAppliesImpulse, 0x1 )
			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshActor.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Destroyed(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshActor.Destroyed" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateAnimSetList(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshActor.UpdateAnimSetList" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ReplicatedEvent( ScriptName VarName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshActor.ReplicatedEvent" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = VarName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnToggle( class SeqAct_Toggle* Action )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshActor.OnToggle" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SeqAct_Toggle** )( params + 0 ) = Action;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnSetMaterial( class SeqAct_SetMaterial* Action )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshActor.OnSetMaterial" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SeqAct_SetMaterial** )( params + 0 ) = Action;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void BeginAnimControl( class InterpGroup* InInterpGroup )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshActor.BeginAnimControl" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class InterpGroup** )( params + 0 ) = InInterpGroup;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void MAT_BeginAnimControl( class InterpGroup* InInterpGroup )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshActor.MAT_BeginAnimControl" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class InterpGroup** )( params + 0 ) = InInterpGroup;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetAnimPosition( ScriptName SlotName, int ChannelIndex, ScriptName InAnimSeqName, float InPosition, bool bFireNotifies, bool bLooping, bool bEnableRootMotion )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshActor.SetAnimPosition" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( ScriptName* )( params + 0 ) = SlotName;
				*( int* )( params + 8 ) = ChannelIndex;
				*( ScriptName* )( params + 12 ) = InAnimSeqName;
				*( float* )( params + 20 ) = InPosition;
				*( bool* )( params + 24 ) = bFireNotifies;
				*( bool* )( params + 28 ) = bLooping;
				*( bool* )( params + 32 ) = bEnableRootMotion;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FinishAnimControl( class InterpGroup* InInterpGroup )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshActor.FinishAnimControl" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class InterpGroup** )( params + 0 ) = InInterpGroup;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void MAT_FinishAnimControl( class InterpGroup* InInterpGroup )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshActor.MAT_FinishAnimControl" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class InterpGroup** )( params + 0 ) = InInterpGroup;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool PlayActorFaceFXAnim( class FaceFXAnimSet* AnimSet, ScriptArray< wchar_t > GroupName, ScriptArray< wchar_t > SeqName, class SoundCue* SoundCueToPlay )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshActor.PlayActorFaceFXAnim" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( class FaceFXAnimSet** )( params + 0 ) = AnimSet;
				*( ScriptArray< wchar_t >* )( params + 4 ) = GroupName;
				*( ScriptArray< wchar_t >* )( params + 16 ) = SeqName;
				*( class SoundCue** )( params + 28 ) = SoundCueToPlay;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void StopActorFaceFXAnim(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshActor.StopActorFaceFXAnim" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void* GetFaceFXAudioComponent(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshActor.GetFaceFXAudioComponent" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			void OnPlayFaceFXAnim( class SeqAct_PlayFaceFXAnim* inAction )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshActor.OnPlayFaceFXAnim" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SeqAct_PlayFaceFXAnim** )( params + 0 ) = inAction;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class FaceFXAsset* GetActorFaceFXAsset(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshActor.GetActorFaceFXAsset" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class FaceFXAsset** )( params + function->return_val_offset() );
			}

			bool IsActorPlayingFaceFXAnim(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshActor.IsActorPlayingFaceFXAnim" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void OnSetMesh( class SeqAct_SetMesh* Action )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshActor.OnSetMesh" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SeqAct_SetMesh** )( params + 0 ) = Action;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnUpdatePhysBonesFromAnim( class SeqAct_UpdatePhysBonesFromAnim* Action )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshActor.OnUpdatePhysBonesFromAnim" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SeqAct_UpdatePhysBonesFromAnim** )( params + 0 ) = Action;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnSetSkelControlTarget( class SeqAct_SetSkelControlTarget* Action )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshActor.OnSetSkelControlTarget" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SeqAct_SetSkelControlTarget** )( params + 0 ) = Action;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DoKismetAttachment( class Actor* Attachment, class SeqAct_AttachToActor* Action )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshActor.DoKismetAttachment" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Actor** )( params + 0 ) = Attachment;
				*( class SeqAct_AttachToActor** )( params + 4 ) = Action;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TakeDamage( int Damage, class Controller* EventInstigator, Vector HitLocation, Vector Momentum, ScriptClass* DamageType, void* HitInfo, class Actor* DamageCauser )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshActor.TakeDamage" );
				byte *params = ( byte* )( malloc( 68 ) );
				*( int* )( params + 0 ) = Damage;
				*( class Controller** )( params + 4 ) = EventInstigator;
				*( Vector* )( params + 8 ) = HitLocation;
				*( Vector* )( params + 20 ) = Momentum;
				*( ScriptClass** )( params + 32 ) = DamageType;
				*( void** )( params + 36 ) = HitInfo;
				*( class Actor** )( params + 64 ) = DamageCauser;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool ShouldSaveForCheckpoint(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshActor.ShouldSaveForCheckpoint" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void CreateCheckpointRecord( void* &Record )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshActor.CreateCheckpointRecord" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( void** )( params + 0 ) = Record;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Record = *( void** )( params + 0 );
			}

			void ApplyCheckpointRecord( void* &Record )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshActor.ApplyCheckpointRecord" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( void** )( params + 0 ) = Record;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Record = *( void** )( params + 0 );
			}

			bool PlayParticleEffect( class AnimNotify_PlayParticleEffect* AnimNotifyData )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshActor.PlayParticleEffect" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class AnimNotify_PlayParticleEffect** )( params + 0 ) = AnimNotifyData;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SkelMeshActorOnParticleSystemFinished(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshActor.SkelMeshActorOnParticleSystemFinished" );
				byte *params = ( byte* )( malloc( 4 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool CreateForceField( class AnimNotify_ForceField* AnimNotifyData )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SkeletalMeshActor.CreateForceField" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class AnimNotify_ForceField** )( params + 0 ) = AnimNotifyData;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
