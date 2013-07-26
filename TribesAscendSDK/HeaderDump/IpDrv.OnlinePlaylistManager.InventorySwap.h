#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " OnlinePlaylistManager.InventorySwap." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class InventorySwap
	{
	public:
		ADD_VAR(::StrProperty, SwapTo, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, Original, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
