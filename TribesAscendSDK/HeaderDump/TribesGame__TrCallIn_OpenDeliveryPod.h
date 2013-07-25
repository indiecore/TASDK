#pragma once
#include "Engine__Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrCallIn_OpenDeliveryPod." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrCallIn_OpenDeliveryPod." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrCallIn_OpenDeliveryPod : public Actor
	{
	public:
		ADD_OBJECT(MaterialInstanceTimeVarying, PodFadeMaterial)
		ADD_VAR(::FloatProperty, TimeToFade, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TimeToDelete, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
