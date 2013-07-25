#pragma once
#include "Engine__InterpTrackInst.h"
#include "Engine__InterpTrackFloatMaterialParam.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.InterpTrackInstFloatMaterialParam." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class InterpTrackInstFloatMaterialParam : public InterpTrackInst
	{
	public:
		ADD_OBJECT(InterpTrackFloatMaterialParam, InstancedTrack)
	};
}
#undef ADD_OBJECT
