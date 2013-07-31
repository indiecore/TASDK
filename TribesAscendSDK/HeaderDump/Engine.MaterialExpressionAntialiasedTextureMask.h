#pragma once
#include "Engine.MaterialExpressionTextureSampleParameter2D.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class MaterialExpressionAntialiasedTextureMask : public MaterialExpressionTextureSampleParameter2D
	{
	public:
		enum ETextureColorChannel : byte
		{
			TCC_Red = 0,
			TCC_Green = 1,
			TCC_Blue = 2,
			TCC_Alpha = 3,
			TCC_MAX = 4,
		};
		ADD_STRUCT(MaterialExpressionAntialiasedTextureMask::ETextureColorChannel, Channel, 168)
		ADD_STRUCT(float, Threshold, 164)
	};
}
#undef ADD_STRUCT
