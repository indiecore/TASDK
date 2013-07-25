#pragma once
#include "Core__Object.h"
namespace UnrealScript
{
	class TerrainLayerSetup : public Object
	{
	public:
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.TerrainLayerSetup.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
