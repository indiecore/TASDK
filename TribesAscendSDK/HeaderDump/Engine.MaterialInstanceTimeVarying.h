#pragma once
#include "Engine.MaterialInstance.h"
#include "Engine.MaterialInterface.h"
#include "Core.Object.h"
#include "Engine.Texture.h"
#include "Engine.Font.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
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
	class MaterialInstanceTimeVarying : public MaterialInstance
	{
	public:
		struct ParameterValueOverTime
		{
		public:
			ADD_BOOL(bOffsetFromEnd, 44, 0x1)
			ADD_STRUCT(float, OffsetTime, 40)
			ADD_BOOL(bNormalizeTime, 36, 0x1)
			ADD_STRUCT(float, CycleTime, 32)
			ADD_BOOL(bAutoActivate, 28, 0x2)
			ADD_BOOL(bLoop, 28, 0x1)
			ADD_STRUCT(ScriptName, ParameterName, 20)
			ADD_STRUCT(float, StartTime, 16)
			ADD_STRUCT(Object::Guid, ExpressionGUID, 0)
		};
		struct FontParameterValueOverTime : public ParameterValueOverTime
		{
		public:
			ADD_STRUCT(int, FontPage, 52)
			ADD_OBJECT(Font, FontValue, 48)
		};
		struct ScalarParameterValueOverTime : public ParameterValueOverTime
		{
		public:
			ADD_STRUCT(Object::InterpCurveFloat, ParameterValueCurve, 52)
			ADD_STRUCT(float, ParameterValue, 48)
		};
		struct TextureParameterValueOverTime : public ParameterValueOverTime
		{
		public:
			ADD_OBJECT(Texture, ParameterValue, 48)
		};
		struct VectorParameterValueOverTime : public ParameterValueOverTime
		{
		public:
			ADD_STRUCT(Object::InterpCurveVector, ParameterValueCurve, 64)
			ADD_STRUCT(Object::LinearColor, ParameterValue, 48)
		};
		ADD_STRUCT(ScriptArray<MaterialInstanceTimeVarying::FontParameterValueOverTime>, FontParameterValues, 440)
		ADD_STRUCT(ScriptArray<MaterialInstanceTimeVarying::ScalarParameterValueOverTime>, ScalarParameterValues, 452)
		ADD_STRUCT(ScriptArray<MaterialInstanceTimeVarying::TextureParameterValueOverTime>, TextureParameterValues, 464)
		ADD_STRUCT(ScriptArray<MaterialInstanceTimeVarying::VectorParameterValueOverTime>, VectorParameterValues, 476)
		ADD_STRUCT(float, Duration, 436)
		ADD_BOOL(bAutoActivateAll, 432, 0x1)
		void SetParent(class MaterialInterface* NewParent)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19883);
			byte params[4] = { NULL };
			*(class MaterialInterface**)params = NewParent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetScalarParameterValue(ScriptName ParameterName, float Value)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19885);
			byte params[12] = { NULL };
			*(ScriptName*)params = ParameterName;
			*(float*)&params[8] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetScalarCurveParameterValue(ScriptName ParameterName, Object::InterpCurveFloat& Value)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19888);
			byte params[24] = { NULL };
			*(ScriptName*)params = ParameterName;
			*(Object::InterpCurveFloat*)&params[8] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Value = *(Object::InterpCurveFloat*)&params[8];
		}
		void SetScalarStartTime(ScriptName ParameterName, float Value)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19891);
			byte params[12] = { NULL };
			*(ScriptName*)params = ParameterName;
			*(float*)&params[8] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetDuration(float Value)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19894);
			byte params[4] = { NULL };
			*(float*)params = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetTextureParameterValue(ScriptName ParameterName, class Texture* Value)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19896);
			byte params[12] = { NULL };
			*(ScriptName*)params = ParameterName;
			*(class Texture**)&params[8] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetVectorParameterValue(ScriptName ParameterName, Object::LinearColor& Value)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19899);
			byte params[24] = { NULL };
			*(ScriptName*)params = ParameterName;
			*(Object::LinearColor*)&params[8] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Value = *(Object::LinearColor*)&params[8];
		}
		void SetVectorCurveParameterValue(ScriptName ParameterName, Object::InterpCurveVector& Value)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19902);
			byte params[24] = { NULL };
			*(ScriptName*)params = ParameterName;
			*(Object::InterpCurveVector*)&params[8] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Value = *(Object::InterpCurveVector*)&params[8];
		}
		void SetVectorStartTime(ScriptName ParameterName, float Value)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19905);
			byte params[12] = { NULL };
			*(ScriptName*)params = ParameterName;
			*(float*)&params[8] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetFontParameterValue(ScriptName ParameterName, class Font* FontValue, int FontPage)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19908);
			byte params[16] = { NULL };
			*(ScriptName*)params = ParameterName;
			*(class Font**)&params[8] = FontValue;
			*(int*)&params[12] = FontPage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearParameterValues()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19912);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		float GetMaxDurationFromAllParameters()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19913);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
