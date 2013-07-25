#pragma once
#include "Core__Object.h"
#include "Engine__PhysicsAsset.h"
#include "Engine__SkeletalMesh.h"
#include "Engine__MaterialInterface.h"
#include "Engine__MaterialInstance.h"
#include "Engine__ParticleSystem.h"
#include "Engine__StaticMesh.h"
#include "Engine__MaterialInstanceConstant.h"
#include "Engine__Texture.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTFamilyInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UTGame.UTFamilyInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTFamilyInfo." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTFamilyInfo : public Object
	{
	public:
		ADD_VAR(::StrProperty, Faction, 0xFFFFFFFF)
		ADD_OBJECT(SkeletalMesh, CharacterMesh)
		ADD_OBJECT(PhysicsAsset, PhysAsset)
		ADD_VAR(::BoolProperty, bIsFemale, 0x1)
		ADD_VAR(::NameProperty, LeftFootBone, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, RightFootBone, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, SoundGroupClass)
		ADD_VAR(::FloatProperty, DefaultMeshScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BaseTranslationOffset, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInstance, BloodSplatterDecalMaterial)
		ADD_VAR(::FloatProperty, DrivingDrawScale, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct UTGame.UTPawn.GibInfo' for the property named 'HeadGib'!
		ADD_OBJECT(ParticleSystem, HeadShotEffect)
		ADD_OBJECT(ParticleSystem, GibExplosionTemplate)
		ADD_VAR(::NameProperty, HeadShotGoreSocketName, 0xFFFFFFFF)
		ADD_OBJECT(StaticMesh, HeadShotNeckGoreAttachment)
		ADD_OBJECT(ScriptClass, BloodEmitterClass)
		ADD_VAR(::StrProperty, FamilyID, 0xFFFFFFFF)
		ADD_OBJECT(SkeletalMesh, DeathMeshSkelMesh)
		ADD_OBJECT(PhysicsAsset, DeathMeshPhysAsset)
		ADD_VAR(::IntProperty, DeathMeshNumMaterialsToSetResident, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor' for the property named 'NonTeamTintColor'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor' for the property named 'NonTeamEmissiveColor'!
		ADD_OBJECT(MaterialInstanceConstant, BioDeathMICParent)
		ADD_OBJECT(MaterialInstanceConstant, BaseMICParent)
		ADD_OBJECT(ScriptClass, VoiceClass)
		ADD_STRUCT(::VectorProperty, PortraitExtraOffset, 0xFFFFFFFF
		ADD_VAR(::StrProperty, NeckStumpName, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInterface, BlueArmMaterial)
		ADD_OBJECT(MaterialInterface, RedArmMaterial)
		ADD_VAR(::StrProperty, ArmSkinPackageName, 0xFFFFFFFF)
		ADD_OBJECT(SkeletalMesh, ArmMesh)
		ADD_VAR(::StrProperty, ArmMeshPackageName, 0xFFFFFFFF)
		ADD_OBJECT(Texture, DefaultHeadPortrait)
		class MaterialInterface* GetFirstPersonArmsMaterial(int TeamNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTFamilyInfo.GetFirstPersonArmsMaterial");
			byte* params = (byte*)malloc(8);
			*(int*)params = TeamNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class MaterialInterface**)(params + 4);
			free(params);
			return returnVal;
		}
		class SkeletalMesh* GetFirstPersonArms()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTFamilyInfo.GetFirstPersonArms");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class SkeletalMesh**)params;
			free(params);
			return returnVal;
		}
		ScriptClass* GetVoiceClass()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTFamilyInfo.GetVoiceClass");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptClass**)params;
			free(params);
			return returnVal;
		}
		class Texture* GetCharPortrait(int TeamNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTFamilyInfo.GetCharPortrait");
			byte* params = (byte*)malloc(8);
			*(int*)params = TeamNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Texture**)(params + 4);
			free(params);
			return returnVal;
		}
		int GetEmoteIndex(ScriptName EmoteTag)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTFamilyInfo.GetEmoteIndex");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = EmoteTag;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		void GetTeamMaterials(int TeamNum, class MaterialInterface*& TeamMaterialHead, class MaterialInterface*& TeamMaterialBody)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTFamilyInfo.GetTeamMaterials");
			byte* params = (byte*)malloc(12);
			*(int*)params = TeamNum;
			*(class MaterialInterface**)(params + 4) = TeamMaterialHead;
			*(class MaterialInterface**)(params + 8) = TeamMaterialBody;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			TeamMaterialHead = *(class MaterialInterface**)(params + 4);
			TeamMaterialBody = *(class MaterialInterface**)(params + 8);
			free(params);
		}
		int GetEmoteGroupCnt(ScriptName Category)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTFamilyInfo.GetEmoteGroupCnt");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = Category;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		void GetEmotes(ScriptName Category, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& Captions, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& EmoteTags)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTFamilyInfo.GetEmotes");
			byte* params = (byte*)malloc(32);
			*(ScriptName*)params = Category;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 8) = Captions;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 20) = EmoteTags;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Captions = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 8);
			EmoteTags = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 20);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
