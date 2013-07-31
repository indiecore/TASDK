#pragma once
#include "TribesGame.TrMainMenuMeshInfo.h"
#include "TribesGame.TrPaperDoll.h"
#include "TribesGame.TrObject.h"
#include "Core.Object.h"
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
namespace UnrealScript
{
	class TrPaperDollMainMenu : public TrPaperDoll
	{
	public:
		ADD_STRUCT(ScriptArray<
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void*>, m_ChildSkeletalMeshComponents, 916)
		ADD_STRUCT(TrObject::EContentDataType, m_OldContentDataType, 940)
		ADD_STRUCT(Rotator, m_rZeroedRotation, 928)
		ADD_STRUCT(float, m_fFullCharacterLightingContrastFactor, 912)
		ADD_BOOL(m_bWasLastMeshSwapRequestMainMenuContentScene, 908, 0x2)
		ADD_BOOL(m_bEditorMode, 908, 0x1)
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(100497);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(100498);
			byte params[4] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		TrObject::PaperDollInfo GetDevicePaperDollInfo(ScriptClass* WeaponClass)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(100500);
			byte params[60] = { NULL };
			*(ScriptClass**)params = WeaponClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(TrObject::PaperDollInfo*)&params[4];
		}
		void SetMainMesh(TrObject::PaperDollInfo NewInfo)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(100503);
			byte params[56] = { NULL };
			*(TrObject::PaperDollInfo*)params = NewInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnCharacterMeshContentDataClassLoaded(ScriptClass* Skin3PDataClass)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(100505);
			byte params[4] = { NULL };
			*(ScriptClass**)params = Skin3PDataClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnDeviceContentDataClassLoaded(ScriptClass* DeviceContentDataClass)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(100507);
			byte params[4] = { NULL };
			*(ScriptClass**)params = DeviceContentDataClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TryUpdatingPaperDoll()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(100509);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetWeaponOnlyMesh(ScriptClass* WeaponClass)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(100510);
			byte params[4] = { NULL };
			*(ScriptClass**)params = WeaponClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetFamilyInfo(ScriptClass* NewFamilyInfoClass, ScriptClass* DeviceClass, ScriptClass* skinClass, int TeamNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(100512);
			byte params[16] = { NULL };
			*(ScriptClass**)params = NewFamilyInfoClass;
			*(ScriptClass**)&params[4] = DeviceClass;
			*(ScriptClass**)&params[8] = skinClass;
			*(int*)&params[12] = TeamNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetMainMeshInfo(class TrMainMenuMeshInfo* NewMainMeshInfo, TrObject::EContentDataType ContentDataType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(100517);
			byte params[5] = { NULL };
			*(class TrMainMenuMeshInfo**)params = NewMainMeshInfo;
			*(TrObject::EContentDataType*)&params[4] = ContentDataType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CreateAndAttachParticleSystems(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* MeshComponent, ScriptArray<TrMainMenuMeshInfo::ParticleSystemInfo> ParticleSystems)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(100520);
			byte params[16] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = MeshComponent;
			*(ScriptArray<TrMainMenuMeshInfo::ParticleSystemInfo>*)&params[4] = ParticleSystems;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DetachAndDestroyMeshAttachments(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* MeshComponent)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(100526);
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = MeshComponent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSpinning(bool bShouldSpin, bool bReset)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(100529);
			byte params[8] = { NULL };
			*(bool*)params = bShouldSpin;
			*(bool*)&params[4] = bReset;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EmptyChildrenMeshes()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(100532);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddChildrenMeshes(class TrMainMenuMeshInfo* Parent)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(100534);
			byte params[4] = { NULL };
			*(class TrMainMenuMeshInfo**)params = Parent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
