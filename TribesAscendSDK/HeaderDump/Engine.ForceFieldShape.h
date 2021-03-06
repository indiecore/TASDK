#pragma once
#include "Core.Object.h"
namespace UnrealScript
{
	class ForceFieldShape : public Object
	{
	public:
		void FillBySphere(float Radius)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15918);
			byte params[4] = { NULL };
			*(float*)params = Radius;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FillByBox(Vector Dimension)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15920);
			byte params[12] = { NULL };
			*(Vector*)params = Dimension;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FillByCapsule(float Height, float Radius)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15922);
			byte params[8] = { NULL };
			*(float*)params = Height;
			*(float*)&params[4] = Radius;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FillByCylinder(float BottomRadius, float TopRadius, float Height, float HeightOffset)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15925);
			byte params[16] = { NULL };
			*(float*)params = BottomRadius;
			*(float*)&params[4] = TopRadius;
			*(float*)&params[8] = Height;
			*(float*)&params[12] = HeightOffset;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* GetDrawComponent()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15930);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params;
		}
	};
}
