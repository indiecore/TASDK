#pragma once
#include "Engine.UIDataProvider_Settings.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UDKUIDataProvider_SearchResult : public UIDataProvider_Settings
	{
	public:
		ADD_STRUCT(ScriptString*, IconFontPathName, 176)
		ADD_STRUCT(ScriptName, MapNameTag, 168)
		ADD_STRUCT(ScriptName, ServerFlagsTag, 160)
		ADD_STRUCT(ScriptName, GameModeFriendlyNameTag, 152)
		ADD_STRUCT(ScriptName, PlayerRatioTag, 144)
		bool IsPrivateServer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35582);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
	};
}
#undef ADD_STRUCT
