#pragma once
#include "Engine.PostProcessEffect.h"
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class PostProcessChain : public Object
	{
	public:
		ADD_STRUCT(ScriptArray<class PostProcessEffect*>, Effects, 60)
		class PostProcessEffect* FindPostProcessEffect(ScriptName EffectName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24747);
			byte params[12] = { NULL };
			*(ScriptName*)params = EffectName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class PostProcessEffect**)&params[8];
		}
	};
}
#undef ADD_STRUCT
