#pragma once
#include "Engine__PrimitiveComponent.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrOrientedBoxComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrOrientedBoxComponent : public PrimitiveComponent
	{
	public:
		ADD_VAR(::FloatProperty, BoxLength, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BoxWidth, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BoxHeight, 0xFFFFFFFF)
		void SetBoxSize(float NewHeight, float NewLength, float NewWidth, bool IsRadii)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrOrientedBoxComponent.SetBoxSize");
			byte* params = (byte*)malloc(16);
			*(float*)params = NewHeight;
			*(float*)(params + 4) = NewLength;
			*(float*)(params + 8) = NewWidth;
			*(bool*)(params + 12) = IsRadii;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
