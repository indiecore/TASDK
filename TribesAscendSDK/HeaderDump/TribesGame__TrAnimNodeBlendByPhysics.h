#pragma once
#include "TribesGame__TrAnimNodeBlendList.h"
#include "TribesGame__TrPawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrAnimNodeBlendByPhysics." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrAnimNodeBlendByPhysics." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrAnimNodeBlendByPhysics : public TrAnimNodeBlendList
	{
	public:
		ADD_VAR(::BoolProperty, m_bDirectUnspecifiedPhysicsThroughChild0, 0x1)
		ADD_VAR(::IntProperty, m_CurrentPhysicsChildIndex, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, m_CurrentPhysics, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, m_LastPhysics, 0xFFFFFFFF)
		ADD_OBJECT(TrPawn, m_TrPawn)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
