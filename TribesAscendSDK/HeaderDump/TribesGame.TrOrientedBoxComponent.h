#pragma once
#include "Engine.PrimitiveComponent.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class TrOrientedBoxComponent : public PrimitiveComponent
	{
	public:
		ADD_STRUCT(float, BoxLength, 496)
		ADD_STRUCT(float, BoxWidth, 492)
		ADD_STRUCT(float, BoxHeight, 488)
		void SetBoxSize(float NewHeight, float NewLength, float NewWidth, bool IsRadii)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrOrientedBoxComponent.SetBoxSize");
			byte params[16] = { NULL };
			*(float*)&params[0] = NewHeight;
			*(float*)&params[4] = NewLength;
			*(float*)&params[8] = NewWidth;
			*(bool*)&params[12] = IsRadii;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
