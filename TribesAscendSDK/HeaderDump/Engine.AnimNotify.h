#pragma once
#include "Engine.AnimSequence.AnimNotifyEvent.h"
#include "Core.Object.h"
#include "Engine.AnimNodeSequence.h"
#include "Core.Object.Color.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.AnimNotify." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class AnimNotify : public Object
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<Color>, NotifyColor, 0xFFFFFFFF)
		bool FindNextNotifyOfClass(class AnimNodeSequence* AnimSeqInstigator, ScriptClass* NotifyClass, AnimNotifyEvent& OutEvent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNotify.FindNextNotifyOfClass");
			byte* params = (byte*)malloc(32);
			*(class AnimNodeSequence**)params = AnimSeqInstigator;
			*(ScriptClass**)(params + 4) = NotifyClass;
			*(AnimNotifyEvent*)(params + 8) = OutEvent;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			OutEvent = *(AnimNotifyEvent*)(params + 8);
			auto returnVal = *(bool*)(params + 28);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_STRUCT
