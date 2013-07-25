#pragma once
#include "Engine__Actor.h"
#include "Engine__Pawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrCollisionProxy." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrCollisionProxy : public Actor
	{
	public:
		ADD_VAR(::BoolProperty, m_bTrackLocallyControlledPawnsOnly, 0x20)
		ADD_VAR(::BoolProperty, m_bForwardOwnerOnly, 0x10)
		ADD_VAR(::BoolProperty, m_bIgnoreInvulnerablePlayers, 0x8)
		ADD_VAR(::BoolProperty, m_bIgnoreHackedPawns, 0x4)
		ADD_VAR(::BoolProperty, m_bIgnoreNonPlayers, 0x2)
		ADD_VAR(::BoolProperty, m_bIgnoreStealthPlayers, 0x1)
		void TouchOther(class Actor* Other, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* OtherComp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCollisionProxy.TouchOther");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = Other;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)(params + 4) = OtherComp;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ForceProximityScan(float Radius)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCollisionProxy.ForceProximityScan");
			byte* params = (byte*)malloc(4);
			*(float*)params = Radius;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Touch(class Actor* Other, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* OtherComp, Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCollisionProxy.Touch");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCollisionProxy.UnTouch");
			byte* params = (byte*)malloc(4);
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool ShouldIgnoreActor(class Actor* Actor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCollisionProxy.ShouldIgnoreActor");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = Actor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void ForceClearNearByPawnsList()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCollisionProxy.ForceClearNearByPawnsList");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCollisionProxy.Destroyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CheckNearByPawns(class Pawn* aPawn, bool bAdd)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCollisionProxy.CheckNearByPawns");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = aPawn;
			*(bool*)(params + 4) = bAdd;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnPawnAdded(class Pawn* aPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCollisionProxy.OnPawnAdded");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = aPawn;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnPawnRemoved(class Pawn* aPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCollisionProxy.OnPawnRemoved");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = aPawn;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		int GetNearByPawns(bool bOnlyValid)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCollisionProxy.GetNearByPawns");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bOnlyValid;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		void FellOutOfWorld(ScriptClass* dmgType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCollisionProxy.FellOutOfWorld");
			byte* params = (byte*)malloc(4);
			*(ScriptClass**)params = dmgType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
