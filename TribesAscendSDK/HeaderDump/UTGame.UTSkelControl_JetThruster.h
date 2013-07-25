#pragma once
#include "Engine.SkelControlSingleBone.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTSkelControl_JetThruster." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UTSkelControl_JetThruster : public SkelControlSingleBone
	{
	public:
		ADD_VAR(::FloatProperty, DesiredStrength, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BlendRate, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxForwardVelocity, 0xFFFFFFFF)
		void TickSkelControl(float DeltaTime, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelComp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSkelControl_JetThruster.TickSkelControl");
			byte* params = (byte*)malloc(8);
			*(float*)params = DeltaTime;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)(params + 4) = SkelComp;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
