#pragma once
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class ApexAsset : public Object
	{
	public:
		ADD_STRUCT(ScriptArray<
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void*>, ApexComponents, 72)
		ADD_STRUCT(ScriptArray<class ApexAsset*>, NamedReferences, 84)
		ADD_STRUCT(ScriptString*, SourceFilePath, 96)
		ADD_STRUCT(ScriptString*, OriginalApexName, 60)
	};
}
#undef ADD_STRUCT
