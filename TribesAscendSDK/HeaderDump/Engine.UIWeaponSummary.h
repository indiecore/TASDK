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
	class UIWeaponSummary : public UIResourceDataProvider
	{
	public:
		ADD_BOOL(bIsDisabled, 160, 0x1)
		ADD_STRUCT(ScriptString*, WeaponDescription, 148)
		ADD_STRUCT(ScriptString*, FriendlyName, 136)
		ADD_STRUCT(ScriptString*, ClassPathName, 124)
		bool IsProviderDisabled()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIWeaponSummary.IsProviderDisabled");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
