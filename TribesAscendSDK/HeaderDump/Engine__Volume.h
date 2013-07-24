#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.Volume." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.Volume." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class Volume : public Brush
	{
	public:
		ADD_VAR(::BoolProperty, bProcessAllActors, 0x2)
		ADD_VAR(::BoolProperty, bForcePawnWalk, 0x1)
		ADD_OBJECT(Actor, AssociatedActor)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
