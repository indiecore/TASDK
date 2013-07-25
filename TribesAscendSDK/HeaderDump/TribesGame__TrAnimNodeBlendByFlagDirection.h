#pragma once
#include "Engine__AnimNodeAdditiveBlending.h"
#include "TribesGame__TrAnimNodeBlendList.h"
#include "TribesGame__TrFlagBase.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrAnimNodeBlendByFlagDirection." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrAnimNodeBlendByFlagDirection." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrAnimNodeBlendByFlagDirection : public TrAnimNodeBlendList
	{
	public:
		ADD_VAR(::FloatProperty, m_fIdleBlendOutTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fIdleBlendInTime, 0xFFFFFFFF)
		ADD_OBJECT(AnimNodeAdditiveBlending, m_AdditiveBlendNode)
		ADD_VAR(::NameProperty, m_nmAdditiveAnimNodeName, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fIdleSpeedSizeSq, 0xFFFFFFFF)
		ADD_OBJECT(TrFlagBase, m_TrFlagOwner)
		ADD_VAR(::ByteProperty, LastDirection, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
