#pragma once
#include "Engine.UIDataStore_GameResource.h"
#include "UDKBase.UDKUIResourceDataProvider.h"
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UDKUIDataStore_Options : public UIDataStore_GameResource
	{
	public:
		ADD_STRUCT(ScriptArray<class UDKUIResourceDataProvider*>, DynamicProviders, 256)
		ADD_STRUCT(Object::MultiMap_Mirror, OptionProviders, 196)
		void ClearSet(ScriptName SetName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35645);
			byte params[8] = { NULL };
			*(ScriptName*)params = SetName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AppendToSet(ScriptName SetName, int NumOptions)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35647);
			byte params[12] = { NULL };
			*(ScriptName*)params = SetName;
			*(int*)&params[8] = NumOptions;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GetSet(ScriptName SetName, ScriptArray<class UDKUIResourceDataProvider*>& OutProviders)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(35650);
			byte params[20] = { NULL };
			*(ScriptName*)params = SetName;
			*(ScriptArray<class UDKUIResourceDataProvider*>*)&params[8] = OutProviders;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutProviders = *(ScriptArray<class UDKUIResourceDataProvider*>*)&params[8];
		}
	};
}
#undef ADD_STRUCT
