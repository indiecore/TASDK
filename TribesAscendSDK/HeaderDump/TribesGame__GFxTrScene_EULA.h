#pragma once
#include "TribesGame__GFxTrScene.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrScene_EULA." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GFxTrScene_EULA : public GFxTrScene
	{
	public:
		ADD_VAR(::StrProperty, EULA, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'LoadEULA'
		// Here lies the not-yet-implemented method 'AcceptEULA'
		// Here lies the not-yet-implemented method 'Initialize'
		// Here lies the not-yet-implemented method 'EULAReponse'
	};
}
#undef ADD_VAR
