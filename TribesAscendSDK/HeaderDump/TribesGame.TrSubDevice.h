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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112994);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		Actor::ImpactInfo CalcWeaponFire(Vector StartTrace, Vector EndTrace, ScriptArray<Actor::ImpactInfo>& ImpactList, Vector Extent)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112995);
			byte params[128] = { NULL };
			*(Vector*)params = StartTrace;
			*(Vector*)&params[12] = EndTrace;
			*(ScriptArray<Actor::ImpactInfo>*)&params[24] = ImpactList;
			*(Vector*)&params[36] = Extent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ImpactList = *(ScriptArray<Actor::ImpactInfo>*)&params[24];
			return *(Actor::ImpactInfo*)&params[48];
		}
	};
}
