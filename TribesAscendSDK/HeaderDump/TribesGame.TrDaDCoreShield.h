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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(79660);
			byte params[12] = { NULL };
			*(int*)params = ShieldIndex;
			*(class TrDaDCore**)&params[4] = Core;
			*(class TrDaDShell**)&params[8] = Shell;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(79667);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisableBlocking()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(79668);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void EnableBlocking()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(79669);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateMaterialForPawn(class TrPawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(79670);
			byte params[4] = { NULL };
			*(class TrPawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CreateMICs()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(79673);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
