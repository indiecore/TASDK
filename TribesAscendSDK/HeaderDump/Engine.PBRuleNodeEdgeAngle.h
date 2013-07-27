#pragma once
#include "Engine.PBRuleNodeBase.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class PBRuleNodeEdgeAngle : public PBRuleNodeBase
	{
	public:
		enum EProcBuildingEdge : byte
		{
			EPBE_Top = 0,
			EPBE_Bottom = 1,
			EPBE_Left = 2,
			EPBE_Right = 3,
			EPBE_MAX = 4,
		};
		struct RBEdgeAngleInfo
		{
		public:
			ADD_STRUCT(float, Angle, 0)
		};
		ADD_STRUCT(ScriptArray<PBRuleNodeEdgeAngle::RBEdgeAngleInfo>, Angles, 108)
		ADD_STRUCT(PBRuleNodeEdgeAngle::EProcBuildingEdge, Edge, 104)
	};
}
#undef ADD_STRUCT
