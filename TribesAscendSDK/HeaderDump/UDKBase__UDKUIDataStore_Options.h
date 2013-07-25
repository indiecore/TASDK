#pragma once
#include "Engine__UIDataStore_GameResource.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UDKBase.UDKUIDataStore_Options." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UDKUIDataStore_Options : public UIDataStore_GameResource
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.MultiMap_Mirror' for the property named 'OptionProviders'!
		void ClearSet(ScriptName SetName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKUIDataStore_Options.ClearSet");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = SetName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AppendToSet(ScriptName SetName, int NumOptions)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKUIDataStore_Options.AppendToSet");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = SetName;
			*(int*)(params + 8) = NumOptions;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void GetSet(ScriptName SetName, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& OutProviders)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKUIDataStore_Options.GetSet");
			byte* params = (byte*)malloc(20);
			*(ScriptName*)params = SetName;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 8) = OutProviders;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			OutProviders = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 8);
			free(params);
		}
	};
}
#undef ADD_STRUCT
