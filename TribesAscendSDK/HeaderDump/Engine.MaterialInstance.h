#pragma once
#include "Core.Object.Guid.h"
#include "Engine.MaterialInterface.h"
#include "Core.Object.Pointer.h"
#include "Engine.Texture2D.h"
#include "Engine.Font.h"
#include "Engine.Texture.h"
#include "Core.Object.InterpCurveFloat.h"
#include "Engine.PhysicalMaterial.h"
#include "Core.Object.LinearColor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.MaterialInstance." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.MaterialInstance." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.MaterialInstance." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class MaterialInstance : public MaterialInterface
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<Guid>, ParentLightingGuid, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, Resources, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, StaticPermutationResources, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, StaticParameters, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bNeedsMaterialFlattening, 0x8)
		ADD_VAR(::BoolProperty, ReentrantFlag, 0x4)
		ADD_VAR(::BoolProperty, bStaticPermutationDirty, 0x2)
		ADD_VAR(::BoolProperty, bHasStaticPermutationResource, 0x1)
		ADD_OBJECT(PhysicalMaterial, WhitePhysicalMaterial)
		ADD_OBJECT(PhysicalMaterial, BlackPhysicalMaterial)
		ADD_VAR(::IntProperty, PhysMaterialMaskUVChannel, 0xFFFFFFFF)
		ADD_OBJECT(Texture2D, PhysMaterialMask)
		ADD_OBJECT(MaterialInterface, Parent)
		ADD_OBJECT(PhysicalMaterial, PhysMaterial)
		void SetParent(class MaterialInterface* NewParent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.MaterialInstance.SetParent");
			byte* params = (byte*)malloc(4);
			*(class MaterialInterface**)params = NewParent;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetVectorParameterValue(ScriptName ParameterName, LinearColor& Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.MaterialInstance.SetVectorParameterValue");
			byte* params = (byte*)malloc(24);
			*(ScriptName*)params = ParameterName;
			*(LinearColor*)(params + 8) = Value;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Value = *(LinearColor*)(params + 8);
			free(params);
		}
		void SetScalarParameterValue(ScriptName ParameterName, float Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.MaterialInstance.SetScalarParameterValue");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = ParameterName;
			*(float*)(params + 8) = Value;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetScalarCurveParameterValue(ScriptName ParameterName, InterpCurveFloat& Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.MaterialInstance.SetScalarCurveParameterValue");
			byte* params = (byte*)malloc(24);
			*(ScriptName*)params = ParameterName;
			*(InterpCurveFloat*)(params + 8) = Value;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Value = *(InterpCurveFloat*)(params + 8);
			free(params);
		}
		void SetTextureParameterValue(ScriptName ParameterName, class Texture* Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.MaterialInstance.SetTextureParameterValue");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = ParameterName;
			*(class Texture**)(params + 8) = Value;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetFontParameterValue(ScriptName ParameterName, class Font* FontValue, int FontPage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.MaterialInstance.SetFontParameterValue");
			byte* params = (byte*)malloc(16);
			*(ScriptName*)params = ParameterName;
			*(class Font**)(params + 8) = FontValue;
			*(int*)(params + 12) = FontPage;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearParameterValues()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.MaterialInstance.ClearParameterValues");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool IsInMapOrTransientPackage()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.MaterialInstance.IsInMapOrTransientPackage");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
