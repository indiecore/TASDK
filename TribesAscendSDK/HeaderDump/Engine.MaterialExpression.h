#pragma once
#include "Core.Object.h"
#include "Engine.MaterialExpressionCompound.h"
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
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class MaterialExpression : public Object
	{
	public:
		struct ExpressionInput
		{
		public:
			ADD_STRUCT(int, GCC64_Padding, 24)
			ADD_STRUCT(int, MaskA, 20)
			ADD_STRUCT(int, MaskB, 16)
			ADD_STRUCT(int, MaskG, 12)
			ADD_STRUCT(int, MaskR, 8)
			ADD_STRUCT(int, Mask, 4)
			ADD_OBJECT(MaterialExpression, Expression, 0)
		};
		ADD_STRUCT(ScriptArray<ScriptName>, MenuCategories, 96)
		ADD_STRUCT(ScriptString*, Desc, 84)
		ADD_OBJECT(MaterialExpressionCompound, Compound, 80)
		ADD_BOOL(bUsedByStaticParameterSet, 76, 0x20)
		ADD_BOOL(bHidePreviewWindow, 76, 0x10)
		ADD_BOOL(bShowOutputNameOnPin, 76, 0x8)
		ADD_BOOL(bIsParameterExpression, 76, 0x4)
		ADD_BOOL(bNeedToUpdatePreview, 76, 0x2)
		ADD_BOOL(bRealtimePreview, 76, 0x1)
		ADD_STRUCT(int, MaterialExpressionEditorY, 72)
		ADD_STRUCT(int, MaterialExpressionEditorX, 68)
		ADD_STRUCT(int, EditorY, 64)
		ADD_STRUCT(int, EditorX, 60)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
