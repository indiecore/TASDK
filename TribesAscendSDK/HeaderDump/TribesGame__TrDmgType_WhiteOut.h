#pragma once
#include "TribesGame__TrDmgType_Explosive.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrDmgType_WhiteOut." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrDmgType_WhiteOut : public TrDmgType_Explosive
	{
	public:
		ADD_VAR(::FloatProperty, m_fWhiteoutInterpSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fWhiteoutTargetValue, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
