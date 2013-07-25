#pragma once
#include "TribesGame__TrPaperDoll.h"
#include "TribesGame__TrMainMenuMeshInfo.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrPaperDollMainMenu." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrPaperDollMainMenu." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrPaperDollMainMenu : public TrPaperDoll
	{
	public:
		ADD_VAR(::ByteProperty, m_OldContentDataType, 0xFFFFFFFF)
		ADD_STRUCT(::RotatorProperty, m_rZeroedRotation, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, m_fFullCharacterLightingContrastFactor, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bWasLastMeshSwapRequestMainMenuContentScene, 0x2)
		ADD_VAR(::BoolProperty, m_bEditorMode, 0x1)
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPaperDollMainMenu.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPaperDollMainMenu.Tick");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		
// WARNING: Unknown structure type 'ScriptStruct TribesGame.TrObject.PaperDollInfo'!
void* GetDevicePaperDollInfo(ScriptClass* WeaponClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPaperDollMainMenu.GetDevicePaperDollInfo");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPaperDollMainMenu.SetMainMesh");
			byte* params = (byte*)malloc(56);
			*(
// WARNING: Unknown structure type 'ScriptStruct TribesGame.TrObject.PaperDollInfo'!
void**)params = NewInfo;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnCharacterMeshContentDataClassLoaded(ScriptClass* Skin3PDataClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPaperDollMainMenu.OnCharacterMeshContentDataClassLoaded");
			byte* params = (byte*)malloc(4);
			*(ScriptClass**)params = Skin3PDataClass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnDeviceContentDataClassLoaded(ScriptClass* DeviceContentDataClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPaperDollMainMenu.OnDeviceContentDataClassLoaded");
			byte* params = (byte*)malloc(4);
			*(ScriptClass**)params = DeviceContentDataClass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TryUpdatingPaperDoll()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPaperDollMainMenu.TryUpdatingPaperDoll");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetWeaponOnlyMesh(ScriptClass* WeaponClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPaperDollMainMenu.SetWeaponOnlyMesh");
			byte* params = (byte*)malloc(4);
			*(ScriptClass**)params = WeaponClass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetFamilyInfo(ScriptClass* NewFamilyInfoClass, ScriptClass* DeviceClass, ScriptClass* skinClass, int TeamNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPaperDollMainMenu.SetFamilyInfo");
			byte* params = (byte*)malloc(16);
			*(ScriptClass**)params = NewFamilyInfoClass;
			*(ScriptClass**)(params + 4) = DeviceClass;
			*(ScriptClass**)(params + 8) = skinClass;
			*(int*)(params + 12) = TeamNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetMainMeshInfo(class TrMainMenuMeshInfo* NewMainMeshInfo, byte ContentDataType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPaperDollMainMenu.SetMainMeshInfo");
			byte* params = (byte*)malloc(5);
			*(class TrMainMenuMeshInfo**)params = NewMainMeshInfo;
			*(params + 4) = ContentDataType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CreateAndAttachParticleSystems(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* MeshComponent, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void* ParticleSystems)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPaperDollMainMenu.CreateAndAttachParticleSystems");
			byte* params = (byte*)malloc(16);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = MeshComponent;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4) = ParticleSystems;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DetachAndDestroyMeshAttachments(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* MeshComponent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPaperDollMainMenu.DetachAndDestroyMeshAttachments");
			byte* params = (byte*)malloc(4);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = MeshComponent;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSpinning(bool bShouldSpin, bool bReset)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPaperDollMainMenu.SetSpinning");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bShouldSpin;
			*(bool*)(params + 4) = bReset;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void EmptyChildrenMeshes()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPaperDollMainMenu.EmptyChildrenMeshes");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddChildrenMeshes(class TrMainMenuMeshInfo* Parent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPaperDollMainMenu.AddChildrenMeshes");
			byte* params = (byte*)malloc(4);
			*(class TrMainMenuMeshInfo**)params = Parent;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
