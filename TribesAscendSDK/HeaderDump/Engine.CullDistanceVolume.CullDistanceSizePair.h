#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " CullDistanceVolume.CullDistanceSizePair." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class CullDistanceSizePair
	{
	public:
		ADD_VAR(::FloatProperty, CullDistance, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Size, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
