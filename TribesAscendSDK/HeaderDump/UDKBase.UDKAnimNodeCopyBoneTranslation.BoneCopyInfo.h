#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKAnimNodeCopyBoneTranslation.BoneCopyInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class BoneCopyInfo
	{
	public:
		ADD_VAR(::IntProperty, DstBoneIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SrcBoneIndex, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, DstBoneName, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, SrcBoneName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
