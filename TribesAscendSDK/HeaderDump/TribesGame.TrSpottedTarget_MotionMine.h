#pragma once
#include "TribesGame.TrSpottedTarget.h"
#include "Engine.Texture2D.h"
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class TrSpottedTarget_MotionMine : public TrSpottedTarget
	{
	public:
		ADD_STRUCT(float, m_fMarkerBlinkSpeed, 516)
		ADD_STRUCT(float, m_fCurrentMarkerTime, 512)
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112580);
			byte params[4] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class Texture2D* GetMarker()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112582);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Texture2D**)params;
		}
		Object::LinearColor GetMarkerColor()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112584);
			byte params[16] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::LinearColor*)params;
		}
		bool ShouldRenderMarker()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112586);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
	};
}
#undef ADD_STRUCT
