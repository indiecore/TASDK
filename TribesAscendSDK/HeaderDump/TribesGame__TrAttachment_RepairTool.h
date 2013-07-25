#pragma once
#include "TribesGame__TrDeviceAttachment.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrAttachment_RepairTool." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrAttachment_RepairTool." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrAttachment_RepairTool : public TrDeviceAttachment
	{
	public:
		ADD_STRUCT(::VectorProperty, m_Tangent, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, m_Location, 0xFFFFFFFF
		ADD_VAR(::BoolProperty, m_bIsTracerActive, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
