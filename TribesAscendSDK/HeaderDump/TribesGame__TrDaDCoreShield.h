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
		void Init(int ShieldIndex, class TrDaDCore* Core, class TrDaDShell* Shell)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDaDCoreShield.Init");
			byte* params = (byte*)malloc(12);
			*(int*)params = ShieldIndex;
			*(class TrDaDCore**)(params + 4) = Core;
			*(class TrDaDShell**)(params + 8) = Shell;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDaDCoreShield.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisableBlocking()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDaDCoreShield.DisableBlocking");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void EnableBlocking()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDaDCoreShield.EnableBlocking");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateMaterialForPawn(class TrPawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDaDCoreShield.UpdateMaterialForPawn");
			byte* params = (byte*)malloc(4);
			*(class TrPawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CreateMICs()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDaDCoreShield.CreateMICs");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
