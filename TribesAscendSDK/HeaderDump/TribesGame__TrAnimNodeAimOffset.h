#pragma once
#include "Engine__AnimNodeAimOffset.h"
#include "TribesGame__TrDevice.h"
#include "TribesGame__TrPawn.h"
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
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D' for the property named 'm_TargetRandomAimLocation'!
		ADD_VAR(::FloatProperty, m_fCurrentRandomAimPointsInterval, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fRandomAimPointsIntervalMax, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fRandomAimPointsIntervalMin, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fRandomAimPointsInterpRate, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D' for the property named 'm_RandomAimPointsRangeY'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D' for the property named 'm_RandomAimPointsRangeX'!
		ADD_VAR(::BoolProperty, m_bRandomAimPointsEnabled, 0x1)
		ADD_VAR(::FloatProperty, m_fTurnAroundBlendTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fTurnAroundTimeToGo, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D' for the property named 'm_v2dLastPostProcessedAimOffset'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D' for the property named 'm_v2dLastAimOffset'!
		ADD_VAR(::FloatProperty, m_fTurnInPlaceOffset, 0xFFFFFFFF)
		ADD_OBJECT(TrDevice, m_TrDevice)
		ADD_OBJECT(TrPawn, m_TrPawn)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
