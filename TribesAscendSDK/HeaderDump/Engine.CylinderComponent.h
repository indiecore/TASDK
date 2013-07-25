#pragma once
#include "Engine.PrimitiveComponent.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.CylinderComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.CylinderComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class CylinderComponent : public PrimitiveComponent
	{
	public:
		ADD_VAR(::BoolProperty, bAlwaysRenderIfSelected, 0x4)
		ADD_VAR(::BoolProperty, bDrawNonColliding, 0x2)
		ADD_VAR(::BoolProperty, bDrawBoundingBox, 0x1)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'CylinderColor'!
		ADD_VAR(::FloatProperty, CollisionRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CollisionHeight, 0xFFFFFFFF)
		void SetCylinderSize(float NewRadius, float NewHeight)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.CylinderComponent.SetCylinderSize");
			byte* params = (byte*)malloc(8);
			*(float*)params = NewRadius;
			*(float*)(params + 4) = NewHeight;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
