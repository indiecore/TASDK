#pragma once
#include "TribesGame.TrAnimNodeBlendList.h"
#include "TribesGame.TrPawn.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class TrAnimNodeBlendByFlying : public TrAnimNodeBlendList
	{
	public:
		enum EFlyDirTypes : byte
		{
			FLY_Forward = 0,
			FLY_Back = 1,
			FLY_Left = 2,
			FLY_Right = 3,
			FLY_Up = 4,
			FLY_Down = 5,
			FLY_UpMidair = 6,
			FLY_None = 7,
			FLY_MAX = 8,
		};
		ADD_OBJECT(TrPawn, m_TrPawn, 296)
		ADD_STRUCT(TrAnimNodeBlendByFlying::EFlyDirTypes, LastDirection, 292)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
