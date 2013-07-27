#pragma once
#include "Engine.UIPropertyDataProvider.h"
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class UIDynamicDataProvider : public UIPropertyDataProvider
	{
	public:
		ADD_OBJECT(Object, DataSource, 120)
		ADD_OBJECT(ScriptClass, DataClass, 116)
		ADD_STRUCT(Object::Pointer, VfTable_IUIListElementCellProvider, 112)
		bool BindProviderInstance(class Object* DataSourceInstance)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDynamicDataProvider.BindProviderInstance");
			byte params[8] = { NULL };
			*(class Object**)&params[0] = DataSourceInstance;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool UnbindProviderInstance()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDynamicDataProvider.UnbindProviderInstance");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void ProviderInstanceBound(class Object* DataSourceInstance)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDynamicDataProvider.ProviderInstanceBound");
			byte params[4] = { NULL };
			*(class Object**)&params[0] = DataSourceInstance;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ProviderInstanceUnbound(class Object* DataSourceInstance)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDynamicDataProvider.ProviderInstanceUnbound");
			byte params[4] = { NULL };
			*(class Object**)&params[0] = DataSourceInstance;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsValidDataSourceClass(ScriptClass* PotentialDataSourceClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDynamicDataProvider.IsValidDataSourceClass");
			byte params[8] = { NULL };
			*(ScriptClass**)&params[0] = PotentialDataSourceClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		class Object* GetDataSource()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDynamicDataProvider.GetDataSource");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Object**)&params[0];
		}
		bool CleanupDataProvider()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDynamicDataProvider.CleanupDataProvider");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
