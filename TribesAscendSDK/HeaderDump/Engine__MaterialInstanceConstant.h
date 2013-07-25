#pragma once
#include "Engine__MaterialInterface.h"
#include "Engine__MaterialInstance.h"
#include "Engine__Font.h"
#include "Engine__Texture.h"
namespace UnrealScript
{
	class MaterialInstanceConstant : public MaterialInstance
	{
	public:
		void SetParent(class MaterialInterface* NewParent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.MaterialInstanceConstant.SetParent");
			byte* params = (byte*)malloc(4);
			*(class MaterialInterface**)params = NewParent;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetScalarParameterValue(ScriptName ParameterName, float Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.MaterialInstanceConstant.SetScalarParameterValue");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = ParameterName;
			*(float*)(params + 8) = Value;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetTextureParameterValue(ScriptName ParameterName, class Texture* Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.MaterialInstanceConstant.SetTextureParameterValue");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = ParameterName;
			*(class Texture**)(params + 8) = Value;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetVectorParameterValue(ScriptName ParameterName, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor'!
void*& Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.MaterialInstanceConstant.SetVectorParameterValue");
			byte* params = (byte*)malloc(24);
			*(ScriptName*)params = ParameterName;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor'!
void**)(params + 8) = Value;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Value = *(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor'!
void**)(params + 8);
			free(params);
		}
		void SetFontParameterValue(ScriptName ParameterName, class Font* FontValue, int FontPage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.MaterialInstanceConstant.SetFontParameterValue");
			byte* params = (byte*)malloc(16);
			*(ScriptName*)params = ParameterName;
			*(class Font**)(params + 8) = FontValue;
			*(int*)(params + 12) = FontPage;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearParameterValues()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.MaterialInstanceConstant.ClearParameterValues");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
