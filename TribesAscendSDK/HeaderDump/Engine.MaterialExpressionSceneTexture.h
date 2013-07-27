#pragma once
#include "Engine.MaterialExpression.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class MaterialExpressionSceneTexture : public MaterialExpression
	{
	public:
		enum ESceneTextureType : byte
		{
			SceneTex_Lighting = 0,
			SceneTex_MAX = 1,
		};
		ADD_BOOL(ScreenAlign, 140, 0x1)
		ADD_STRUCT(MaterialExpressionSceneTexture::ESceneTextureType, SceneTextureType, 136)
		ADD_STRUCT(MaterialExpression::ExpressionInput, Coordinates, 108)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
