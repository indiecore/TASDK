#pragma once
#include "Engine.Texture.h"
#include "Engine.SequenceAction.h"
#include "Engine.MaterialInstanceConstant.h"
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
	class SeqAct_SetMatInstTexParam : public SequenceAction
	{
	public:
		ADD_STRUCT(ScriptName, ParamName, 240)
		ADD_OBJECT(Texture, NewTexture, 236)
		ADD_OBJECT(MaterialInstanceConstant, MatInst, 232)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
