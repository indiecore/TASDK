#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrJammerMessage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrJammerMessage : public UTLocalMessage
	{
	public:
		ADD_VAR(::StrProperty, JammedByEnemyJammerPack, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, JammingViaOtherDropJammer, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, JammedByEnemyDropJammer, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, JammingForOther, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, JammingViaOther, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
