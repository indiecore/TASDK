#pragma once
#include "Core__Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTCharInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UTCharInfo : public Object
	{
	public:
		ADD_VAR(::FloatProperty, LOD3DisplayFactor, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LOD2DisplayFactor, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LOD1DisplayFactor, 0xFFFFFFFF)
		ScriptClass* FindFamilyInfo(ScriptArray<wchar_t> InFamilyID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCharInfo.FindFamilyInfo");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = InFamilyID;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptClass**)(params + 12);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetRandomCharClassName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCharInfo.GetRandomCharClassName");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
