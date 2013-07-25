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
		// Here lies the not-yet-implemented method 'GetBlendTime'
	};
}
#undef ADD_VAR
