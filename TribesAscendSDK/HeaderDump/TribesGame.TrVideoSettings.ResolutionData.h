#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TrVideoSettings.ResolutionData." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ResolutionData
	{
	public:
		ADD_VAR(::IntProperty, ResY, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ResX, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
