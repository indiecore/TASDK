#pragma once
#include "Engine__MaterialInterface.h"
#include "Engine__MaterialInstance.h"
#include "Engine__Font.h"
#include "Engine__Texture.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.MaterialInstanceTimeVarying." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class MaterialInstanceTimeVarying : public MaterialInstance
	{
	public:
		ADD_VAR(::FloatProperty, Duration, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bAutoActivateAll, 0x1)
		// Here lies the not-yet-implemented method 'SetParent'
		// Here lies the not-yet-implemented method 'SetScalarParameterValue'
		// Here lies the not-yet-implemented method 'SetScalarCurveParameterValue'
		// Here lies the not-yet-implemented method 'SetScalarStartTime'
		// Here lies the not-yet-implemented method 'SetDuration'
		// Here lies the not-yet-implemented method 'SetTextureParameterValue'
		// Here lies the not-yet-implemented method 'SetVectorParameterValue'
		// Here lies the not-yet-implemented method 'SetVectorCurveParameterValue'
		// Here lies the not-yet-implemented method 'SetVectorStartTime'
		// Here lies the not-yet-implemented method 'SetFontParameterValue'
		// Here lies the not-yet-implemented method 'ClearParameterValues'
		// Here lies the not-yet-implemented method 'GetMaxDurationFromAllParameters'
	};
}
#undef ADD_VAR
