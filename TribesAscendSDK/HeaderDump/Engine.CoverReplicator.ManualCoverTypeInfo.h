#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " CoverReplicator.ManualCoverTypeInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ManualCoverTypeInfo
	{
	public:
		ADD_VAR(::ByteProperty, ManualCoverType, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, SlotIndex, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
