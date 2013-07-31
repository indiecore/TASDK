#pragma once
#include "Engine.Volume.h"
#include "Engine.PortalTeleporter.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class PortalVolume : public Volume
	{
	public:
		ADD_STRUCT(ScriptArray<class PortalTeleporter*>, Portals, 520)
	};
}
#undef ADD_STRUCT
