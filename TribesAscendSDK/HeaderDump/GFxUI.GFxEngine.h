#pragma once
#include "Core.Object.h"
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
	class GFxEngine : public Object
	{
	public:
		struct GCReference
		{
		public:
			ADD_STRUCT(int, m_statid, 8)
			ADD_STRUCT(int, m_count, 4)
			ADD_OBJECT(Object, m_object, 0)
		};
		ADD_STRUCT(ScriptArray<GFxEngine::GCReference>, GCReferences, 60)
		ADD_STRUCT(int, RefCount, 72)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
