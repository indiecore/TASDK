#pragma once
#include "Engine.ForceFieldShape.h"
#include "Core.Object.h"
namespace UnrealScript
{
	class ForceFieldShapeBox : public ForceFieldShape
	{
	public:
		Object::Vector GetRadii()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ForceFieldShapeBox.GetRadii");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[0];
		}
		void FillBySphere(float Radius)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ForceFieldShapeBox.FillBySphere");
			byte params[4] = { NULL };
			*(float*)&params[0] = Radius;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FillByBox(Object::Vector Extent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ForceFieldShapeBox.FillByBox");
			byte params[12] = { NULL };
			*(Object::Vector*)&params[0] = Extent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FillByCapsule(float Height, float Radius)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ForceFieldShapeBox.FillByCapsule");
			byte params[8] = { NULL };
			*(float*)&params[0] = Height;
			*(float*)&params[4] = Radius;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FillByCylinder(float BottomRadius, float TopRadius, float Height, float HeightOffset)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ForceFieldShapeBox.FillByCylinder");
			byte params[16] = { NULL };
			*(float*)&params[0] = BottomRadius;
			*(float*)&params[4] = TopRadius;
			*(float*)&params[8] = Height;
			*(float*)&params[12] = HeightOffset;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* GetDrawComponent()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ForceFieldShapeBox.GetDrawComponent");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0];
		}
	};
}
