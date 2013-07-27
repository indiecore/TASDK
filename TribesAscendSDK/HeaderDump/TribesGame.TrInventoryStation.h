#pragma once
#include "TribesGame.TrStation.h"
#include "Engine.Texture2D.h"
#include "TribesGame.TrPawn.h"
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
	class TrInventoryStation : public TrStation
	{
	public:
		ADD_OBJECT(TrPawn, m_PawnToRefresh, 1420)
		ADD_BOOL(m_bForceHealthRegen, 1416, 0x1)
		ADD_STRUCT(Object::Color, m_PowerOffColor, 1412)
		ADD_STRUCT(Object::Color, m_PowerOnColor, 1408)
		ADD_STRUCT(float, m_fStationReleaseTime, 1400)
		ADD_STRUCT(float, m_fStationAnimTime, 1396)
		void PawnEnteredStation(class TrPawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98206);
			byte params[4] = { NULL };
			*(class TrPawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnPowerStatusChanged()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98211);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayStationEnteredEffects()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98212);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Timer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98216);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class Texture2D* GetMarker()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98218);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Texture2D**)params;
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
