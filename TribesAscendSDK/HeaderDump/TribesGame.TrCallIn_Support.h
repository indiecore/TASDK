#pragma once
#include "TribesGame.TrCallIn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrCallIn_Support." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrCallIn_Support." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrCallIn_Support : public TrCallIn
	{
	public:
		ADD_VAR(::IntProperty, MaxDeployedLimit, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, ItemInDeliveryPod)
		bool FireCompletedCallIn(int CallInOffs, Vector TargetLocation, Vector TargetNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCallIn_Support.FireCompletedCallIn");
			byte* params = (byte*)malloc(32);
			*(int*)params = CallInOffs;
			*(Vector*)(params + 4) = TargetLocation;
			*(Vector*)(params + 16) = TargetNormal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 28);
			free(params);
			return returnVal;
		}
		void DestroyOverLimit()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCallIn_Support.DestroyOverLimit");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
