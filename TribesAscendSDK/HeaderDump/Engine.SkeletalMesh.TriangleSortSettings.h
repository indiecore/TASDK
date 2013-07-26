#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " SkeletalMesh.TriangleSortSettings." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TriangleSortSettings
	{
	public:
		ADD_VAR(::ByteProperty, TriangleSorting, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, CustomLeftRightAxis, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, CustomLeftRightBoneName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
