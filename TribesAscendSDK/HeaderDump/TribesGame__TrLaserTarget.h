#pragma once
#include "Engine__Actor.h"
#include "Engine__Canvas.h"
#include "Engine__PlayerController.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrLaserTarget." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrLaserTarget : public Actor
	{
	public:
		ADD_VAR(::ByteProperty, m_nTeamId, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'SetTeamNum'
		// Here lies the not-yet-implemented method 'GetTeamNum'
		// Here lies the not-yet-implemented method 'UpdateLocation'
		// Here lies the not-yet-implemented method 'Destroyed'
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'PostRenderFor'
		// Here lies the not-yet-implemented method 'RenderForOwner'
		// Here lies the not-yet-implemented method 'RenderForTeammate'
	};
}
#undef ADD_VAR
