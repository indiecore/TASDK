#pragma once
#include "Core.Object.h"
#include "Engine.FontImportOptions.FontImportOptionsData.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.Font." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.Font." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class Font : public Object
	{
	public:
		ADD_VAR(::IntProperty, NumCharacters, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<FontImportOptionsData>, ImportOptions, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Kerning, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Leading, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Descent, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Ascent, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, EmScale, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, IsRemapped, 0xFFFFFFFF)
		int GetResolutionPageIndex(float HeightTest)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Font.GetResolutionPageIndex");
			byte* params = (byte*)malloc(8);
			*(float*)params = HeightTest;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		float GetScalingFactor(float HeightTest)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Font.GetScalingFactor");
			byte* params = (byte*)malloc(8);
			*(float*)params = HeightTest;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 4);
			free(params);
			return returnVal;
		}
		float GetAuthoredViewportHeight(float ViewportHeight)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Font.GetAuthoredViewportHeight");
			byte* params = (byte*)malloc(8);
			*(float*)params = ViewportHeight;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 4);
			free(params);
			return returnVal;
		}
		float GetMaxCharHeight()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Font.GetMaxCharHeight");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		void GetStringHeightAndWidth(ScriptArray<wchar_t>& InString, int& Height, int& Width)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Font.GetStringHeightAndWidth");
			byte* params = (byte*)malloc(20);
			*(ScriptArray<wchar_t>*)params = InString;
			*(int*)(params + 12) = Height;
			*(int*)(params + 16) = Width;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			InString = *(ScriptArray<wchar_t>*)params;
			Height = *(int*)(params + 12);
			Width = *(int*)(params + 16);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
