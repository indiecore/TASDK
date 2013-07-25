#pragma once
#include "TribesGame__TrSpottedTarget.h"
#include "Engine__Texture2D.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrSpottedTarget_MotionMine." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrSpottedTarget_MotionMine : public TrSpottedTarget
	{
	public:
		ADD_VAR(::FloatProperty, m_fMarkerBlinkSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fCurrentMarkerTime, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'Tick'
		// Here lies the not-yet-implemented method 'GetMarker'
		// Here lies the not-yet-implemented method 'GetMarkerColor'
		// Here lies the not-yet-implemented method 'ShouldRenderMarker'
	};
}
#undef ADD_VAR
