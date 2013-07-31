#pragma once
#include "PlatformCommon.TgGameEngine.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class TrGameEngine : public TgGameEngine
	{
	public:
		ADD_STRUCT(float, fBGMVolume, 1840)
	};
}
#undef ADD_STRUCT