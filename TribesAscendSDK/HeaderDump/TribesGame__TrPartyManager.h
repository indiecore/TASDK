#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrPartyManager." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrPartyManager : public Object
	{
	public:
		ADD_VAR(::BoolProperty, bCreatedParty, 0x1)
		ADD_VAR(::StrProperty, InvitingPlayer, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
