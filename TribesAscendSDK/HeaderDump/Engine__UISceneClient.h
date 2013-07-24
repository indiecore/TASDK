#pragma once
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
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
