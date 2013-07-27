#pragma once
#include "TribesGame.TrAnimNodeBlendList.h"
#include "Engine.Actor.h"
#include "TribesGame.TrPawn.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
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
	class TrAnimNodeBlendByPhysics : public TrAnimNodeBlendList
	{
	public:
		class ChildBlendInfo
		{
		public:
			ADD_STRUCT(float, m_fBlendTime, 4)
			ADD_STRUCT(Actor::EPhysics, m_PhysicsState, 0)
		};
		class ChildrenBlendInfo
		{
		public:
			ADD_STRUCT(ScriptArray<TrAnimNodeBlendByPhysics::ChildBlendInfo>, m_ChildBlendInfo, 4)
			ADD_STRUCT(Actor::EPhysics, m_PhysicsState, 0)
		};
		ADD_STRUCT(ScriptArray<Actor::EPhysics>, m_PhysicsChildren, 304)
		ADD_STRUCT(ScriptArray<TrAnimNodeBlendByPhysics::ChildrenBlendInfo>, m_ChildrenBlendInfo, 320)
		ADD_BOOL(m_bDirectUnspecifiedPhysicsThroughChild0, 316, 0x1)
		ADD_STRUCT(int, m_CurrentPhysicsChildIndex, 300)
		ADD_STRUCT(Actor::EPhysics, m_CurrentPhysics, 297)
		ADD_STRUCT(Actor::EPhysics, m_LastPhysics, 296)
		ADD_OBJECT(TrPawn, m_TrPawn, 292)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
