#pragma once
#include "TribesGame.TrPawn.h"
#include "Core.Object.Vector2D.h"
#include "Engine.AnimNodeAimOffset.h"
#include "TribesGame.TrDevice.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrAnimNodeAimOffset." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrAnimNodeAimOffset." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrAnimNodeAimOffset." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrAnimNodeAimOffset : public AnimNodeAimOffset
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<Vector2D>, m_TargetRandomAimLocation, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fCurrentRandomAimPointsInterval, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fRandomAimPointsIntervalMax, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fRandomAimPointsIntervalMin, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fRandomAimPointsInterpRate, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Vector2D>, m_RandomAimPointsRangeY, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Vector2D>, m_RandomAimPointsRangeX, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bRandomAimPointsEnabled, 0x1)
		ADD_VAR(::FloatProperty, m_fTurnAroundBlendTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fTurnAroundTimeToGo, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Vector2D>, m_v2dLastPostProcessedAimOffset, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Vector2D>, m_v2dLastAimOffset, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fTurnInPlaceOffset, 0xFFFFFFFF)
		ADD_OBJECT(TrDevice, m_TrDevice)
		ADD_OBJECT(TrPawn, m_TrPawn)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
