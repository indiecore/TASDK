#pragma once
#include "Core.Object.h"
#include "Engine.Material.h"
#include "TribesGame.TrObject.h"
#include "Engine.SoundCue.h"
#include "Engine.ParticleSystem.h"
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
	class TrEffectForm : public Object
	{
	public:
		ADD_BOOL(m_bIsManaged, 76, 0x2)
		ADD_OBJECT(Material, m_BodyMat, 60)
		ADD_STRUCT(TrObject::EffectFormPriority, m_ePriority, 72)
		ADD_BOOL(m_bApplied, 76, 0x1)
		ADD_OBJECT(SoundCue, m_SoundCue, 84)
		ADD_OBJECT(ParticleSystem, m_PSC, 80)
		ADD_STRUCT(TrObject::EffectFormMatTypes, m_eMatType, 73)
		ADD_STRUCT(float, m_fBodyMatFadeOutTime, 68)
		ADD_STRUCT(float, m_fBodyMatFadeInTime, 64)
		class Material* GetOverwriteMat(ScriptArray<TrObject::EffectFormOverwrite> List)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87227);
			byte params[16] = { NULL };
			*(ScriptArray<TrObject::EffectFormOverwrite>*)params = List;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Material**)&params[12];
		}
		class Material* GetMatApplyToPawn(ScriptClass* PawnClass)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87232);
			byte params[8] = { NULL };
			*(ScriptClass**)params = PawnClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Material**)&params[4];
		}
		class Material* GetMatApplyToWeapon(ScriptClass* devClass)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87235);
			byte params[8] = { NULL };
			*(ScriptClass**)params = devClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Material**)&params[4];
		}
		class Material* GetMatApplyToAttachment(ScriptClass* attClass)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87238);
			byte params[8] = { NULL };
			*(ScriptClass**)params = attClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Material**)&params[4];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
