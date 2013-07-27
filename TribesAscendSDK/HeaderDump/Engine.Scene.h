#pragma once
#include "Core.Object.h"
namespace UnrealScript
{
	class Scene : public Object
	{
		static const auto SDPG_NumBits = 3;
		enum EDetailMode : byte
		{
			DM_Low = 0,
			DM_Medium = 1,
			DM_High = 2,
			DM_MAX = 3,
		};
		enum ESceneDepthPriorityGroup : byte
		{
			SDPG_UnrealEdBackground = 0,
			SDPG_World = 1,
			SDPG_Foreground = 2,
			SDPG_UnrealEdForeground = 3,
			SDPG_PostProcess = 4,
			SDPG_MAX = 5,
		};
	};
}
