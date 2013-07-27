#pragma once
#include "TribesGame.TrDevice_Pack.h"
#include "TribesGame.TrDevice.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class TrDevice_AmmoPack : public TrDevice_Pack
	{
	public:
		ADD_STRUCT(int, m_nAmmoPackMultBelt, 2176)
		ADD_STRUCT(int, m_nAmmoPackMultSecondary, 2172)
		ADD_STRUCT(int, m_nAmmoPackMultPrimary, 2168)
		void AddAmmoBuff(class TrDevice* Dev, float Mult)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_AmmoPack.AddAmmoBuff");
			byte params[8] = { NULL };
			*(class TrDevice**)&params[0] = Dev;
			*(float*)&params[4] = Mult;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ApplyAmmoBuff()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_AmmoPack.ApplyAmmoBuff");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
