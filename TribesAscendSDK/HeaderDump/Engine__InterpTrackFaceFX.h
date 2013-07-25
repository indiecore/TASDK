#pragma once
#include "Engine__InterpTrack.h"
#include "Engine__FaceFXAsset.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.InterpTrackFaceFX." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class InterpTrackFaceFX : public InterpTrack
	{
	public:
		ADD_OBJECT(FaceFXAsset, CachedActorFXAsset)
	};
}
#undef ADD_OBJECT
