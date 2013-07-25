#pragma once
#include "TribesGame__TrHUD.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrHUDTeam." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrHUDTeam : public TrHUD
	{
	public:
		ADD_VAR(::IntProperty, m_nLastMessageCode, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'Timer'
	};
}
#undef ADD_VAR
