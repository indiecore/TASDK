#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.Emitter." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class Emitter : public Actor
	{
	public:
		ADD_VAR(::BoolProperty, bCurrentlyActive, 0x4)
		ADD_VAR(::BoolProperty, bPostUpdateTickGroup, 0x2)
		ADD_VAR(::BoolProperty, bDestroyOnSystemFinish, 0x1)
	};
}
#undef ADD_VAR
