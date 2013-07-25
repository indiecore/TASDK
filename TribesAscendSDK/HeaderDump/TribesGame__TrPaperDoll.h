#pragma once
#include "Engine__SkeletalMeshActorMAT.h"
#include "Engine__AnimNodeSequence.h"
#include "Engine__MaterialInstanceConstant.h"
#include "TribesGame__TrPlayerController.h"
#include "Engine__AnimNodePlayCustomAnim.h"
#include "Engine__SkeletalMesh.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrPaperDoll." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrPaperDoll." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrPaperDoll." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrPaperDoll : public SkeletalMeshActorMAT
	{
	public:
		ADD_OBJECT(ScriptClass, m_LastFamilyClassRequest)
		ADD_OBJECT(ScriptClass, m_LastDeviceOnlyRequest)
		ADD_OBJECT(TrPlayerController, m_TrPlayerController)
		ADD_OBJECT(ScriptClass, m_LastDeviceClassRequest)
		ADD_OBJECT(ScriptClass, m_DeviceContentDataClass)
		ADD_VAR(::FloatProperty, m_fLastStreamingCheckTimestamp, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fCheckStreamingFrequency, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct TribesGame.TrObject.PaperDollInfo' for the property named 'm_PendingPaperDollInfoSkin'!
		// WARNING: Unknown structure type 'ScriptStruct TribesGame.TrObject.PaperDollInfo' for the property named 'm_PendingPaperDollInfoDevice'!
		ADD_VAR(::IntProperty, m_LastSkinIdRequest, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bWasLastMeshSwapRequestNonWeapon, 0x1)
		// WARNING: Unknown structure type 'ScriptStruct TribesGame.TrObject.PaperDollInfo' for the property named 'm_CurrentPaperDollInfo'!
		ADD_VAR(::FloatProperty, m_fMaxCustomAnimTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fMinCustomAnimTime, 0xFFFFFFFF)
		ADD_OBJECT(AnimNodePlayCustomAnim, m_SidekickCustomAnimNode)
		ADD_OBJECT(AnimNodePlayCustomAnim, m_CharacterCustomAnimNode)
		ADD_STRUCT(::VectorProperty, m_vOffsetHeavy, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, m_vOffsetMedium, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, m_vOffsetLight, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, m_vBackdropOffset, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, m_fBackdropScale16x10, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fBackdropScale16x9, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fBackdropScale4x3, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInstanceConstant, m_DiamondSwordBackdropMaterial)
		ADD_OBJECT(MaterialInstanceConstant, m_BloodEagleBackdropMaterial)
		ADD_OBJECT(ScriptClass, m_TrDeviceClass)
		ADD_OBJECT(ScriptClass, m_FamilyInfoClass)
		ADD_STRUCT(::VectorProperty, m_vViewOffset16x10, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, m_vViewOffset16x9, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, m_vViewOffset4x3, 0xFFFFFFFF
		bool IsFullyStreamed(
// WARNING: Unknown structure type 'ScriptStruct TribesGame.TrObject.PaperDollInfo'!
void* PaperDoll)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPaperDoll.IsFullyStreamed");
			byte* params = (byte*)malloc(60);
			*(
// WARNING: Unknown structure type 'ScriptStruct TribesGame.TrObject.PaperDollInfo'!
void**)params = PaperDoll;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 56);
			free(params);
			return returnVal;
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPaperDoll.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostInitAnimTree(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelComp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPaperDoll.PostInitAnimTree");
			byte* params = (byte*)malloc(4);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = SkelComp;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class SkeletalMesh* GetCharacterSkeletalMesh(ScriptClass* FamilyInfoClass, byte TeamNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPaperDoll.GetCharacterSkeletalMesh");
			byte* params = (byte*)malloc(9);
			*(ScriptClass**)params = FamilyInfoClass;
			*(params + 4) = TeamNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class SkeletalMesh**)(params + 8);
			free(params);
			return returnVal;
		}
		void OnCharacterMeshContentDataClassLoaded(ScriptClass* Skin3PDataClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPaperDoll.OnCharacterMeshContentDataClassLoaded");
			byte* params = (byte*)malloc(4);
			*(ScriptClass**)params = Skin3PDataClass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnSkeletalMeshFinishedStreaming(class SkeletalMesh* NewSkelMesh)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPaperDoll.OnSkeletalMeshFinishedStreaming");
			byte* params = (byte*)malloc(4);
			*(class SkeletalMesh**)params = NewSkelMesh;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TryUpdatingPaperDoll()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPaperDoll.TryUpdatingPaperDoll");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetFamilyInfo(ScriptClass* NewFamilyInfoClass, ScriptClass* DeviceClass, ScriptClass* skinClass, int TeamNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPaperDoll.SetFamilyInfo");
			byte* params = (byte*)malloc(16);
			*(ScriptClass**)params = NewFamilyInfoClass;
			*(ScriptClass**)(params + 4) = DeviceClass;
			*(ScriptClass**)(params + 8) = skinClass;
			*(int*)(params + 12) = TeamNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayCustomAnimation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPaperDoll.PlayCustomAnimation");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StopCustomAnimation(float FadeOutTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPaperDoll.StopCustomAnimation");
			byte* params = (byte*)malloc(4);
			*(float*)params = FadeOutTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ResetCustomAnimTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPaperDoll.ResetCustomAnimTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnAnimEnd(class AnimNodeSequence* SeqNode, float PlayedTime, float ExcessTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPaperDoll.OnAnimEnd");
			byte* params = (byte*)malloc(12);
			*(class AnimNodeSequence**)params = SeqNode;
			*(float*)(params + 4) = PlayedTime;
			*(float*)(params + 8) = ExcessTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnDeviceContentDataClassLoaded(ScriptClass* DeviceContentDataClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPaperDoll.OnDeviceContentDataClassLoaded");
			byte* params = (byte*)malloc(4);
			*(ScriptClass**)params = DeviceContentDataClass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayLoadingGraphic()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPaperDoll.PlayLoadingGraphic");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StopLoadingGraphic()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPaperDoll.StopLoadingGraphic");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnWeaponFinishedStreaming(
// WARNING: Unknown structure type 'ScriptStruct TribesGame.TrObject.PaperDollInfo'!
void* NewPaperDollInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPaperDoll.OnWeaponFinishedStreaming");
			byte* params = (byte*)malloc(56);
			*(
// WARNING: Unknown structure type 'ScriptStruct TribesGame.TrObject.PaperDollInfo'!
void**)params = NewPaperDollInfo;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetWeaponOnlyMesh(ScriptClass* WeaponClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPaperDoll.SetWeaponOnlyMesh");
			byte* params = (byte*)malloc(4);
			*(ScriptClass**)params = WeaponClass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		
// WARNING: Unknown structure type 'ScriptStruct TribesGame.TrObject.PaperDollInfo'!
void* GetDevicePaperDollInfo(ScriptClass* WeaponClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPaperDoll.GetDevicePaperDollInfo");
			byte* params = (byte*)malloc(60);
			*(ScriptClass**)params = WeaponClass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// WARNING: Unknown structure type 'ScriptStruct TribesGame.TrObject.PaperDollInfo'!
void**)(params + 4);
			free(params);
			return returnVal;
		}
		void SetMainMesh(
// WARNING: Unknown structure type 'ScriptStruct TribesGame.TrObject.PaperDollInfo'!
void* NewInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPaperDoll.SetMainMesh");
			byte* params = (byte*)malloc(56);
			*(
// WARNING: Unknown structure type 'ScriptStruct TribesGame.TrObject.PaperDollInfo'!
void**)params = NewInfo;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Destroyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPaperDoll.Destroyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
