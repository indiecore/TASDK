#pragma once
#include "Engine.UIResourceDataProvider.h"
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
	class UIGameInfoSummary : public UIResourceDataProvider
	{
	public:
		ADD_STRUCT(ScriptString*, Description, 188)
		ADD_STRUCT(ScriptString*, GameName, 176)
		ADD_STRUCT(ScriptString*, GameSettingsClassName, 164)
		ADD_BOOL(bIsDisabled, 160, 0x2)
		ADD_BOOL(bIsTeamGame, 160, 0x1)
		ADD_STRUCT(ScriptString*, MapPrefix, 148)
		ADD_STRUCT(ScriptString*, GameAcronym, 136)
		ADD_STRUCT(ScriptString*, ClassName, 124)
		bool IsProviderDisabled()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(29029);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
