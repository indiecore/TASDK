#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqAct_DrawText." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.SeqAct_DrawText." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqAct_DrawText : public SequenceAction
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Engine.HUD.KismetDrawTextInfo' for the property named 'DrawTextInfo'!
		ADD_VAR(::FloatProperty, DisplayTimeSeconds, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bDisplayOnObject, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
