#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrKillerMessage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrKillerMessage : public UTLocalMessage
	{
	public:
		ADD_VAR(::StrProperty, KillCreditFor, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, YouKilled, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
