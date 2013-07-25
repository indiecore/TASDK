#pragma once
#include "TribesGame__TrDeviceAttachment.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrAttachment_LaserTargeter." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrAttachment_LaserTargeter : public TrDeviceAttachment
	{
	public:
		ADD_VAR(::BoolProperty, m_bIsTracerActive, 0x1)
	};
}
#undef ADD_VAR
