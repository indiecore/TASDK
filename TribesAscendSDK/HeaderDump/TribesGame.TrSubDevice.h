#pragma once
#include "Core.Object.Vector.h"
#include "TribesGame.TrDevice.h"
#include "Engine.Actor.ImpactInfo.h"
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
		ImpactInfo CalcWeaponFire(Vector StartTrace, Vector EndTrace, 
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
			auto returnVal = *(ImpactInfo*)(params + 48);
			free(params);
			return returnVal;
		}
	};
}
