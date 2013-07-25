#pragma once
#include "Engine__SequenceObject.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SequenceVariable." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SequenceVariable : public SequenceObject
	{
	public:
		ADD_VAR(::NameProperty, VarName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
