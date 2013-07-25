#pragma once
#include "Engine__UISceneClient.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.GameUISceneClient." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.GameUISceneClient." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GameUISceneClient : public UISceneClient
	{
	public:
		ADD_VAR(::BoolProperty, bCaptureUnprocessedInput, 0x10)
		ADD_VAR(::BoolProperty, bRenderDebugInfo, 0x8)
		ADD_VAR(::BoolProperty, bEnableDebugInput, 0x4)
		ADD_VAR(::BoolProperty, bUpdateSceneViewportSizes, 0x2)
		ADD_VAR(::BoolProperty, bUpdateInputProcessingStatus, 0x1)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Map_Mirror' for the property named 'InitialPressedKeys'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.IntPoint' for the property named 'DoubleClickStartPosition'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Double' for the property named 'DoubleClickStartTime'!
		ADD_VAR(::FloatProperty, LatestDeltaTime, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
