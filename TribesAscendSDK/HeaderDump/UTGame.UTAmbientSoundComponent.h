#pragma once
#include "Engine.AudioComponent.h"
namespace UnrealScript
{
	class UTAmbientSoundComponent : public AudioComponent
	{
	public:
		void OcclusionChanged(bool bNowOccluded)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTAmbientSoundComponent.OcclusionChanged");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bNowOccluded;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
