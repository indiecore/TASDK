#pragma once
#include "Engine.ParticleModule.h"
namespace UnrealScript
{
	class ParticleModuleBeamBase : public ParticleModule
	{
		enum Beam2SourceTargetMethod : byte
		{
			PEB2STM_Default = 0,
			PEB2STM_UserSet = 1,
			PEB2STM_Emitter = 2,
			PEB2STM_Particle = 3,
			PEB2STM_Actor = 4,
			PEB2STM_MAX = 5,
		};
		enum Beam2SourceTargetTangentMethod : byte
		{
			PEB2STTM_Direct = 0,
			PEB2STTM_UserSet = 1,
			PEB2STTM_Distribution = 2,
			PEB2STTM_Emitter = 3,
			PEB2STTM_MAX = 4,
		};
	};
}
