#pragma once
#include "UTGame__UTSimpleDestroyable.h"
#include "Engine__Controller.h"
#include "Engine__SeqAct_Toggle.h"
#include "Engine__Actor.h"
namespace UnrealScript
{
	class TrDestroyableTarget : public UTSimpleDestroyable
	{
	public:
		void TakeDamage(int DamageAmount, class Controller* EventInstigator, Vector HitLocation, Vector Momentum, ScriptClass* DamageType, 
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.TraceHitInfo'!
void* HitInfo, class Actor* DamageCauser)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDestroyableTarget.TakeDamage");
			byte* params = (byte*)malloc(68);
			*(int*)params = DamageAmount;
			*(class Controller**)(params + 4) = EventInstigator;
			*(Vector*)(params + 8) = HitLocation;
			*(Vector*)(params + 20) = Momentum;
			*(ScriptClass**)(params + 32) = DamageType;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.TraceHitInfo'!
void**)(params + 36) = HitInfo;
			*(class Actor**)(params + 64) = DamageCauser;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnToggle(class SeqAct_Toggle* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDestroyableTarget.OnToggle");
			byte* params = (byte*)malloc(4);
			*(class SeqAct_Toggle**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
