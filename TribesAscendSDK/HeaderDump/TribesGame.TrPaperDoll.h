#pragma once
#include "Engine.SkeletalMeshActorMAT.h"
#include "Engine.AnimNodePlayCustomAnim.h"
#include "TribesGame.TrPlayerController.h"
#include "TribesGame.TrObject.h"
#include "Core.Object.h"
#include "Engine.AnimNodeSequence.h"
#include "Engine.MaterialInstanceConstant.h"
#include "Engine.SkeletalMesh.h"
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
	class TrPaperDoll : public SkeletalMeshActorMAT
	{
	public:
		ADD_OBJECT(ScriptClass, m_LastFamilyClassRequest, 776)
		ADD_OBJECT(ScriptClass, m_LastDeviceOnlyRequest, 772)
		ADD_OBJECT(TrPlayerController, m_TrPlayerController, 760)
		ADD_OBJECT(ScriptClass, m_LastDeviceClassRequest, 768)
		ADD_STRUCT(ScriptArray<
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void*>, m_Lights, 548)
		ADD_OBJECT(ScriptClass, m_DeviceContentDataClass, 904)
		ADD_STRUCT(float, m_fLastStreamingCheckTimestamp, 900)
		ADD_STRUCT(float, m_fCheckStreamingFrequency, 896)
		ADD_STRUCT(TrObject::PaperDollInfo, m_PendingPaperDollInfoSkin, 840)
		ADD_STRUCT(TrObject::PaperDollInfo, m_PendingPaperDollInfoDevice, 784)
		ADD_STRUCT(int, m_LastSkinIdRequest, 780)
		ADD_BOOL(m_bWasLastMeshSwapRequestNonWeapon, 764, 0x1)
		ADD_STRUCT(TrObject::PaperDollInfo, m_CurrentPaperDollInfo, 704)
		ADD_STRUCT(float, m_fMaxCustomAnimTime, 700)
		ADD_STRUCT(float, m_fMinCustomAnimTime, 696)
		ADD_OBJECT(AnimNodePlayCustomAnim, m_SidekickCustomAnimNode, 692)
		ADD_OBJECT(AnimNodePlayCustomAnim, m_CharacterCustomAnimNode, 688)
		ADD_STRUCT(Vector, m_vOffsetHeavy, 676)
		ADD_STRUCT(Vector, m_vOffsetMedium, 664)
		ADD_STRUCT(Vector, m_vOffsetLight, 652)
		ADD_STRUCT(Vector, m_vBackdropOffset, 640)
		ADD_STRUCT(float, m_fBackdropScale16x10, 636)
		ADD_STRUCT(float, m_fBackdropScale16x9, 632)
		ADD_STRUCT(float, m_fBackdropScale4x3, 628)
		ADD_OBJECT(MaterialInstanceConstant, m_DiamondSwordBackdropMaterial, 624)
		ADD_OBJECT(MaterialInstanceConstant, m_BloodEagleBackdropMaterial, 620)
		ADD_OBJECT(ScriptClass, m_TrDeviceClass, 600)
		ADD_OBJECT(ScriptClass, m_FamilyInfoClass, 596)
		ADD_STRUCT(Vector, m_vViewOffset16x10, 584)
		ADD_STRUCT(Vector, m_vViewOffset16x9, 572)
		ADD_STRUCT(Vector, m_vViewOffset4x3, 560)
		bool IsFullyStreamed(TrObject::PaperDollInfo PaperDoll)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(100424);
			byte params[60] = { NULL };
			*(TrObject::PaperDollInfo*)params = PaperDoll;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[56];
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(100427);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostInitAnimTree(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelComp)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(100429);
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = SkelComp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class SkeletalMesh* GetCharacterSkeletalMesh(ScriptClass* FamilyInfoClass, byte TeamNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(100432);
			byte params[9] = { NULL };
			*(ScriptClass**)params = FamilyInfoClass;
			params[4] = TeamNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class SkeletalMesh**)&params[8];
		}
		void OnCharacterMeshContentDataClassLoaded(ScriptClass* Skin3PDataClass)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(100438);
			byte params[4] = { NULL };
			*(ScriptClass**)params = Skin3PDataClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnSkeletalMeshFinishedStreaming(class SkeletalMesh* NewSkelMesh)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(100442);
			byte params[4] = { NULL };
			*(class SkeletalMesh**)params = NewSkelMesh;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TryUpdatingPaperDoll()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(100444);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetFamilyInfo(ScriptClass* NewFamilyInfoClass, ScriptClass* DeviceClass, ScriptClass* skinClass, int TeamNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(100447);
			byte params[16] = { NULL };
			*(ScriptClass**)params = NewFamilyInfoClass;
			*(ScriptClass**)&params[4] = DeviceClass;
			*(ScriptClass**)&params[8] = skinClass;
			*(int*)&params[12] = TeamNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayCustomAnimation()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(100453);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StopCustomAnimation(float FadeOutTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(100454);
			byte params[4] = { NULL };
			*(float*)params = FadeOutTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ResetCustomAnimTimer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(100456);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnAnimEnd(class AnimNodeSequence* SeqNode, float PlayedTime, float ExcessTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(100457);
			byte params[12] = { NULL };
			*(class AnimNodeSequence**)params = SeqNode;
			*(float*)&params[4] = PlayedTime;
			*(float*)&params[8] = ExcessTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnDeviceContentDataClassLoaded(ScriptClass* DeviceContentDataClass)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(100461);
			byte params[4] = { NULL };
			*(ScriptClass**)params = DeviceContentDataClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayLoadingGraphic()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(100467);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StopLoadingGraphic()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(100468);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnWeaponFinishedStreaming(TrObject::PaperDollInfo NewPaperDollInfo)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(100469);
			byte params[56] = { NULL };
			*(TrObject::PaperDollInfo*)params = NewPaperDollInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetWeaponOnlyMesh(ScriptClass* WeaponClass)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(100471);
			byte params[4] = { NULL };
			*(ScriptClass**)params = WeaponClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		TrObject::PaperDollInfo GetDevicePaperDollInfo(ScriptClass* WeaponClass)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(100473);
			byte params[60] = { NULL };
			*(ScriptClass**)params = WeaponClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(TrObject::PaperDollInfo*)&params[4];
		}
		void SetMainMesh(TrObject::PaperDollInfo NewInfo)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(100476);
			byte params[56] = { NULL };
			*(TrObject::PaperDollInfo*)params = NewInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(100481);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
