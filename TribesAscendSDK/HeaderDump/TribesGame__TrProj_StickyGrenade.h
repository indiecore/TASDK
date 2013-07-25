#pragma once
#include "Engine__Actor.h"
#include "TribesGame__TrProj_Grenade.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrProj_StickyGrenade." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrProj_StickyGrenade." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrProj_StickyGrenade : public TrProj_Grenade
	{
	public:
		ADD_OBJECT(Actor, m_OldBase)
		ADD_VAR(::BoolProperty, m_bHasStuckToTarget, 0x1)
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'HitWall'
		// Here lies the not-yet-implemented method 'ProcessTouch'
		// Here lies the not-yet-implemented method 'StickToTarget'
		// Here lies the not-yet-implemented method 'OnBaseChanged'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
