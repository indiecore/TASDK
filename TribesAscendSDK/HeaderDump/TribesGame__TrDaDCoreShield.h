#pragma once
#include "Engine__DynamicSMActor.h"
#include "Engine__Material.h"
#include "TribesGame__TrDaDShell.h"
#include "TribesGame__TrDaDCore.h"
#include "TribesGame__TrPawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrDaDCoreShield." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrDaDCoreShield." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrDaDCoreShield : public DynamicSMActor
	{
	public:
		ADD_OBJECT(TrDaDShell, m_Shell)
		ADD_VAR(::IntProperty, m_nShieldIndex, 0xFFFFFFFF)
		ADD_OBJECT(TrDaDCore, m_Core)
		ADD_OBJECT(Material, m_BaseMaterial)
		ADD_VAR(::ByteProperty, m_DefenderTeamIndex, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'Init'
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'DisableBlocking'
		// Here lies the not-yet-implemented method 'EnableBlocking'
		// Here lies the not-yet-implemented method 'UpdateMaterialForPawn'
		// Here lies the not-yet-implemented method 'CreateMICs'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
