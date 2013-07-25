#pragma once
#include "Core.Exporter.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UnrealEd.RenderTargetCubeExporterTGA." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class RenderTargetCubeExporterTGA : public Exporter
	{
	public:
		ADD_VAR(::ByteProperty, CubeFace, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
