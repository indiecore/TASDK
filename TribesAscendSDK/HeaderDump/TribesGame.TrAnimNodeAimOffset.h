#pragma once
#include "TribesGame.TrPawn.h"
#include "Engine.AnimNodeAimOffset.h"
#include "Core.Object.h"
#include "TribesGame.TrDevice.h"
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
	class TrAnimNodeAimOffset : public AnimNodeAimOffset
	{
	public:
		ADD_STRUCT(Object::Vector2D, m_TargetRandomAimLocation, 388)
		ADD_STRUCT(float, m_fCurrentRandomAimPointsInterval, 384)
		ADD_STRUCT(float, m_fRandomAimPointsIntervalMax, 380)
		ADD_STRUCT(float, m_fRandomAimPointsIntervalMin, 376)
		ADD_STRUCT(float, m_fRandomAimPointsInterpRate, 372)
		ADD_STRUCT(Object::Vector2D, m_RandomAimPointsRangeY, 364)
		ADD_STRUCT(Object::Vector2D, m_RandomAimPointsRangeX, 356)
		ADD_BOOL(m_bRandomAimPointsEnabled, 352, 0x1)
		ADD_STRUCT(float, m_fTurnAroundBlendTime, 348)
		ADD_STRUCT(float, m_fTurnAroundTimeToGo, 344)
		ADD_STRUCT(Object::Vector2D, m_v2dLastPostProcessedAimOffset, 336)
		ADD_STRUCT(Object::Vector2D, m_v2dLastAimOffset, 328)
		ADD_STRUCT(float, m_fTurnInPlaceOffset, 324)
		ADD_OBJECT(TrDevice, m_TrDevice, 320)
		ADD_OBJECT(TrPawn, m_TrPawn, 316)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
