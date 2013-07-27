#pragma once
#include "Engine.PrimitiveComponent.h"
#include "TribesGame.TrTripActor.h"
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
	class TrTripComponent : public PrimitiveComponent
	{
	public:
		ADD_STRUCT(float, m_fCachedX, 492)
		ADD_OBJECT(TrTripActor, m_TripActor, 488)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
