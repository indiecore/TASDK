#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.AnimNodeAimOffset." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.AnimNodeAimOffset." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.AnimNodeAimOffset." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class AnimNodeAimOffset : public AnimNodeBlendBase
	{
	public:
		ADD_VAR(::IntProperty, CurrentProfileIndex, 0xFFFFFFFF)
		ADD_OBJECT(AnimNodeAimOffset, TemplateNode)
		ADD_VAR(::ByteProperty, ForcedAimDir, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PassThroughAtOrAboveLOD, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bSynchronizeNodesInEditor, 0x8)
		ADD_VAR(::BoolProperty, bPassThroughWhenNotRendered, 0x4)
		ADD_VAR(::BoolProperty, bBakeFromAnimations, 0x2)
		ADD_VAR(::BoolProperty, bForceAimDir, 0x1)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D' for the property named 'AngleOffset'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D' for the property named 'Aim'!
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
