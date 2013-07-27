#pragma once
#include "TribesGame.TrEffect_Managed.h"
#include "Engine.Actor.h"
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
	class TrEffect_Sensor : public TrEffect_Managed
	{
	public:
		ADD_BOOL(m_bSeeLowHealthEnemy, 96, 0x20)
		ADD_BOOL(m_bSeeStealthedEnemy, 96, 0x10)
		ADD_BOOL(m_bSeeNormalEnemy, 96, 0x8)
		ADD_BOOL(m_bDisplayForeground, 96, 0x4)
		ADD_BOOL(m_bDisplayInGame, 96, 0x2)
		ADD_BOOL(m_bRequiresLOS, 96, 0x1)
		ADD_STRUCT(float, m_fScannerRange, 92)
		ADD_STRUCT(float, m_fScannerFOV, 88)
		void Apply(class Actor* Target, Actor::ImpactInfo Impact)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEffect_Sensor.Apply");
			byte params[84] = { NULL };
			*(class Actor**)&params[0] = Target;
			*(Actor::ImpactInfo*)&params[4] = Impact;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Remove(class Actor* Target)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEffect_Sensor.Remove");
			byte params[4] = { NULL };
			*(class Actor**)&params[0] = Target;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
