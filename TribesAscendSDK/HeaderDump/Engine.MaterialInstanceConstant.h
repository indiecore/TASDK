#pragma once
#include "Engine.MaterialInstance.h"
#include "Engine.MaterialInterface.h"
#include "Engine.Texture.h"
#include "Core.Object.h"
#include "Engine.Font.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class MaterialInstanceConstant : public MaterialInstance
	{
	public:
		class FontParameterValue
		{
		public:
			ADD_STRUCT(Object::Guid, ExpressionGUID, 16)
			ADD_STRUCT(int, FontPage, 12)
			ADD_OBJECT(Font, FontValue, 8)
			ADD_STRUCT(ScriptName, ParameterName, 0)
		};
		class ScalarParameterValue
		{
		public:
			ADD_STRUCT(Object::Guid, ExpressionGUID, 12)
			ADD_STRUCT(float, ParameterValue, 8)
			ADD_STRUCT(ScriptName, ParameterName, 0)
		};
		class TextureParameterValue
		{
		public:
			ADD_STRUCT(Object::Guid, ExpressionGUID, 12)
			ADD_OBJECT(Texture, ParameterValue, 8)
			ADD_STRUCT(ScriptName, ParameterName, 0)
		};
		class VectorParameterValue
		{
		public:
			ADD_STRUCT(Object::Guid, ExpressionGUID, 24)
			ADD_STRUCT(Object::LinearColor, ParameterValue, 8)
			ADD_STRUCT(ScriptName, ParameterName, 0)
		};
		ADD_STRUCT(ScriptArray<MaterialInstanceConstant::FontParameterValue>, FontParameterValues, 432)
		ADD_STRUCT(ScriptArray<MaterialInstanceConstant::ScalarParameterValue>, ScalarParameterValues, 444)
		ADD_STRUCT(ScriptArray<MaterialInstanceConstant::TextureParameterValue>, TextureParameterValues, 456)
		ADD_STRUCT(ScriptArray<MaterialInstanceConstant::VectorParameterValue>, VectorParameterValues, 468)
		void SetParent(class MaterialInterface* NewParent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.MaterialInstanceConstant.SetParent");
			byte params[4] = { NULL };
			*(class MaterialInterface**)&params[0] = NewParent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetScalarParameterValue(ScriptName ParameterName, float Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.MaterialInstanceConstant.SetScalarParameterValue");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = ParameterName;
			*(float*)&params[8] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetTextureParameterValue(ScriptName ParameterName, class Texture* Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.MaterialInstanceConstant.SetTextureParameterValue");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = ParameterName;
			*(class Texture**)&params[8] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetVectorParameterValue(ScriptName ParameterName, Object::LinearColor& Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.MaterialInstanceConstant.SetVectorParameterValue");
			byte params[24] = { NULL };
			*(ScriptName*)&params[0] = ParameterName;
			*(Object::LinearColor*)&params[8] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Value = *(Object::LinearColor*)&params[8];
		}
		void SetFontParameterValue(ScriptName ParameterName, class Font* FontValue, int FontPage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.MaterialInstanceConstant.SetFontParameterValue");
			byte params[16] = { NULL };
			*(ScriptName*)&params[0] = ParameterName;
			*(class Font**)&params[8] = FontValue;
			*(int*)&params[12] = FontPage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearParameterValues()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.MaterialInstanceConstant.ClearParameterValues");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
