#pragma once
#include "Engine.InterpActor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrDaDShell." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrDaDShell : public InterpActor
	{
	public:
		ADD_VAR(::BoolProperty, r_bShield0Up, 0x1)
		ADD_VAR(::BoolProperty, r_bShield1Up, 0x2)
		ADD_VAR(::BoolProperty, r_bShield2Up, 0x4)
		ADD_VAR(::BoolProperty, r_bIsRotating, 0x8)
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDaDShell.ReplicatedEvent");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDaDShell.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartRotation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDaDShell.StartRotation");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StopRotation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDaDShell.StopRotation");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
