#pragma once
#include "Engine.SequenceAction.h"
#include "Core.Object.Vector2D.h"
#include "Core.Object.Color.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqAct_CameraFade." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.SeqAct_CameraFade." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqAct_CameraFade : public SequenceAction
	{
	public:
		ADD_VAR(::FloatProperty, FadeTimeRemaining, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bPersistFade, 0x1)
		ADD_VAR(::FloatProperty, FadeTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FadeOpacity, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Vector2D>, FadeAlpha, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Color>, FadeColor, 0xFFFFFFFF)
		int GetObjClassVersion()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SeqAct_CameraFade.GetObjClassVersion");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
