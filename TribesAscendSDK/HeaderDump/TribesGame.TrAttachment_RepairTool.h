#pragma once
#include "TribesGame.TrDeviceAttachment.h"
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
namespace UnrealScript
{
	class TrAttachment_RepairTool : public TrDeviceAttachment
	{
	public:
		ADD_STRUCT(Object::Vector, m_Tangent, 804)
		ADD_STRUCT(Object::Vector, m_Location, 792)
		ADD_BOOL(m_bIsTracerActive, 784, 0x1)
		void KillRepairEffect()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAttachment_RepairTool.KillRepairEffect");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SpawnRepairEffect(Object::Vector HitLocation, Object::Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAttachment_RepairTool.SpawnRepairEffect");
			byte params[24] = { NULL };
			*(Object::Vector*)&params[0] = HitLocation;
			*(Object::Vector*)&params[12] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateRepairEffect(float DeltaTime, Object::Vector HitLocation, Object::Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAttachment_RepairTool.UpdateRepairEffect");
			byte params[28] = { NULL };
			*(float*)&params[0] = DeltaTime;
			*(Object::Vector*)&params[4] = HitLocation;
			*(Object::Vector*)&params[16] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayImpactEffects(Object::Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAttachment_RepairTool.PlayImpactEffects");
			byte params[12] = { NULL };
			*(Object::Vector*)&params[0] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ThirdPersonFireEffects(Object::Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAttachment_RepairTool.ThirdPersonFireEffects");
			byte params[12] = { NULL };
			*(Object::Vector*)&params[0] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StopThirdPersonFireEffects()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAttachment_RepairTool.StopThirdPersonFireEffects");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
