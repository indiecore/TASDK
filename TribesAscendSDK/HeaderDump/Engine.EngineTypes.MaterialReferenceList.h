#pragma once
#include "Engine.MaterialInterface.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty EngineTypes.MaterialReferenceList." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class MaterialReferenceList
	{
	public:
		ADD_OBJECT(MaterialInterface, TargetMaterial)
	};
}
#undef ADD_OBJECT
