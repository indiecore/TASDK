#pragma once
#include "Engine__DynamicSMActor.h"
#include "TribesGame__TrStormCore.h"
#include "Engine__Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrStormCarrierShield." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrStormCarrierShield." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrStormCarrierShield : public DynamicSMActor
	{
	public:
		ADD_OBJECT(TrStormCore, m_AssociatedCarrierCore)
		ADD_VAR(::BoolProperty, m_bAreShieldsUp, 0x1)
		// Here lies the not-yet-implemented method 'OnShieldsDestroyed'
		// Here lies the not-yet-implemented method 'Touch'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
