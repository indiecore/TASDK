#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TgStructures.CombatMessageInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class CombatMessageInfo
	{
	public:
		ADD_VAR(::IntProperty, nSourceItemId, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, nAmount2, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, nAmount1, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, eTargetType, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, nTargetId, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, nSourceOwnerId, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, eSourceType, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, nSourceId, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, nMsgId, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
