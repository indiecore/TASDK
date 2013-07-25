#pragma once
#include "TribesGame__TrAnimNodeBlendList.h"
#include "TribesGame__TrPawn.h"
#include "Engine__AnimNodeSequence.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrAnimNodeBlendByRidingPassenger." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrAnimNodeBlendByRidingPassenger." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrAnimNodeBlendByRidingPassenger : public TrAnimNodeBlendList
	{
	public:
		ADD_OBJECT(AnimNodeSequence, m_FireAnimSeqNode)
		ADD_VAR(::NameProperty, m_nmFireAnimSeqNodeName, 0xFFFFFFFF)
		ADD_OBJECT(TrPawn, m_TrPawn)
		// Here lies the not-yet-implemented method 'PlayIdle'
		// Here lies the not-yet-implemented method 'PlayFire'
		// Here lies the not-yet-implemented method 'PlayReload'
		// Here lies the not-yet-implemented method 'PlayOffhand'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
