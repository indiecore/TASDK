#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.UTFamilyInfo." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.UTFamilyInfo." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.UTFamilyInfo." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTFamilyInfo : public Object
	{
	public:
			ADD_VAR( ::StrProperty, Faction, 0xFFFFFFFF )
			class MaterialInterface* GetFirstPersonArmsMaterial( int TeamNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTFamilyInfo.GetFirstPersonArmsMaterial" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = TeamNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class MaterialInterface** )( params + function->return_val_offset() );
			}

			ADD_OBJECT( SkeletalMesh, CharacterMesh )
			class SkeletalMesh* GetFirstPersonArms(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTFamilyInfo.GetFirstPersonArms" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class SkeletalMesh** )( params + function->return_val_offset() );
			}

			ADD_OBJECT( PhysicsAsset, PhysAsset )
			ADD_VAR( ::BoolProperty, bIsFemale, 0x1 )
			ScriptClass* GetVoiceClass(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTFamilyInfo.GetVoiceClass" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptClass** )( params + function->return_val_offset() );
			}

			class Texture* GetCharPortrait( int TeamNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTFamilyInfo.GetCharPortrait" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = TeamNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Texture** )( params + function->return_val_offset() );
			}

			ADD_VAR( ::NameProperty, LeftFootBone, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, RightFootBone, 0xFFFFFFFF )
			ADD_OBJECT( ScriptClass, SoundGroupClass )
			ADD_VAR( ::FloatProperty, DefaultMeshScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BaseTranslationOffset, 0xFFFFFFFF )
			ADD_OBJECT( MaterialInstance, BloodSplatterDecalMaterial )
			int GetEmoteIndex( ScriptName EmoteTag )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTFamilyInfo.GetEmoteIndex" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = EmoteTag;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::FloatProperty, DrivingDrawScale, 0xFFFFFFFF )
			ADD_OBJECT( ParticleSystem, HeadShotEffect )
			ADD_OBJECT( ParticleSystem, GibExplosionTemplate )
			ADD_VAR( ::NameProperty, HeadShotGoreSocketName, 0xFFFFFFFF )
			ADD_OBJECT( StaticMesh, HeadShotNeckGoreAttachment )
			ADD_OBJECT( ScriptClass, BloodEmitterClass )
			ADD_VAR( ::StrProperty, FamilyID, 0xFFFFFFFF )
			ADD_OBJECT( SkeletalMesh, DeathMeshSkelMesh )
			ADD_OBJECT( PhysicsAsset, DeathMeshPhysAsset )
			ADD_VAR( ::IntProperty, DeathMeshNumMaterialsToSetResident, 0xFFFFFFFF )
			ADD_OBJECT( MaterialInstanceConstant, BioDeathMICParent )
			ADD_OBJECT( MaterialInstanceConstant, BaseMICParent )
			ADD_OBJECT( ScriptClass, VoiceClass )
			ADD_STRUCT( ::VectorProperty, PortraitExtraOffset, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, NeckStumpName, 0xFFFFFFFF )
			ADD_OBJECT( MaterialInterface, BlueArmMaterial )
			ADD_OBJECT( MaterialInterface, RedArmMaterial )
			ADD_VAR( ::StrProperty, ArmSkinPackageName, 0xFFFFFFFF )
			ADD_OBJECT( SkeletalMesh, ArmMesh )
			ADD_VAR( ::StrProperty, ArmMeshPackageName, 0xFFFFFFFF )
			ADD_OBJECT( Texture, DefaultHeadPortrait )
			void GetTeamMaterials( int TeamNum, class MaterialInterface* &TeamMaterialHead, class MaterialInterface* &TeamMaterialBody )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTFamilyInfo.GetTeamMaterials" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( int* )params = TeamNum;
				*( class MaterialInterface** )( params + 4 ) = TeamMaterialHead;
				*( class MaterialInterface** )( params + 8 ) = TeamMaterialBody;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				TeamMaterialHead = *( class MaterialInterface** )( params + 4 );
				TeamMaterialBody = *( class MaterialInterface** )( params + 8 );
			}

			int GetEmoteGroupCnt( ScriptName Category )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTFamilyInfo.GetEmoteGroupCnt" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = Category;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void GetEmotes( ScriptName Category )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTFamilyInfo.GetEmotes" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( ScriptName* )params = Category;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
