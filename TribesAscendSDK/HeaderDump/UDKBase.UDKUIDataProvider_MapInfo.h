#pragma once
#include "UDKBase.UDKUIResourceDataProvider.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UDKUIDataProvider_MapInfo : public UDKUIResourceDataProvider
	{
	public:
		ADD_STRUCT(ScriptString*, PreviewImageMarkup, 192)
		ADD_STRUCT(ScriptString*, Description, 180)
		ADD_STRUCT(ScriptString*, NumPlayers, 168)
		ADD_STRUCT(ScriptString*, MapName, 156)
		ADD_STRUCT(int, MapId, 152)
	};
}
#undef ADD_STRUCT
