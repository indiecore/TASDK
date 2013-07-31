#pragma once
#include "Engine.SeqVar_Object.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class SeqVar_Character : public SeqVar_Object
	{
	public:
		ADD_OBJECT(ScriptClass, PawnClass, 176)
	};
}
#undef ADD_OBJECT
