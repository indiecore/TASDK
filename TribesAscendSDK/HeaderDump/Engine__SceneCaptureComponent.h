#pragma once
#include "Engine__ActorComponent.h"
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
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'ViewState'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'CaptureInfo'!
		ADD_VAR(::FloatProperty, MaxStreamingUpdateDist, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxViewDistanceOverride, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxUpdateDist, 0xFFFFFFFF)
		ADD_OBJECT(PostProcessChain, PostProcess)
		ADD_VAR(::FloatProperty, FrameRate, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SceneLOD, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, ViewMode, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'ClearColor'!
		ADD_VAR(::BoolProperty, bSkipRenderingDepthPrepass, 0x40)
		ADD_VAR(::BoolProperty, bSkipUpdateIfOwnerOccluded, 0x20)
		ADD_VAR(::BoolProperty, bSkipUpdateIfTextureUsersOccluded, 0x10)
		ADD_VAR(::BoolProperty, bUseMainScenePostProcessSettings, 0x8)
		ADD_VAR(::BoolProperty, bEnableFog, 0x4)
		ADD_VAR(::BoolProperty, bEnablePostProcess, 0x2)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
