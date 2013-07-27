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
namespace UnrealScript
{
	class Commandlet : public Object
	{
	public:
		ADD_STRUCT(ScriptArray<ScriptString*>, HelpParamNames, 96)
		ADD_STRUCT(ScriptArray<ScriptString*>, HelpParamDescriptions, 108)
		ADD_BOOL(ShowErrorCount, 120, 0x10)
		ADD_BOOL(LogToConsole, 120, 0x8)
		ADD_BOOL(IsEditor, 120, 0x4)
		ADD_BOOL(IsClient, 120, 0x2)
		ADD_BOOL(IsServer, 120, 0x1)
		ADD_STRUCT(ScriptString*, HelpWebLink, 84)
		ADD_STRUCT(ScriptString*, HelpUsage, 72)
		ADD_STRUCT(ScriptString*, HelpDescription, 60)
		int Main(ScriptString* Params)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Core.Commandlet.Main");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = Params;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[12];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
