#pragma once
#include "Core.Object.h"
#include "Engine.AnimNodeSequence.h"
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
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'NotifyColor'!
		bool FindNextNotifyOfClass(class AnimNodeSequence* AnimSeqInstigator, ScriptClass* NotifyClass, 
// WARNING: Unknown structure type 'ScriptStruct Engine.AnimSequence.AnimNotifyEvent'!
void*& OutEvent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNotify.FindNextNotifyOfClass");
			byte* params = (byte*)malloc(32);
			*(class AnimNodeSequence**)params = AnimSeqInstigator;
			*(ScriptClass**)(params + 4) = NotifyClass;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.AnimSequence.AnimNotifyEvent'!
void**)(params + 8) = OutEvent;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			OutEvent = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.AnimSequence.AnimNotifyEvent'!
void**)(params + 8);
			auto returnVal = *(bool*)(params + 28);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_STRUCT
