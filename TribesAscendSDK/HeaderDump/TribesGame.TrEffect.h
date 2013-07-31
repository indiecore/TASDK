#pragma once
#include "Engine.Actor.h"
#include "Core.Object.h"
#include "TribesGame.TrObject.h"
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
	class TrEffect : public Object
	{
	public:
		ADD_OBJECT(ScriptClass, m_EffectFormClass, 76)
		ADD_STRUCT(float, m_fValue, 72)
		ADD_BOOL(m_bRemovable, 68, 0x1)
		ADD_STRUCT(TrObject::EffectCalcMethod, m_eCalcMethodCode, 64)
		ADD_STRUCT(int, m_nEffectInstanceId, 60)
		void Apply(class Actor* Target, Actor::ImpactInfo Impact)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87081);
			byte params[84] = { NULL };
			*(class Actor**)params = Target;
			*(Actor::ImpactInfo*)&params[4] = Impact;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Remove(class Actor* Target)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87084);
			byte params[4] = { NULL };
			*(class Actor**)params = Target;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CanBeApplied(class Actor* Target)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87086);
			byte params[8] = { NULL };
			*(class Actor**)params = Target;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
