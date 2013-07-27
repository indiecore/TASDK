#pragma once
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
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class Factory : public Object
	{
	public:
		ADD_STRUCT(ScriptArray<ScriptString*>, Formats, 80)
		ADD_STRUCT(ScriptArray<ScriptString*>, ValidGameNames, 100)
		ADD_STRUCT(int, AutoPriority, 96)
		ADD_BOOL(bText, 92, 0x8)
		ADD_BOOL(bEditorImport, 92, 0x4)
		ADD_BOOL(bEditAfterNew, 92, 0x2)
		ADD_BOOL(bCreateNew, 92, 0x1)
		ADD_STRUCT(ScriptString*, Description, 68)
		ADD_OBJECT(ScriptClass, ContextClass, 64)
		ADD_OBJECT(ScriptClass, SupportedClass, 60)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
