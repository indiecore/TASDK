#pragma once
#include "Core.Object.Vector.h"
#include "Engine.ForceFieldShape.h"
namespace UnrealScript
{
	class ForceFieldShapeSphere : public ForceFieldShape
	{
	public:
		float GetRadius()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ForceFieldShapeSphere.GetRadius");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		void FillBySphere(float Radius)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ForceFieldShapeSphere.FillBySphere");
			byte* params = (byte*)malloc(4);
			*(float*)params = Radius;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void FillByBox(Vector Extent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ForceFieldShapeSphere.FillByBox");
			byte* params = (byte*)malloc(12);
			*(Vector*)params = Extent;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void FillByCapsule(float Height, float Radius)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ForceFieldShapeSphere.FillByCapsule");
			byte* params = (byte*)malloc(8);
			*(float*)params = Height;
			*(float*)(params + 4) = Radius;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void FillByCylinder(float BottomRadius, float TopRadius, float Height, float HeightOffset)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ForceFieldShapeSphere.FillByCylinder");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ForceFieldShapeSphere.GetDrawComponent");
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
