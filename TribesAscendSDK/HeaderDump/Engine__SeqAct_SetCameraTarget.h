#pragma once
#include "Engine__SequenceAction.h"
#include "Engine__Actor.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.SeqAct_SetCameraTarget." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.SeqAct_SetCameraTarget." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SeqAct_SetCameraTarget : public SequenceAction
	{
	public:
		ADD_OBJECT(Actor, CameraTarget)
		// WARNING: Unknown structure type 'ScriptStruct Engine.Camera.ViewTargetTransitionParams' for the property named 'TransitionParams'!
		// Here lies the not-yet-implemented method 'GetObjClassVersion'
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
