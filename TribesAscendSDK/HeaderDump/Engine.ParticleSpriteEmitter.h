#pragma once
#include "Engine.ParticleEmitter.h"
namespace UnrealScript
{
	class ParticleSpriteEmitter : public ParticleEmitter
	{
		enum EParticleScreenAlignment : byte
		{
			PSA_Square = 0,
			PSA_Rectangle = 1,
			PSA_Velocity = 2,
			PSA_TypeSpecific = 3,
			PSA_MAX = 4,
		};
	};
}
