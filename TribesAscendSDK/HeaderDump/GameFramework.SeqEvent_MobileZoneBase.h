#pragma once
#include "GameFramework.SeqEvent_MobileBase.h"
#include "GameFramework.MobilePlayerInput.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.SeqEvent_MobileZoneBase." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqEvent_MobileZoneBase : public SeqEvent_MobileBase
	{
	public:
		ADD_VAR(::StrProperty, TargetZoneName, 0xFFFFFFFF)
		void AddToMobileInput(class MobilePlayerInput* MPI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.SeqEvent_MobileZoneBase.AddToMobileInput");
			byte* params = (byte*)malloc(4);
			*(class MobilePlayerInput**)params = MPI;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
