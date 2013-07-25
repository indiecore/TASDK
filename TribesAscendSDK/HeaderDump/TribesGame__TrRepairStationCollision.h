#pragma once
#include "TribesGame__TrStationCollision.h"
#include "TribesGame__TrPawn.h"
#include "Engine__Actor.h"
namespace UnrealScript
{
	class TrRepairStationCollision : public TrStationCollision
	{
	public:
		int GetPawnsInStation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrRepairStationCollision.GetPawnsInStation");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		void CheckNearByPawns(class TrPawn* aPawn, bool bAdd)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrRepairStationCollision.CheckNearByPawns");
			byte* params = (byte*)malloc(8);
			*(class TrPawn**)params = aPawn;
			*(bool*)(params + 4) = bAdd;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Touch(class Actor* Other, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* OtherComp, Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrRepairStationCollision.Touch");
			byte* params = (byte*)malloc(32);
			*(class Actor**)params = Other;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)(params + 4) = OtherComp;
			*(Vector*)(params + 8) = HitLocation;
			*(Vector*)(params + 20) = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UnTouch(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrRepairStationCollision.UnTouch");
			byte* params = (byte*)malloc(4);
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
