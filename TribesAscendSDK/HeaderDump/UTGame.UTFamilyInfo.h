#pragma once
#include "Core.Object.h"
#include "Engine.SkeletalMesh.h"
#include "Engine.ParticleSystem.h"
#include "UTGame.UTPawn.h"
#include "Engine.AnimSet.h"
#include "UDKBase.UDKPawn.h"
#include "Engine.PhysicsAsset.h"
#include "Engine.MaterialInstance.h"
#include "Engine.StaticMesh.h"
#include "Engine.MaterialInstanceTimeVarying.h"
#include "Engine.Texture.h"
#include "Engine.MaterialInterface.h"
#include "Engine.MaterialInstanceConstant.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class UTFamilyInfo : public Object
	{
	public:
		ADD_STRUCT(ScriptString*, Faction, 88)
		ADD_STRUCT(ScriptArray<class AnimSet*>, AnimSets, 192)
		ADD_OBJECT(SkeletalMesh, CharacterMesh, 100)
		ADD_OBJECT(PhysicsAsset, PhysAsset, 188)
		ADD_BOOL(bIsFemale, 400, 0x1)
		ADD_STRUCT(ScriptName, LeftFootBone, 204)
		ADD_STRUCT(ScriptName, RightFootBone, 212)
		ADD_STRUCT(ScriptArray<ScriptName>, TakeHitPhysicsFixedBones, 220)
		ADD_OBJECT(ScriptClass, SoundGroupClass, 232)
		ADD_STRUCT(float, DefaultMeshScale, 404)
		ADD_STRUCT(float, BaseTranslationOffset, 408)
		ADD_OBJECT(MaterialInstance, BloodSplatterDecalMaterial, 248)
		ADD_STRUCT(ScriptArray<UDKPawn::EmoteInfo>, FamilyEmotes, 284)
		ADD_STRUCT(float, DrivingDrawScale, 396)
		ADD_STRUCT(UTPawn::GibInfo, HeadGib, 308)
		ADD_OBJECT(ParticleSystem, HeadShotEffect, 360)
		ADD_OBJECT(ParticleSystem, GibExplosionTemplate, 392)
		ADD_STRUCT(ScriptArray<UTPawn::GibInfo>, Gibs, 296)
		ADD_STRUCT(ScriptName, HeadShotGoreSocketName, 364)
		ADD_OBJECT(StaticMesh, HeadShotNeckGoreAttachment, 372)
		ADD_STRUCT(ScriptArray<UDKPawn::DistanceBasedParticleTemplate>, BloodEffects, 380)
		ADD_OBJECT(ScriptClass, BloodEmitterClass, 376)
		ADD_STRUCT(ScriptString*, FamilyID, 76)
		ADD_OBJECT(SkeletalMesh, DeathMeshSkelMesh, 324)
		ADD_OBJECT(PhysicsAsset, DeathMeshPhysAsset, 328)
		ADD_STRUCT(ScriptArray<class MaterialInstanceTimeVarying*>, SkeletonBurnOutMaterials, 348)
		ADD_STRUCT(int, DeathMeshNumMaterialsToSetResident, 332)
		ADD_STRUCT(ScriptArray<ScriptName>, DeathMeshBreakableJoints, 336)
		ADD_STRUCT(ScriptArray<class Texture*>, DefaultTeamHeadPortrait, 64)
		ADD_STRUCT(ScriptArray<class MaterialInterface*>, CharacterTeamBodyMaterials, 104)
		ADD_STRUCT(ScriptArray<class MaterialInterface*>, CharacterTeamHeadMaterials, 116)
		ADD_STRUCT(Object::LinearColor, NonTeamTintColor, 268)
		ADD_STRUCT(Object::LinearColor, NonTeamEmissiveColor, 252)
		ADD_OBJECT(MaterialInstanceConstant, BioDeathMICParent, 244)
		ADD_OBJECT(MaterialInstanceConstant, BaseMICParent, 240)
		ADD_OBJECT(ScriptClass, VoiceClass, 236)
		ADD_STRUCT(Object::Vector, PortraitExtraOffset, 176)
		ADD_STRUCT(ScriptString*, NeckStumpName, 164)
		ADD_OBJECT(MaterialInterface, BlueArmMaterial, 160)
		ADD_OBJECT(MaterialInterface, RedArmMaterial, 156)
		ADD_STRUCT(ScriptString*, ArmSkinPackageName, 144)
		ADD_OBJECT(SkeletalMesh, ArmMesh, 140)
		ADD_STRUCT(ScriptString*, ArmMeshPackageName, 128)
		ADD_OBJECT(Texture, DefaultHeadPortrait, 60)
		class MaterialInterface* GetFirstPersonArmsMaterial(int TeamNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTFamilyInfo.GetFirstPersonArmsMaterial");
			byte params[8] = { NULL };
			*(int*)&params[0] = TeamNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class MaterialInterface**)&params[4];
		}
		class SkeletalMesh* GetFirstPersonArms()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTFamilyInfo.GetFirstPersonArms");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class SkeletalMesh**)&params[0];
		}
		ScriptClass* GetVoiceClass()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTFamilyInfo.GetVoiceClass");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptClass**)&params[0];
		}
		class Texture* GetCharPortrait(int TeamNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTFamilyInfo.GetCharPortrait");
			byte params[8] = { NULL };
			*(int*)&params[0] = TeamNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Texture**)&params[4];
		}
		int GetEmoteIndex(ScriptName EmoteTag)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTFamilyInfo.GetEmoteIndex");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = EmoteTag;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		void GetTeamMaterials(int TeamNum, class MaterialInterface*& TeamMaterialHead, class MaterialInterface*& TeamMaterialBody)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTFamilyInfo.GetTeamMaterials");
			byte params[12] = { NULL };
			*(int*)&params[0] = TeamNum;
			*(class MaterialInterface**)&params[4] = TeamMaterialHead;
			*(class MaterialInterface**)&params[8] = TeamMaterialBody;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			TeamMaterialHead = *(class MaterialInterface**)&params[4];
			TeamMaterialBody = *(class MaterialInterface**)&params[8];
		}
		int GetEmoteGroupCnt(ScriptName Category)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTFamilyInfo.GetEmoteGroupCnt");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = Category;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		void GetEmotes(ScriptName Category, ScriptArray<ScriptString*>& Captions, ScriptArray<ScriptName>& EmoteTags)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTFamilyInfo.GetEmotes");
			byte params[32] = { NULL };
			*(ScriptName*)&params[0] = Category;
			*(ScriptArray<ScriptString*>*)&params[8] = Captions;
			*(ScriptArray<ScriptName>*)&params[20] = EmoteTags;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Captions = *(ScriptArray<ScriptString*>*)&params[8];
			EmoteTags = *(ScriptArray<ScriptName>*)&params[20];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
