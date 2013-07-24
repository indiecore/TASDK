#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.AnimSet." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class AnimSet : public Object
	{
	public:
		ADD_VAR(::NameProperty, BestRatioSkelMeshName, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, PreviewSkelMeshName, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bAnimRotationOnly, 0x1)
	};
}
#undef ADD_VAR
