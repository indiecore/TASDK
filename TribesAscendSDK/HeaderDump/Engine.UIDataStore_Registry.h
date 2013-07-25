#pragma once
#include "Engine.UIDataStore.h"
#include "Engine.UIDynamicFieldProvider.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.UIDataStore_Registry." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UIDataStore_Registry : public UIDataStore
	{
	public:
		ADD_OBJECT(UIDynamicFieldProvider, RegistryDataProvider)
		class UIDynamicFieldProvider* GetDataProvider()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_Registry.GetDataProvider");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class UIDynamicFieldProvider**)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_OBJECT
