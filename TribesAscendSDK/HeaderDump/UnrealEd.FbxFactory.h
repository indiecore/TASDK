#pragma once
#include "Core.Factory.h"
#include "UnrealEd.FbxImportUI.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UnrealEd.FbxFactory." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class FbxFactory : public Factory
	{
	public:
		ADD_OBJECT(FbxImportUI, Import Options)
	};
}
#undef ADD_OBJECT
