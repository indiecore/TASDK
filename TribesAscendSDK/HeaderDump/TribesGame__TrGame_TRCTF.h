#pragma once
#include "TribesGame__TrGame.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrGame_TRCTF." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrGame_TRCTF : public TrGame
	{
	public:
		ADD_OBJECT(TrFlagCTF, m_Flags)
	};
}
#undef ADD_OBJECT
