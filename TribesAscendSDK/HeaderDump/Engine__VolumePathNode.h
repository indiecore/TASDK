#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.VolumePathNode." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class VolumePathNode : public PathNode
	{
	public:
		ADD_VAR(::FloatProperty, StartingHeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, StartingRadius, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
