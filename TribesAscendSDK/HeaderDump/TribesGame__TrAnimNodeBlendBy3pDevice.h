#pragma once
#include "TribesGame__TrAnimNodeBlendList.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrAnimNodeBlendBy3pDevice." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrAnimNodeBlendBy3pDevice." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrAnimNodeBlendBy3pDevice : public TrAnimNodeBlendList
	{
	public:
		ADD_VAR(::NameProperty, m_StandardReloadAnimName, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, m_SkiingReloadName, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, m_StandardFireAnimName, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, m_SkiingFireName, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fRefireTimePreview, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bCurrentDeviceSupportsAltSkiReloadAnims, 0x10)
		ADD_VAR(::BoolProperty, m_bCurrentDeviceSupportsAltSkiFireAnims, 0x8)
		ADD_VAR(::BoolProperty, m_bScalePutawayRetrieveAnims, 0x4)
		ADD_VAR(::BoolProperty, m_bFirePreview, 0x2)
		ADD_VAR(::BoolProperty, m_bScaleFireByRefireTime, 0x1)
		ADD_OBJECT(TrPawn, m_TrPawn)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
