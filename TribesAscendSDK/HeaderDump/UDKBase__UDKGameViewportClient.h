#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKGameViewportClient." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UDKGameViewportClient : public GameViewportClient
	{
	public:
		ADD_VAR(::StrProperty, HintLocFileName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
