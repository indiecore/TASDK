#pragma once
#include "TribesGame.TrDaDCore.h"
#include "Engine.DynamicSMActor.h"
#include "Engine.MaterialInstanceConstant.h"
#include "Engine.Material.h"
#include "TribesGame.TrDaDShell.h"
#include "TribesGame.TrPawn.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class TrDaDCoreShield : public DynamicSMActor
	{
	public:
		ADD_STRUCT(ScriptArray<class MaterialInstanceConstant*>, m_MICs, 536)
		ADD_OBJECT(TrDaDShell, m_Shell, 560)
		ADD_STRUCT(int, m_nShieldIndex, 556)
		ADD_OBJECT(TrDaDCore, m_Core, 552)
		ADD_OBJECT(Material, m_BaseMaterial, 548)
		ADD_STRUCT(byte, m_DefenderTeamIndex, 532)
		void Init(int ShieldIndex, class TrDaDCore* Core, class TrDaDShell* Shell)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDaDCoreShield.Init");
			byte params[12] = { NULL };
			*(int*)&params[0] = ShieldIndex;
			*(class TrDaDCore**)&params[4] = Core;
			*(class TrDaDShell**)&params[8] = Shell;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
			byte params[4] = { NULL };
			*(class TrPawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CreateMICs()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDaDCoreShield.CreateMICs");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
