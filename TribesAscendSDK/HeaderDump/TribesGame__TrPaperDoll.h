#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrPaperDoll." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrPaperDoll." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrPaperDoll." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrPaperDoll : public SkeletalMeshActorMAT
	{
	public:
			ADD_OBJECT( ScriptClass, m_LastFamilyClassRequest )
			ADD_OBJECT( ScriptClass, m_LastDeviceOnlyRequest )
			ADD_OBJECT( TrPlayerController, m_TrPlayerController )
			ADD_OBJECT( ScriptClass, m_LastDeviceClassRequest )
			ADD_OBJECT( ScriptClass, m_DeviceContentDataClass )
			ADD_VAR( ::FloatProperty, m_fLastStreamingCheckTimestamp, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fCheckStreamingFrequency, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_LastSkinIdRequest, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, m_bWasLastMeshSwapRequestNonWeapon, 0x1 )
			ADD_VAR( ::FloatProperty, m_fMaxCustomAnimTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fMinCustomAnimTime, 0xFFFFFFFF )
			ADD_OBJECT( AnimNodePlayCustomAnim, m_SidekickCustomAnimNode )
			ADD_OBJECT( AnimNodePlayCustomAnim, m_CharacterCustomAnimNode )
			ADD_STRUCT( ::VectorProperty, m_vOffsetHeavy, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, m_vOffsetMedium, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, m_vOffsetLight, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, m_vBackdropOffset, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fBackdropScale16x10, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fBackdropScale16x9, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fBackdropScale4x3, 0xFFFFFFFF )
			ADD_OBJECT( MaterialInstanceConstant, m_DiamondSwordBackdropMaterial )
			ADD_OBJECT( MaterialInstanceConstant, m_BloodEagleBackdropMaterial )
			ADD_OBJECT( ScriptClass, m_TrDeviceClass )
			ADD_OBJECT( ScriptClass, m_FamilyInfoClass )
			ADD_STRUCT( ::VectorProperty, m_vViewOffset16x10, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, m_vViewOffset16x9, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, m_vViewOffset4x3, 0xFFFFFFFF )
			bool IsFullyStreamed( void* PaperDoll )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPaperDoll.IsFullyStreamed" );
				byte *params = ( byte* )( malloc( 56 ) );
				*( void** )( params + 0 ) = PaperDoll;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPaperDoll.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostInitAnimTree(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPaperDoll.PostInitAnimTree" );
				byte *params = ( byte* )( malloc( 4 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class SkeletalMesh* GetCharacterSkeletalMesh( ScriptClass* FamilyInfoClass, byte TeamNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPaperDoll.GetCharacterSkeletalMesh" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( ScriptClass** )( params + 0 ) = FamilyInfoClass;
				*( byte* )( params + 4 ) = TeamNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class SkeletalMesh** )( params + function->return_val_offset() );
			}

			void OnCharacterMeshContentDataClassLoaded( ScriptClass* Skin3PDataClass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPaperDoll.OnCharacterMeshContentDataClassLoaded" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )( params + 0 ) = Skin3PDataClass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnSkeletalMeshFinishedStreaming( class SkeletalMesh* NewSkelMesh )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPaperDoll.OnSkeletalMeshFinishedStreaming" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SkeletalMesh** )( params + 0 ) = NewSkelMesh;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TryUpdatingPaperDoll(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPaperDoll.TryUpdatingPaperDoll" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetFamilyInfo( ScriptClass* NewFamilyInfoClass, ScriptClass* DeviceClass, ScriptClass* skinClass, int TeamNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPaperDoll.SetFamilyInfo" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptClass** )( params + 0 ) = NewFamilyInfoClass;
				*( ScriptClass** )( params + 4 ) = DeviceClass;
				*( ScriptClass** )( params + 8 ) = skinClass;
				*( int* )( params + 12 ) = TeamNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayCustomAnimation(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPaperDoll.PlayCustomAnimation" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StopCustomAnimation( float FadeOutTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPaperDoll.StopCustomAnimation" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = FadeOutTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ResetCustomAnimTimer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPaperDoll.ResetCustomAnimTimer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnAnimEnd( class AnimNodeSequence* SeqNode, float PlayedTime, float ExcessTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPaperDoll.OnAnimEnd" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class AnimNodeSequence** )( params + 0 ) = SeqNode;
				*( float* )( params + 4 ) = PlayedTime;
				*( float* )( params + 8 ) = ExcessTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnDeviceContentDataClassLoaded( ScriptClass* DeviceContentDataClass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPaperDoll.OnDeviceContentDataClassLoaded" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )( params + 0 ) = DeviceContentDataClass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayLoadingGraphic(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPaperDoll.PlayLoadingGraphic" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StopLoadingGraphic(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPaperDoll.StopLoadingGraphic" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnWeaponFinishedStreaming( void* NewPaperDollInfo )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPaperDoll.OnWeaponFinishedStreaming" );
				byte *params = ( byte* )( malloc( 56 ) );
				*( void** )( params + 0 ) = NewPaperDollInfo;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetWeaponOnlyMesh( ScriptClass* WeaponClass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPaperDoll.SetWeaponOnlyMesh" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )( params + 0 ) = WeaponClass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void* GetDevicePaperDollInfo( ScriptClass* WeaponClass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPaperDoll.GetDevicePaperDollInfo" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )( params + 0 ) = WeaponClass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			void SetMainMesh( void* NewInfo )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPaperDoll.SetMainMesh" );
				byte *params = ( byte* )( malloc( 56 ) );
				*( void** )( params + 0 ) = NewInfo;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Destroyed(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPaperDoll.Destroyed" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
