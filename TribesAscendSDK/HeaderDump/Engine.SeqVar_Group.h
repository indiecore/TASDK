#pragma once
#include "Engine.SeqVar_Object.h"
#include "Core.Object.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class SeqVar_Group : public SeqVar_Object
	{
	public:
		ADD_STRUCT(ScriptArray<class Object*>, Actors, 188)
		ADD_BOOL(bCachedList, 184, 0x1)
		ADD_STRUCT(ScriptName, GroupName, 176)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
