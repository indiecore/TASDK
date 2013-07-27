#pragma once
#include "Engine.AnimNodeBlendList.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class TrAnimNodeBlendList : public AnimNodeBlendList
	{
	public:
		ADD_STRUCT(ScriptArray<float>, m_ChildBlendInTime, 276)
		ADD_STRUCT(float, m_fBlendTime, 288)
		float GetBlendTime(int ChildIndex, bool bGetDefault)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAnimNodeBlendList.GetBlendTime");
			byte params[12] = { NULL };
			*(int*)&params[0] = ChildIndex;
			*(bool*)&params[4] = bGetDefault;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[8];
		}
	};
}
#undef ADD_STRUCT
