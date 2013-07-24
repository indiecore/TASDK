#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.UIInteraction." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.UIInteraction." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.UIInteraction." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UIInteraction : public Interaction
	{
	public:
		ADD_OBJECT(GameUISceneClient, SceneClient)
		// WARNING: Unknown structure type 'ScriptStruct Engine.UIInteraction.UIAxisEmulationData' for the property named 'AxisInputEmulation'!
		// WARNING: Unknown structure type 'ScriptStruct Engine.UIInteraction.UIKeyRepeatData' for the property named 'MouseButtonRepeatInfo'!
		ADD_VAR(::IntProperty, DoubleClickPixelTolerance, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DoubleClickTriggerSeconds, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MouseButtonRepeatDelay, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AxisRepeatDelay, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, UIAxisMultiplier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, UIJoystickDeadZone, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bProcessInput, 0x1)
		ADD_OBJECT(DataStoreClient, DataStoreManager)
		ADD_OBJECT(UIManager, UIManager)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTable_FCallbackEventDevice'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTable_FGlobalDataStoreClientManager'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTable_FExec'!
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
