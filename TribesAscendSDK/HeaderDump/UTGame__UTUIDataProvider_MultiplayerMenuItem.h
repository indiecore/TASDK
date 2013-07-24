#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTUIDataProvider_MultiplayerMenuItem." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UTUIDataProvider_MultiplayerMenuItem : public UTUIResourceDataProvider
	{
	public:
		ADD_VAR(::BoolProperty, bRequiresOnlineAccess, 0x1)
		ADD_VAR(::StrProperty, Description, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
