#pragma once
#include "UTGame.UTUIResourceDataProvider.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UTUIDataProvider_GameModeInfo : public UTUIResourceDataProvider
	{
	public:
		ADD_STRUCT(ScriptString*, GameMode, 152)
		ADD_STRUCT(ScriptString*, DefaultMap, 164)
		ADD_STRUCT(ScriptString*, Prefixes, 236)
		ADD_STRUCT(ScriptString*, GameSettingsClass, 176)
		ADD_STRUCT(ScriptString*, Description, 212)
		ADD_STRUCT(ScriptString*, PreviewImageMarkup, 224)
		ADD_STRUCT(float, IconVL, 272)
		ADD_STRUCT(float, IconUL, 268)
		ADD_STRUCT(float, IconV, 264)
		ADD_STRUCT(float, IconU, 260)
		ADD_STRUCT(ScriptString*, IconImage, 248)
		ADD_STRUCT(ScriptString*, OptionSet, 200)
		ADD_STRUCT(ScriptString*, GameSearchClass, 188)
	};
}
#undef ADD_STRUCT
