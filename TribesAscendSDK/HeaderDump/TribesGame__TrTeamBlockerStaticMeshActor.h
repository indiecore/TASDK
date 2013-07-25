#pragma once
#include "Engine__StaticMeshActor.h"
#include "Engine__Material.h"
#include "TribesGame__TrPawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrTeamBlockerStaticMeshActor." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrTeamBlockerStaticMeshActor." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrTeamBlockerStaticMeshActor : public StaticMeshActor
	{
	public:
		ADD_VAR(::BoolProperty, m_bDisableBlockingOnSiegePhase0Ends, 0x1)
		ADD_OBJECT(Material, m_BaseMaterial)
		ADD_VAR(::ByteProperty, m_DefenderTeamIndex, 0xFFFFFFFF)
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
			byte* params = (byte*)malloc(4);
			*(class TrPawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CreateMICs()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrTeamBlockerStaticMeshActor.CreateMICs");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
