#pragma once
#include "Engine.PrimitiveComponent.h"
#include "Engine.MaterialInterface.h"
#include "Engine.MaterialInstanceConstant.h"
#include "Engine.MaterialInstanceTimeVarying.h"
namespace UnrealScript
{
	class MeshComponent : public PrimitiveComponent
	{
	public:
		class MaterialInterface* GetMaterial(int ElementIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.MeshComponent.GetMaterial");
			byte* params = (byte*)malloc(8);
			*(int*)params = ElementIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class MaterialInterface**)(params + 4);
			free(params);
			return returnVal;
		}
		void SetMaterial(int ElementIndex, class MaterialInterface* Material)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.MeshComponent.SetMaterial");
			byte* params = (byte*)malloc(8);
			*(int*)params = ElementIndex;
			*(class MaterialInterface**)(params + 4) = Material;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		int GetNumElements()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.MeshComponent.GetNumElements");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		void PrestreamTextures(float Seconds, bool bPrioritizeCharacterTextures, int CinematicTextureGroups)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.MeshComponent.PrestreamTextures");
			byte* params = (byte*)malloc(12);
			*(float*)params = Seconds;
			*(bool*)(params + 4) = bPrioritizeCharacterTextures;
			*(int*)(params + 8) = CinematicTextureGroups;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class MaterialInstanceConstant* CreateAndSetMaterialInstanceConstant(int ElementIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.MeshComponent.CreateAndSetMaterialInstanceConstant");
			byte* params = (byte*)malloc(8);
			*(int*)params = ElementIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class MaterialInstanceConstant**)(params + 4);
			free(params);
			return returnVal;
		}
		class MaterialInstanceTimeVarying* CreateAndSetMaterialInstanceTimeVarying(int ElementIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.MeshComponent.CreateAndSetMaterialInstanceTimeVarying");
			byte* params = (byte*)malloc(8);
			*(int*)params = ElementIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class MaterialInstanceTimeVarying**)(params + 4);
			free(params);
			return returnVal;
		}
	};
}
