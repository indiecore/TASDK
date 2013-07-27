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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6923);
			byte params[8] = { NULL };
			*(int*)params = ElementIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class MaterialInterface**)&params[4];
		}
		void SetMaterial(int ElementIndex, class MaterialInterface* Material)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6926);
			byte params[8] = { NULL };
			*(int*)params = ElementIndex;
			*(class MaterialInterface**)&params[4] = Material;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int GetNumElements()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6929);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		void PrestreamTextures(float Seconds, bool bPrioritizeCharacterTextures, int CinematicTextureGroups)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6931);
			byte params[12] = { NULL };
			*(float*)params = Seconds;
			*(bool*)&params[4] = bPrioritizeCharacterTextures;
			*(int*)&params[8] = CinematicTextureGroups;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class MaterialInstanceConstant* CreateAndSetMaterialInstanceConstant(int ElementIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6935);
			byte params[8] = { NULL };
			*(int*)params = ElementIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class MaterialInstanceConstant**)&params[4];
		}
		class MaterialInstanceTimeVarying* CreateAndSetMaterialInstanceTimeVarying(int ElementIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6939);
			byte params[8] = { NULL };
			*(int*)params = ElementIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class MaterialInstanceTimeVarying**)&params[4];
		}
	};
}
#undef ADD_STRUCT
