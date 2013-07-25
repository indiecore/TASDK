#pragma once
#include "Engine__MaterialExpression.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.MaterialExpressionCustomTexture." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class MaterialExpressionCustomTexture : public MaterialExpression
	{
	public:
		ADD_OBJECT(Texture, Texture)
	};
}
#undef ADD_OBJECT
