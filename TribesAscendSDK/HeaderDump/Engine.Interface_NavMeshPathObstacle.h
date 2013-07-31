#pragma once
#include "Core.Interface.h"
namespace UnrealScript
{
	class Interface_NavMeshPathObstacle : public Interface
	{
		enum EEdgeHandlingStatus : byte
		{
			EHS_AddedBothDirs = 0,
			EHS_Added0to1 = 1,
			EHS_Added1to0 = 2,
			EHS_AddedNone = 3,
			EHS_MAX = 4,
		};
	};
}
