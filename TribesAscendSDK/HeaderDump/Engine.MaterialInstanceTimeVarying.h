#pragma once
#include "Engine.MaterialInstance.h"
#include "Core.Object.InterpCurveVector.h"
#include "Engine.MaterialInterface.h"
#include "Engine.Texture.h"
#include "Core.Object.InterpCurveFloat.h"
#include "Core.Object.LinearColor.h"
#include "Engine.Font.h"
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
		void SetParent(class MaterialInterface* NewParent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.MaterialInstanceTimeVarying.SetParent");
			byte* params = (byte*)malloc(4);
			*(class MaterialInterface**)params = NewParent;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetScalarParameterValue(ScriptName ParameterName, float Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.MaterialInstanceTimeVarying.SetScalarParameterValue");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = ParameterName;
			*(float*)(params + 8) = Value;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetScalarCurveParameterValue(ScriptName ParameterName, InterpCurveFloat& Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.MaterialInstanceTimeVarying.SetScalarCurveParameterValue");
			byte* params = (byte*)malloc(24);
			*(ScriptName*)params = ParameterName;
			*(InterpCurveFloat*)(params + 8) = Value;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Value = *(InterpCurveFloat*)(params + 8);
			free(params);
		}
		void SetScalarStartTime(ScriptName ParameterName, float Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.MaterialInstanceTimeVarying.SetScalarStartTime");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = ParameterName;
			*(float*)(params + 8) = Value;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetDuration(float Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.MaterialInstanceTimeVarying.SetDuration");
			byte* params = (byte*)malloc(4);
			*(float*)params = Value;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetTextureParameterValue(ScriptName ParameterName, class Texture* Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.MaterialInstanceTimeVarying.SetTextureParameterValue");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = ParameterName;
			*(class Texture**)(params + 8) = Value;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetVectorParameterValue(ScriptName ParameterName, LinearColor& Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.MaterialInstanceTimeVarying.SetVectorParameterValue");
			byte* params = (byte*)malloc(24);
			*(ScriptName*)params = ParameterName;
			*(LinearColor*)(params + 8) = Value;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Value = *(LinearColor*)(params + 8);
			free(params);
		}
		void SetVectorCurveParameterValue(ScriptName ParameterName, InterpCurveVector& Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.MaterialInstanceTimeVarying.SetVectorCurveParameterValue");
			byte* params = (byte*)malloc(24);
			*(ScriptName*)params = ParameterName;
			*(InterpCurveVector*)(params + 8) = Value;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Value = *(InterpCurveVector*)(params + 8);
			free(params);
		}
		void SetVectorStartTime(ScriptName ParameterName, float Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.MaterialInstanceTimeVarying.SetVectorStartTime");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = ParameterName;
			*(float*)(params + 8) = Value;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetFontParameterValue(ScriptName ParameterName, class Font* FontValue, int FontPage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.MaterialInstanceTimeVarying.SetFontParameterValue");
			byte* params = (byte*)malloc(16);
			*(ScriptName*)params = ParameterName;
			*(class Font**)(params + 8) = FontValue;
			*(int*)(params + 12) = FontPage;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearParameterValues()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.MaterialInstanceTimeVarying.ClearParameterValues");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		float GetMaxDurationFromAllParameters()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.MaterialInstanceTimeVarying.GetMaxDurationFromAllParameters");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
