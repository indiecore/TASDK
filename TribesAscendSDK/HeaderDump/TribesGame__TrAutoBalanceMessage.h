#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrAutoBalanceMessage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrAutoBalanceMessage : public UTLocalMessage
	{
	public:
		ADD_VAR(::StrProperty, TeamsAutoBalanced, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, AutoBalanceInFive, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, AutoBalanceInTwenty, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
