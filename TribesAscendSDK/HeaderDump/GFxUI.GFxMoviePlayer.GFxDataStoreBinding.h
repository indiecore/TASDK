#pragma once
#include "Engine.UIRoot.UIDataStoreBinding.h"
#include "Core.Object.Pointer.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GFxMoviePlayer.GFxDataStoreBinding." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty GFxMoviePlayer.GFxDataStoreBinding." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GFxDataStoreBinding
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<UIDataStoreBinding>, DataSource, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, VarPath, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ModelId, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ControlId, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bEditable, 0x1)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, ModelRef, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, ControlRef, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
