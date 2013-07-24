#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKAnimNodeCopyBoneTranslation." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UDKBase.UDKAnimNodeCopyBoneTranslation." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UDKAnimNodeCopyBoneTranslation : public AnimNodeBlendBase
	{
	public:
		ADD_VAR(::NameProperty, OldAimProfileName, 0xFFFFFFFF)
		ADD_OBJECT(AnimNodeAimOffset, CachedAimNode)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
