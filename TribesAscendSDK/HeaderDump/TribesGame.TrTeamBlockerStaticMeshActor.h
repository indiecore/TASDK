#pragma once
#include "Engine.StaticMeshActor.h"
#include "Engine.MaterialInstanceConstant.h"
#include "Engine.Material.h"
#include "TribesGame.TrPawn.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
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
	class TrTeamBlockerStaticMeshActor : public StaticMeshActor
	{
	public:
		ADD_BOOL(m_bDisableBlockingOnSiegePhase0Ends, 488, 0x1)
		ADD_STRUCT(ScriptArray<class MaterialInstanceConstant*>, m_MICs, 492)
		ADD_OBJECT(Material, m_BaseMaterial, 504)
		ADD_STRUCT(byte, m_DefenderTeamIndex, 484)
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrTeamBlockerStaticMeshActor.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisableBlocking()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrTeamBlockerStaticMeshActor.DisableBlocking");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void EnableBlocking()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrTeamBlockerStaticMeshActor.EnableBlocking");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateMaterialForPawn(class TrPawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrTeamBlockerStaticMeshActor.UpdateMaterialForPawn");
			byte params[4] = { NULL };
			*(class TrPawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CreateMICs()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrTeamBlockerStaticMeshActor.CreateMICs");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
