#pragma once
#include "TribesGame__TrGameObjective.h"
#include "Engine__Actor.h"
#include "TribesGame__TrDaDCore.h"
#include "Engine__MaterialInstanceConstant.h"
#include "Engine__Controller.h"
#include "Engine__Texture2D.h"
#include "Engine__Canvas.h"
#include "Engine__PlayerController.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrDaDCapacitor." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrDaDCapacitor." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrDaDCapacitor : public TrGameObjective
	{
	public:
		ADD_VAR(::StrProperty, StringC, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, StringB, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, StringA, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_CapacitorIndex, 0xFFFFFFFF)
		ADD_OBJECT(TrDaDCore, m_Core)
		ADD_VAR(::FloatProperty, m_fShieldBarPlacementY, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInstanceConstant, m_ShieldBarMIC)
		// Here lies the not-yet-implemented method 'Init'
		// Here lies the not-yet-implemented method 'TakeDamage'
		// Here lies the not-yet-implemented method 'GetScreenName'
		// Here lies the not-yet-implemented method 'PostRenderFor'
		// Here lies the not-yet-implemented method 'GetMarker'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
