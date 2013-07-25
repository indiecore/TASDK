#pragma once
#include "Engine.UIPropertyDataProvider.h"
#include "Core.Object.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.UIDynamicDataProvider." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.UIDynamicDataProvider." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UIDynamicDataProvider : public UIPropertyDataProvider
	{
	public:
		ADD_OBJECT(Object, DataSource)
		ADD_OBJECT(ScriptClass, DataClass)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTable_IUIListElementCellProvider'!
		bool BindProviderInstance(class Object* DataSourceInstance)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDynamicDataProvider.BindProviderInstance");
			byte* params = (byte*)malloc(8);
			*(class Object**)params = DataSourceInstance;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool UnbindProviderInstance()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDynamicDataProvider.UnbindProviderInstance");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void ProviderInstanceBound(class Object* DataSourceInstance)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDynamicDataProvider.ProviderInstanceBound");
			byte* params = (byte*)malloc(4);
			*(class Object**)params = DataSourceInstance;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ProviderInstanceUnbound(class Object* DataSourceInstance)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDynamicDataProvider.ProviderInstanceUnbound");
			byte* params = (byte*)malloc(4);
			*(class Object**)params = DataSourceInstance;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool IsValidDataSourceClass(ScriptClass* PotentialDataSourceClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDynamicDataProvider.IsValidDataSourceClass");
			byte* params = (byte*)malloc(8);
			*(ScriptClass**)params = PotentialDataSourceClass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		class Object* GetDataSource()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDynamicDataProvider.GetDataSource");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Object**)params;
			free(params);
			return returnVal;
		}
		bool CleanupDataProvider()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDynamicDataProvider.CleanupDataProvider");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
