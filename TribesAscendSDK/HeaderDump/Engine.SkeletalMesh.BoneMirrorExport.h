#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " SkeletalMesh.BoneMirrorExport." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class BoneMirrorExport
	{
	public:
		ADD_VAR(::NameProperty, BoneName, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, SourceBoneName, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, BoneFlipAxis, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
