#pragma once
#include "Engine.AnimNotify_Sound.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrAnimNotify_Sound." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrAnimNotify_Sound : public AnimNotify_Sound
	{
	public:
		ADD_OBJECT(ScriptClass, m_PreviewDeviceClass)
	};
}
#undef ADD_OBJECT
