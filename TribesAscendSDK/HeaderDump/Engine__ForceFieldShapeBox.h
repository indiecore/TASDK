#pragma once
#include "Engine__ForceFieldShape.h"
namespace UnrealScript
{
	class ForceFieldShapeBox : public ForceFieldShape
	{
	public:
		Vector GetRadii()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ForceFieldShapeBox.GetRadii");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)params;
			free(params);
			return returnVal;
		}
		void FillBySphere(float Radius)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ForceFieldShapeBox.FillBySphere");
			byte* params = (byte*)malloc(4);
			*(float*)params = Radius;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void FillByBox(Vector Extent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ForceFieldShapeBox.FillByBox");
			byte* params = (byte*)malloc(12);
			*(Vector*)params = Extent;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void FillByCapsule(float Height, float Radius)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ForceFieldShapeBox.FillByCapsule");
			byte* params = (byte*)malloc(8);
			*(float*)params = Height;
			*(float*)(params + 4) = Radius;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void FillByCylinder(float BottomRadius, float TopRadius, float Height, float HeightOffset)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ForceFieldShapeBox.FillByCylinder");
			byte* params = (byte*)malloc(16);
			*(float*)params = BottomRadius;
			*(float*)(params + 4) = TopRadius;
			*(float*)(params + 8) = Height;
			*(float*)(params + 12) = HeightOffset;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* GetDrawComponent()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ForceFieldShapeBox.GetDrawComponent");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params;
			free(params);
			return returnVal;
		}
	};
}
