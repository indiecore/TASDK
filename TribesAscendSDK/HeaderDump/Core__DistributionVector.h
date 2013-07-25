#pragma once
#include "Core__Component.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Core.DistributionVector." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Core.DistributionVector." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class DistributionVector : public Component
	{
	public:
		ADD_VAR(::BoolProperty, bIsDirty, 0x2)
		ADD_VAR(::BoolProperty, bCanBeBaked, 0x1)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTable_FCurveEdInterface'!
		Vector GetVectorValue(float F, int LastExtreme)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.DistributionVector.GetVectorValue");
			byte* params = (byte*)malloc(20);
			*(float*)params = F;
			*(int*)(params + 4) = LastExtreme;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 8);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
