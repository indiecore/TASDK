#pragma once
#include "UTGame.UTUIResourceDataProvider.h"
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
	class UTUIDataProvider_Mutator : public UTUIResourceDataProvider
	{
	public:
		ADD_STRUCT(ScriptString*, ClassName, 152)
		ADD_STRUCT(ScriptString*, Description, 164)
		ADD_STRUCT(ScriptString*, GroupNames, 176)
		ADD_STRUCT(ScriptArray<ScriptString*>, SupportedGameTypes, 188)
		ADD_BOOL(bOfficialMutator, 200, 0x2)
		ADD_BOOL(bStandaloneOnly, 200, 0x1)
		bool ShouldBeFiltered()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38898);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool SupportsCurrentGameMode()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49611);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
