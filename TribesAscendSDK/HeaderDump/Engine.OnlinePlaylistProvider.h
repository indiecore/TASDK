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
	class OnlinePlaylistProvider : public UIResourceDataProvider
	{
	public:
		ADD_STRUCT(ScriptArray<ScriptName>, PlaylistGameTypeNames, 128)
		ADD_STRUCT(int, Priority, 156)
		ADD_BOOL(bIsArbitrated, 152, 0x1)
		ADD_STRUCT(ScriptString*, DisplayName, 140)
		ADD_STRUCT(int, PlaylistId, 124)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
