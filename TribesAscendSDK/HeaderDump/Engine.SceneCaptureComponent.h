#pragma once
#include "Engine.ActorComponent.h"
#include "Core.Object.Pointer.h"
#include "Engine.PostProcessChain.h"
#include "Core.Object.Color.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SceneCaptureComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.SceneCaptureComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.SceneCaptureComponent." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SceneCaptureComponent : public ActorComponent
	{
	public:
		ADD_VAR(::BoolProperty, bEnabled, 0x1)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, ViewState, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, CaptureInfo, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxStreamingUpdateDist, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxViewDistanceOverride, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxUpdateDist, 0xFFFFFFFF)
		ADD_OBJECT(PostProcessChain, PostProcess)
		ADD_VAR(::FloatProperty, FrameRate, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SceneLOD, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, ViewMode, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Color>, ClearColor, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bSkipRenderingDepthPrepass, 0x40)
		ADD_VAR(::BoolProperty, bSkipUpdateIfOwnerOccluded, 0x20)
		ADD_VAR(::BoolProperty, bSkipUpdateIfTextureUsersOccluded, 0x10)
		ADD_VAR(::BoolProperty, bUseMainScenePostProcessSettings, 0x8)
		ADD_VAR(::BoolProperty, bEnableFog, 0x4)
		ADD_VAR(::BoolProperty, bEnablePostProcess, 0x2)
		void SetEnabled(bool bEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SceneCaptureComponent.SetEnabled");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetFrameRate(float NewFrameRate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SceneCaptureComponent.SetFrameRate");
			byte* params = (byte*)malloc(4);
			*(float*)params = NewFrameRate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
