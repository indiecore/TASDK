#pragma once
#include "UTGame.UTWeaponPawn.h"
#include "Engine.SoundCue.h"
#include "Core.Object.h"
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
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class TrWeaponPawn : public UTWeaponPawn
	{
	public:
		ADD_STRUCT(float, m_fCurrentAccuracy, 1560)
		ADD_STRUCT(byte, r_nFlashReload, 1564)
		ADD_OBJECT(SoundCue, r_scFiringLoop, 1576)
		ADD_BOOL(r_bFiringLoopSound, 1572, 0x1)
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115617);
			byte params[8] = { NULL };
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayReload()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115619);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ProcessViewRotation(float DeltaTime, Rotator& out_ViewRotation, Rotator& out_DeltaRot)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115620);
			byte params[28] = { NULL };
			*(float*)params = DeltaTime;
			*(Rotator*)&params[4] = out_ViewRotation;
			*(Rotator*)&params[16] = out_DeltaRot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_ViewRotation = *(Rotator*)&params[4];
			out_DeltaRot = *(Rotator*)&params[16];
		}
		void ClientPlayLoopSound()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115624);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayLoopingSound(class SoundCue* InSound, bool Play)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115625);
			byte params[8] = { NULL };
			*(class SoundCue**)params = InSound;
			*(bool*)&params[4] = Play;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
