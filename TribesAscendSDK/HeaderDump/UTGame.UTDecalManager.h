#pragma once
#include "Engine.DecalManager.h"
namespace UnrealScript
{
	class UTDecalManager : public DecalManager
	{
	public:
		bool CanSpawnDecals()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47046);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
	};
}
