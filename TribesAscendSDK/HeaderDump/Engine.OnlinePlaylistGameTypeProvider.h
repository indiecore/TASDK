#pragma once
#include "Engine.UIResourceDataProvider.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class OnlinePlaylistGameTypeProvider : public UIResourceDataProvider
	{
	public:
		ADD_STRUCT(int, GameTypeId, 156)
		ADD_STRUCT(ScriptString*, Description, 144)
		ADD_STRUCT(ScriptString*, DisplayName, 132)
		ADD_STRUCT(ScriptName, PlaylistGameTypeName, 124)
	};
}
#undef ADD_STRUCT
