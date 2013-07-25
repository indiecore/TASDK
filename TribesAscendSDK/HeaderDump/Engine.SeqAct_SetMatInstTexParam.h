#pragma once
#include "Engine.Texture.h"
#include "Engine.SequenceAction.h"
#include "Engine.MaterialInstanceConstant.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqAct_SetMatInstTexParam." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.SeqAct_SetMatInstTexParam." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SeqAct_SetMatInstTexParam : public SequenceAction
	{
	public:
		ADD_VAR(::NameProperty, ParamName, 0xFFFFFFFF)
		ADD_OBJECT(Texture, NewTexture)
		ADD_OBJECT(MaterialInstanceConstant, MatInst)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
