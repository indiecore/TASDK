#pragma once
#include "Core.Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.NavMeshGoal_Filter." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class NavMeshGoal_Filter : public Object
	{
	public:
		ADD_VAR(::IntProperty, NumNodesProcessed, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NumNodesThrownOut, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bShowDebug, 0x1)
		ScriptArray<wchar_t> GetDumpString()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavMeshGoal_Filter.GetDumpString");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
