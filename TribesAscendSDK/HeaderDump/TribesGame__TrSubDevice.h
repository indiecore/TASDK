#pragma once
#include "TribesGame__TrDevice.h"
namespace UnrealScript
{
	class TrSubDevice : public TrDevice
	{
	public:
		void Reset()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSubDevice.Reset");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.ImpactInfo'!
void* CalcWeaponFire(Vector StartTrace, Vector EndTrace, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& ImpactList, Vector Extent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSubDevice.CalcWeaponFire");
			byte* params = (byte*)malloc(128);
			*(Vector*)params = StartTrace;
			*(Vector*)(params + 12) = EndTrace;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 24) = ImpactList;
			*(Vector*)(params + 36) = Extent;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			ImpactList = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 24);
			auto returnVal = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.ImpactInfo'!
void**)(params + 48);
			free(params);
			return returnVal;
		}
	};
}
