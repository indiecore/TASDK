#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.LensFlareSource." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class LensFlareSource : public Actor
	{
	public:
		ADD_VAR(::BoolProperty, bCurrentlyActive, 0x1)
	};
}
#undef ADD_VAR
