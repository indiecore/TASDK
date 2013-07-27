#pragma once
#include "Engine.MaterialInterface.h"
#include "Engine.PhysicalMaterial.h"
#include "Engine.Texture.h"
#include "Core.Object.h"
#include "Engine.Font.h"
#include "Engine.Texture2D.h"
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
	class MaterialInstance : public MaterialInterface
	{
	public:
		ADD_STRUCT(ScriptArray<class Texture*>, ReferencedTextures, 392)
		ADD_STRUCT(ScriptArray<Object::Guid>, ReferencedTextureGuids, 404)
		ADD_STRUCT(Object::Guid, ParentLightingGuid, 416)
		ADD_STRUCT(Object::Pointer, Resources, 380)
		ADD_STRUCT(Object::Pointer, StaticPermutationResources, 372)
		ADD_STRUCT(Object::Pointer, StaticParameters, 364)
		ADD_BOOL(bNeedsMaterialFlattening, 360, 0x8)
		ADD_BOOL(ReentrantFlag, 360, 0x4)
		ADD_BOOL(bStaticPermutationDirty, 360, 0x2)
		ADD_BOOL(bHasStaticPermutationResource, 360, 0x1)
		ADD_OBJECT(PhysicalMaterial, WhitePhysicalMaterial, 356)
		ADD_OBJECT(PhysicalMaterial, BlackPhysicalMaterial, 352)
		ADD_STRUCT(int, PhysMaterialMaskUVChannel, 348)
		ADD_OBJECT(Texture2D, PhysMaterialMask, 344)
		ADD_OBJECT(MaterialInterface, Parent, 340)
		ADD_OBJECT(PhysicalMaterial, PhysMaterial, 336)
		void SetParent(class MaterialInterface* NewParent)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19789);
			byte params[4] = { NULL };
			*(class MaterialInterface**)params = NewParent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetVectorParameterValue(ScriptName ParameterName, Object::LinearColor& Value)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19791);
			byte params[24] = { NULL };
			*(ScriptName*)params = ParameterName;
			*(Object::LinearColor*)&params[8] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Value = *(Object::LinearColor*)&params[8];
		}
		void SetScalarParameterValue(ScriptName ParameterName, float Value)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19794);
			byte params[12] = { NULL };
			*(ScriptName*)params = ParameterName;
			*(float*)&params[8] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetScalarCurveParameterValue(ScriptName ParameterName, Object::InterpCurveFloat& Value)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19797);
			byte params[24] = { NULL };
			*(ScriptName*)params = ParameterName;
			*(Object::InterpCurveFloat*)&params[8] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Value = *(Object::InterpCurveFloat*)&params[8];
		}
		void SetTextureParameterValue(ScriptName ParameterName, class Texture* Value)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19800);
			byte params[12] = { NULL };
			*(ScriptName*)params = ParameterName;
			*(class Texture**)&params[8] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetFontParameterValue(ScriptName ParameterName, class Font* FontValue, int FontPage)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19803);
			byte params[16] = { NULL };
			*(ScriptName*)params = ParameterName;
			*(class Font**)&params[8] = FontValue;
			*(int*)&params[12] = FontPage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearParameterValues()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19807);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool IsInMapOrTransientPackage()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19808);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
