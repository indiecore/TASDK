#pragma once
#include "Engine.UIRoot.h"
#include "Engine.DataStoreClient.h"
#include "Engine.PostProcessChain.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.UISceneClient." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.UISceneClient." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.UISceneClient." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UISceneClient : public UIRoot
	{
	public:
		ADD_VAR(::BoolProperty, bEnablePostProcess, 0x1)
		ADD_OBJECT(PostProcessChain, UIScenePostProcess)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix' for the property named 'InvCanvasToScreen'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix' for the property named 'CanvasToScreen'!
		ADD_OBJECT(DataStoreClient, DataStoreManager)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.IntPoint' for the property named 'MousePosition'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'RenderViewport'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTable_FExec'!
		bool IsUIActive(int Flags)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UISceneClient.IsUIActive");
			byte* params = (byte*)malloc(8);
			*(int*)params = Flags;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix'!
void* GetCanvasToScreen()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UISceneClient.GetCanvasToScreen");
			byte* params = (byte*)malloc(64);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix'!
void**)params;
			free(params);
			return returnVal;
		}
		
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix'!
void* GetInverseCanvasToScreen()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UISceneClient.GetInverseCanvasToScreen");
			byte* params = (byte*)malloc(64);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix'!
void**)params;
			free(params);
			return returnVal;
		}
		void InitializeSceneClient()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UISceneClient.InitializeSceneClient");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
