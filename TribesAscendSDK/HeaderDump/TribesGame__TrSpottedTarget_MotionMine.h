#pragma once
#include "TribesGame__TrSpottedTarget.h"
#include "Engine__Texture2D.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrSpottedTarget_MotionMine." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrSpottedTarget_MotionMine : public TrSpottedTarget
	{
	public:
		ADD_VAR(::FloatProperty, m_fMarkerBlinkSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fCurrentMarkerTime, 0xFFFFFFFF)
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSpottedTarget_MotionMine.Tick");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class Texture2D* GetMarker()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSpottedTarget_MotionMine.GetMarker");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Texture2D**)params;
			free(params);
			return returnVal;
		}
		
// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor'!
void* GetMarkerColor()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSpottedTarget_MotionMine.GetMarkerColor");
			byte* params = (byte*)malloc(16);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor'!
void**)params;
			free(params);
			return returnVal;
		}
		bool ShouldRenderMarker()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSpottedTarget_MotionMine.ShouldRenderMarker");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
