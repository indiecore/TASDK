#pragma once
#include "TribesGame__TrProj_StickyGrenade.h"
#include "Engine__Controller.h"
#include "Engine__Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrProj_RemoteArxBuster." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrProj_RemoteArxBuster : public TrProj_StickyGrenade
	{
	public:
		ADD_VAR(::BoolProperty, m_bIsDetonating, 0x1)
		// Here lies the not-yet-implemented method 'PreBeginPlay'
		// Here lies the not-yet-implemented method 'TakeRadiusDamage'
		// Here lies the not-yet-implemented method 'TakeDamage'
		// Here lies the not-yet-implemented method 'ReportDestroyedByOtherToParentDevice'
		// Here lies the not-yet-implemented method 'StickToTarget'
		// Here lies the not-yet-implemented method 'Destroyed'
	};
}
#undef ADD_VAR
