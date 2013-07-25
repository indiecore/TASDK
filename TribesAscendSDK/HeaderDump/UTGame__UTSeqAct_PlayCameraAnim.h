#pragma once
#include "Engine__SequenceAction.h"
#include "Engine__CameraAnim.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTSeqAct_PlayCameraAnim." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTSeqAct_PlayCameraAnim." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTSeqAct_PlayCameraAnim : public SequenceAction
	{
	public:
		ADD_OBJECT(CameraAnim, AnimToPlay)
		ADD_VAR(::FloatProperty, IntensityScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Rate, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BlendInTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BlendOutTime, 0xFFFFFFFF)
		int GetObjClassVersion()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSeqAct_PlayCameraAnim.GetObjClassVersion");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
