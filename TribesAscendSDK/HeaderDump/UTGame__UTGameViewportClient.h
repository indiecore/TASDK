#pragma once
#include "UDKBase__UDKGameViewportClient.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTGameViewportClient." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTGameViewportClient." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTGameViewportClient : public UDKGameViewportClient
	{
	public:
		ADD_VAR(::StrProperty, LevelActionMessages, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ProgressMessageSceneClassName, 0xFFFFFFFF)
		ADD_OBJECT(Font, LoadingScreenHintMessageFont)
		ADD_OBJECT(Font, LoadingScreenGameTypeNameFont)
		ADD_OBJECT(Font, LoadingScreenMapNameFont)
		ADD_VAR(::StrProperty, UTFrontEndString, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
