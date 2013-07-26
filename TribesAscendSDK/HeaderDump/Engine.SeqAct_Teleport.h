#pragma once
#include "Engine.SequenceAction.h"
#include "Engine.Actor.h"
#include "Core.Object.Vector.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqAct_Teleport." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqAct_Teleport : public SequenceAction
	{
	public:
		ADD_VAR(::BoolProperty, bCheckOverlap, 0x2)
		ADD_VAR(::BoolProperty, bUpdateRotation, 0x1)
		ADD_VAR(::FloatProperty, TeleportDistance, 0xFFFFFFFF)
		bool ShouldTeleport(class Actor* TestActor, Vector TeleportLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SeqAct_Teleport.ShouldTeleport");
			byte* params = (byte*)malloc(20);
			*(class Actor**)params = TestActor;
			*(Vector*)(params + 4) = TeleportLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		int GetObjClassVersion()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SeqAct_Teleport.GetObjClassVersion");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
