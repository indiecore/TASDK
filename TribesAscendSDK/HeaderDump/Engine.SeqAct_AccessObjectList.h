#pragma once
#include "Engine.SeqAct_SetSequenceVariable.h"
#include "Core.Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqAct_AccessObjectList." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.SeqAct_AccessObjectList." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SeqAct_AccessObjectList : public SeqAct_SetSequenceVariable
	{
	public:
		ADD_VAR(::IntProperty, ObjectIndex, 0xFFFFFFFF)
		ADD_OBJECT(Object, OutputObject)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
