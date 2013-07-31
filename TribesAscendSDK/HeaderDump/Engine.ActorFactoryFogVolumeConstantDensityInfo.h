#pragma once
#include "Engine.ActorFactory.h"
#include "Engine.MaterialInterface.h"
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
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class ActorFactoryFogVolumeConstantDensityInfo : public ActorFactory
	{
	public:
		ADD_BOOL(bNothingSelected, 96, 0x1)
		ADD_OBJECT(MaterialInterface, SelectedMaterial, 92)
	};
}
#undef ADD_BOOL
#undef ADD_OBJECT
