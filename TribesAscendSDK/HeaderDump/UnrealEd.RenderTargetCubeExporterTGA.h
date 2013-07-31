#pragma once
#include "Core.Exporter.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class RenderTargetCubeExporterTGA : public Exporter
	{
	public:
		enum CubeFace : byte
		{
			CubeFace_MAX = 0,
		};
		ADD_STRUCT(RenderTargetCubeExporterTGA::CubeFace, CubeFace, 100)
	};
}
#undef ADD_STRUCT
