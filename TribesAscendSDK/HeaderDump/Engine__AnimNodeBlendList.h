#pragma once
#include "Engine__AnimNodeBlendBase.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.AnimNodeBlendList." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class AnimNodeBlendList : public AnimNodeBlendBase
	{
	public:
		ADD_VAR(::IntProperty, EditorActiveChildIndex, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SliderPosition, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bSkipBlendWhenNotRendered, 0x4)
		ADD_VAR(::BoolProperty, bForceChildFullWeightWhenBecomingRelevant, 0x2)
		ADD_VAR(::BoolProperty, bPlayActiveChild, 0x1)
		ADD_VAR(::IntProperty, ActiveChildIndex, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BlendTimeToGo, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'SetActiveChild'
	};
}
#undef ADD_VAR
