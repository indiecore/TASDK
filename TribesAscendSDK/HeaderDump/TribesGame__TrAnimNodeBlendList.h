#pragma once
#include "Engine__AnimNodeBlendList.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrAnimNodeBlendList." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrAnimNodeBlendList : public AnimNodeBlendList
	{
	public:
		ADD_VAR(::FloatProperty, m_fBlendTime, 0xFFFFFFFF)
		float GetBlendTime(int ChildIndex, bool bGetDefault)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAnimNodeBlendList.GetBlendTime");
			byte* params = (byte*)malloc(12);
			*(int*)params = ChildIndex;
			*(bool*)(params + 4) = bGetDefault;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 8);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
