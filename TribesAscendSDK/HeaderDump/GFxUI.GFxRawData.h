#pragma once
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class GFxRawData : public Object
	{
	public:
		ADD_STRUCT(ScriptArray<byte>, RawData, 60)
		ADD_STRUCT(ScriptArray<ScriptString*>, ReferencedSwfs, 72)
		ADD_STRUCT(ScriptArray<class Object*>, References, 84)
		ADD_STRUCT(ScriptArray<class Object*>, UserReferences, 96)
	};
}
#undef ADD_STRUCT
