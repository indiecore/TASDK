#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " UTGame.UTFamilyInfo." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty UTGame.UTFamilyInfo." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty UTGame.UTFamilyInfo." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTFamilyInfo : public Object
	{
	public:
			ADD_VAR( ::StrProperty, Faction, 0xFFFFFFFF )
			ADD_OBJECT( SkeletalMesh, CharacterMesh )
			ADD_OBJECT( PhysicsAsset, PhysAsset )
			ADD_VAR( ::BoolProperty, bIsFemale, 0x1 )
			ADD_VAR( ::NameProperty, LeftFootBone, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, RightFootBone, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DefaultMeshScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BaseTranslationOffset, 0xFFFFFFFF )
			ADD_OBJECT( MaterialInstance, BloodSplatterDecalMaterial )
			ADD_VAR( ::FloatProperty, DrivingDrawScale, 0xFFFFFFFF )
			ADD_OBJECT( ParticleSystem, HeadShotEffect )
			ADD_OBJECT( ParticleSystem, GibExplosionTemplate )
			ADD_VAR( ::NameProperty, HeadShotGoreSocketName, 0xFFFFFFFF )
			ADD_OBJECT( StaticMesh, HeadShotNeckGoreAttachment )
			ADD_VAR( ::StrProperty, FamilyID, 0xFFFFFFFF )
			ADD_OBJECT( SkeletalMesh, DeathMeshSkelMesh )
			ADD_OBJECT( PhysicsAsset, DeathMeshPhysAsset )
			ADD_VAR( ::IntProperty, DeathMeshNumMaterialsToSetResident, 0xFFFFFFFF )
			ADD_OBJECT( MaterialInstanceConstant, BioDeathMICParent )
			ADD_OBJECT( MaterialInstanceConstant, BaseMICParent )
			ADD_STRUCT( ::VectorProperty, PortraitExtraOffset, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, NeckStumpName, 0xFFFFFFFF )
			ADD_OBJECT( MaterialInterface, BlueArmMaterial )
			ADD_OBJECT( MaterialInterface, RedArmMaterial )
			ADD_VAR( ::StrProperty, ArmSkinPackageName, 0xFFFFFFFF )
			ADD_OBJECT( SkeletalMesh, ArmMesh )
			ADD_VAR( ::StrProperty, ArmMeshPackageName, 0xFFFFFFFF )
			ADD_OBJECT( Texture, DefaultHeadPortrait )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
