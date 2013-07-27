#pragma once
#include "Engine.UIRoot.h"
#include "Engine.DataStoreClient.h"
#include "Core.Object.h"
#include "Engine.PostProcessChain.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
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
	class UISceneClient : public UIRoot
	{
	public:
		static const auto SCENEFILTER_None = 0x00000000;
		static const auto SCENEFILTER_IncludeTransient = 0x00000001;
		static const auto SCENEFILTER_InputProcessorOnly = 0x00000002;
		static const auto SCENEFILTER_PausersOnly = 0x00000004;
		static const auto SCENEFILTER_PrimitiveUsersOnly = 0x00000008;
		static const auto SCENEFILTER_UsesPostProcessing = 0x00000010;
		static const auto SCENEFILTER_ReceivesFocus = 0x00000020;
		static const auto SCENEFILTER_Any = 0xFFFFFFFF;
		ADD_BOOL(bEnablePostProcess, 212, 0x1)
		ADD_OBJECT(PostProcessChain, UIScenePostProcess, 208)
		ADD_STRUCT(Object::Matrix, InvCanvasToScreen, 144)
		ADD_STRUCT(Object::Matrix, CanvasToScreen, 80)
		ADD_OBJECT(DataStoreClient, DataStoreManager, 76)
		ADD_STRUCT(Object::IntPoint, MousePosition, 68)
		ADD_STRUCT(Object::Pointer, RenderViewport, 64)
		ADD_STRUCT(Object::Pointer, VfTable_FExec, 60)
		bool IsUIActive(int Flags)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UISceneClient.IsUIActive");
			byte params[8] = { NULL };
			*(int*)&params[0] = Flags;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		Object::Matrix GetCanvasToScreen()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UISceneClient.GetCanvasToScreen");
			byte params[64] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Matrix*)&params[0];
		}
		Object::Matrix GetInverseCanvasToScreen()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UISceneClient.GetInverseCanvasToScreen");
			byte params[64] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Matrix*)&params[0];
		}
		void InitializeSceneClient()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UISceneClient.InitializeSceneClient");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
