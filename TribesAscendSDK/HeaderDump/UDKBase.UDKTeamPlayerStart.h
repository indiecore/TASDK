#pragma once
#include "Engine.PlayerStart.h"
#include "Engine.Texture2D.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UDKTeamPlayerStart : public PlayerStart
	{
	public:
		ADD_STRUCT(ScriptArray<class Texture2D*>, TeamSprites, 704)
		ADD_STRUCT(byte, TeamNumber, 700)
	};
}
#undef ADD_STRUCT
