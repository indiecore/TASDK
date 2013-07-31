#pragma once
#include "Engine.PrimitiveComponent.h"
#include "Engine.LensFlare.h"
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
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class LensFlareComponent : public PrimitiveComponent
	{
	public:
		struct LensFlareElementMaterials
		{
		public:
			ADD_STRUCT(ScriptArray<class MaterialInterface*>, ElementMaterials, 0)
		};
		struct LensFlareElementInstance
		{
		};
		ADD_STRUCT(ScriptArray<LensFlareComponent::LensFlareElementMaterials>, Materials, 540)
		ADD_STRUCT(float, NextTraceTime, 556)
		ADD_STRUCT(Object::Pointer, ReleaseResourcesFence, 552)
		ADD_STRUCT(Object::LinearColor, SourceColor, 524)
		ADD_STRUCT(float, Radius, 520)
		ADD_STRUCT(float, ConeFudgeFactor, 516)
		ADD_STRUCT(float, InnerCone, 512)
		ADD_STRUCT(float, OuterCone, 508)
		ADD_BOOL(bVisibleForMobile, 504, 0x40)
		ADD_BOOL(bUsesSceneColor, 504, 0x20)
		ADD_BOOL(bHasUnlitDistortion, 504, 0x10)
		ADD_BOOL(bHasUnlitTranslucency, 504, 0x8)
		ADD_BOOL(bHasTranslucency, 504, 0x4)
		ADD_BOOL(bIsActive, 504, 0x2)
		ADD_BOOL(bAutoActivate, 504, 0x1)
		ADD_OBJECT(LensFlare, Template, 488)
		void SetTemplate(class LensFlare* NewTemplate, bool bForceSet)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19314);
			byte params[8] = { NULL };
			*(class LensFlare**)params = NewTemplate;
			*(bool*)&params[4] = bForceSet;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSourceColor(Object::LinearColor InSourceColor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19317);
			byte params[16] = { NULL };
			*(Object::LinearColor*)params = InSourceColor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetIsActive(bool bInIsActive)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19319);
			byte params[4] = { NULL };
			*(bool*)params = bInIsActive;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
