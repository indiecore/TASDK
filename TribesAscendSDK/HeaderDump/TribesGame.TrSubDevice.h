#pragma once
#include "TribesGame.TrDevice.h"
#include "Core.Object.h"
#include "Engine.Actor.h"
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
		Actor::ImpactInfo CalcWeaponFire(Object::Vector StartTrace, Object::Vector EndTrace, ScriptArray<Actor::ImpactInfo>& ImpactList, Object::Vector Extent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSubDevice.CalcWeaponFire");
			byte params[128] = { NULL };
			*(Object::Vector*)&params[0] = StartTrace;
			*(Object::Vector*)&params[12] = EndTrace;
			*(ScriptArray<Actor::ImpactInfo>*)&params[24] = ImpactList;
			*(Object::Vector*)&params[36] = Extent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ImpactList = *(ScriptArray<Actor::ImpactInfo>*)&params[24];
			return *(Actor::ImpactInfo*)&params[48];
		}
	};
}
