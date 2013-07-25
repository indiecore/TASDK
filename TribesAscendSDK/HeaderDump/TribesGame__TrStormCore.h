#pragma once
#include "TribesGame__TrGameObjective.h"
#include "Engine__MaterialInstanceConstant.h"
#include "Engine__Controller.h"
#include "Engine__Actor.h"
#include "Engine__Canvas.h"
#include "Engine__PlayerController.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrStormCore." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrStormCore." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrStormCore : public TrGameObjective
	{
	public:
		ADD_VAR(::FloatProperty, m_fShieldBarPlacementY, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInstanceConstant, m_ShieldBarMIC)
		// Here lies the not-yet-implemented method 'TakeDamage'
		// Here lies the not-yet-implemented method 'GetHealthAmount'
		// Here lies the not-yet-implemented method 'GetShieldAmount'
		// Here lies the not-yet-implemented method 'OnCoreDestroyed'
		// Here lies the not-yet-implemented method 'PostRenderFor'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
