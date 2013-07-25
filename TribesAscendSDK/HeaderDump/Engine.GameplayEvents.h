#pragma once
#include "Core.Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.GameplayEvents." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.GameplayEvents." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GameplayEvents : public Object
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Engine.GameplayEvents.GameSessionInformation' for the property named 'CurrentSessionInfo'!
		// WARNING: Unknown structure type 'ScriptStruct Engine.GameplayEvents.GameplayEventsHeader' for the property named 'Header'!
		ADD_VAR(::StrProperty, StatsFileName, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'Archive'!
		bool OpenStatsFile(ScriptArray<wchar_t> Filename)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEvents.OpenStatsFile");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = Filename;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		void CloseStatsFile()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEvents.CloseStatsFile");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		ScriptArray<wchar_t> GetFilename()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEvents.GetFilename");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
