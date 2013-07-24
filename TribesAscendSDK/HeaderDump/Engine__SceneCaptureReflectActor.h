#pragma once
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.SceneCaptureReflectActor." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SceneCaptureReflectActor : public SceneCaptureActor
	{
	public:
		ADD_OBJECT(MaterialInstanceConstant, ReflectMaterialInst)
	};
}
#undef ADD_OBJECT
