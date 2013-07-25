#pragma once
#include "Engine__InterpGroupInst.h"
#include "Engine__InterpGroupAI.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.InterpGroupInstAI." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.InterpGroupInstAI." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class InterpGroupInstAI : public InterpGroupInst
	{
	public:
		ADD_VAR(::BoolProperty, bSavedNoEncroachCheck, 0x1)
		ADD_VAR(::ByteProperty, SavedPhysics, 0xFFFFFFFF)
		ADD_OBJECT(InterpGroupAI, AIGroup)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
