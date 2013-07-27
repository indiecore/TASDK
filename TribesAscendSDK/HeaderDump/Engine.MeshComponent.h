#pragma once
#include "Engine.PrimitiveComponent.h"
#include "Engine.MaterialInterface.h"
#include "Engine.MaterialInstanceConstant.h"
#include "Engine.MaterialInstanceTimeVarying.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class MeshComponent : public PrimitiveComponent
	{
	public:
		ADD_STRUCT(ScriptArray<class MaterialInterface*>, Materials, 488)
		class MaterialInterface* GetMaterial(int ElementIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.MeshComponent.GetMaterial");
			byte params[8] = { NULL };
			*(int*)&params[0] = ElementIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class MaterialInterface**)&params[4];
		}
		void SetMaterial(int ElementIndex, class MaterialInterface* Material)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.MeshComponent.SetMaterial");
			byte params[8] = { NULL };
			*(int*)&params[0] = ElementIndex;
			*(class MaterialInterface**)&params[4] = Material;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int GetNumElements()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.MeshComponent.GetNumElements");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		void PrestreamTextures(float Seconds, bool bPrioritizeCharacterTextures, int CinematicTextureGroups)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.MeshComponent.PrestreamTextures");
			byte params[12] = { NULL };
			*(float*)&params[0] = Seconds;
			*(bool*)&params[4] = bPrioritizeCharacterTextures;
			*(int*)&params[8] = CinematicTextureGroups;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class MaterialInstanceConstant* CreateAndSetMaterialInstanceConstant(int ElementIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.MeshComponent.CreateAndSetMaterialInstanceConstant");
			byte params[8] = { NULL };
			*(int*)&params[0] = ElementIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class MaterialInstanceConstant**)&params[4];
		}
		class MaterialInstanceTimeVarying* CreateAndSetMaterialInstanceTimeVarying(int ElementIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.MeshComponent.CreateAndSetMaterialInstanceTimeVarying");
			byte params[8] = { NULL };
			*(int*)&params[0] = ElementIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class MaterialInstanceTimeVarying**)&params[4];
		}
	};
}
#undef ADD_STRUCT
