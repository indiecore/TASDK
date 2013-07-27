#pragma once
#include "Engine.SequenceAction.h"
#include "Engine.CameraAnim.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class UTSeqAct_PlayCameraAnim : public SequenceAction
	{
	public:
		ADD_OBJECT(CameraAnim, AnimToPlay, 232)
		ADD_STRUCT(float, IntensityScale, 248)
		ADD_STRUCT(float, Rate, 244)
		ADD_STRUCT(float, BlendInTime, 236)
		ADD_STRUCT(float, BlendOutTime, 240)
		int GetObjClassVersion()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSeqAct_PlayCameraAnim.GetObjClassVersion");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
