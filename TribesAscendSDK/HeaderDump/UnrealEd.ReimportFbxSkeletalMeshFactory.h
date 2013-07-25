#pragma once
#include "UnrealEd.FbxFactory.h"
#include "UnrealEd.FbxImportUI.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UnrealEd.ReimportFbxSkeletalMeshFactory." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class ReimportFbxSkeletalMeshFactory : public FbxFactory
	{
	public:
		ADD_OBJECT(FbxImportUI, Import Options)
	};
}
#undef ADD_OBJECT
