#pragma once
#include "TribesGame__TrPawn.h"
#include "Engine__AnimNodeSequenceBlendBase.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrAnimNodeBlendByDirection." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrAnimNodeBlendByDirection." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrAnimNodeBlendByDirection : public AnimNodeSequenceBlendBase
	{
	public:
		ADD_OBJECT(TrPawn, m_TrPawn)
		ADD_VAR(::BoolProperty, m_bForwardLeftCorrection, 0x2)
		ADD_VAR(::BoolProperty, m_bInterpolateWeights, 0x1)
		ADD_VAR(::FloatProperty, m_fDirAngle, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fBlendSpeed, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
