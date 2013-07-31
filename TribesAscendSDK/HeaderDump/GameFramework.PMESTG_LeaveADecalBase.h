#pragma once
#include "Engine.ParticleModuleEventSendToGame.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class PMESTG_LeaveADecalBase : public ParticleModuleEventSendToGame
	{
	public:
		ADD_OBJECT(ScriptClass, PhysicalMaterialPropertyClass, 60)
	};
}
#undef ADD_OBJECT
