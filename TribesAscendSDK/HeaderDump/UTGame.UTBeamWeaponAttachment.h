#pragma once
#include "Engine.ParticleSystem.h"
#include "UTGame.UTPawn.h"
#include "UTGame.UTWeaponAttachment.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class UTBeamWeaponAttachment : public UTWeaponAttachment
	{
	public:
		ADD_STRUCT(ScriptName, EndPointParamName, 740)
		ADD_OBJECT(UTPawn, PawnOwner, 736)
		ADD_STRUCT(ScriptName, BeamSockets, 720)
		ADD_OBJECT(ParticleSystem, BeamTemplate, 704)
		void AddBeamEmitter()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42416);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HideEmitter(int Index, bool bHide)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42418);
			byte params[8] = { NULL };
			*(int*)params = Index;
			*(bool*)&params[4] = bHide;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateBeam(byte FireModeNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42421);
			byte params[1] = { NULL };
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
