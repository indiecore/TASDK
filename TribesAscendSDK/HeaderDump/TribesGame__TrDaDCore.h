#pragma once
#include "TribesGame__TrDaDCapacitor.h"
#include "TribesGame__TrGameObjective.h"
#include "TribesGame__TrDaDShell.h"
#include "TribesGame__TrDaDCoreShield.h"
#include "Engine__MaterialInstanceConstant.h"
#include "Engine__Controller.h"
#include "Engine__Actor.h"
#include "Engine__Canvas.h"
#include "Engine__PlayerController.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrDaDCore." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrDaDCore." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrDaDCore : public TrGameObjective
	{
	public:
		ADD_OBJECT(TrDaDShell, m_Shell)
		ADD_OBJECT(TrDaDCoreShield, m_Shields)
		ADD_OBJECT(TrDaDCapacitor, m_Capacitors)
		ADD_VAR(::FloatProperty, m_fShieldBarPlacementY, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInstanceConstant, m_ShieldBarMIC)
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'SpawnShield'
		// Here lies the not-yet-implemented method 'OnCapacitorBlownUp'
		// Here lies the not-yet-implemented method 'OnCapacitorRestored'
		// Here lies the not-yet-implemented method 'TakeDamage'
		// Here lies the not-yet-implemented method 'OnCoreDestroyed'
		// Here lies the not-yet-implemented method 'PostRenderFor'
		// Here lies the not-yet-implemented method 'GetCeilPctScore'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
