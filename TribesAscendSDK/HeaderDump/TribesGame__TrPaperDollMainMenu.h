#pragma once
#include "TribesGame__TrPaperDoll.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrPaperDollMainMenu." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrPaperDollMainMenu." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrPaperDollMainMenu : public TrPaperDoll
	{
	public:
		ADD_VAR(::ByteProperty, m_OldContentDataType, 0xFFFFFFFF)
		ADD_STRUCT(::RotatorProperty, m_rZeroedRotation, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, m_fFullCharacterLightingContrastFactor, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bWasLastMeshSwapRequestMainMenuContentScene, 0x2)
		ADD_VAR(::BoolProperty, m_bEditorMode, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
