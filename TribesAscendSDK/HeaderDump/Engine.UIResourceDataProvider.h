#pragma once
#include "Engine.UIPropertyDataProvider.h"
#include "Core.Object.Pointer.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.UIResourceDataProvider." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.UIResourceDataProvider." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UIResourceDataProvider : public UIPropertyDataProvider
	{
	public:
		ADD_VAR(::BoolProperty, bSkipDuringEnumeration, 0x2)
		ADD_VAR(::BoolProperty, bDataBindingPropertiesOnly, 0x1)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, VfTable_IUIListElementCellProvider, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, VfTable_IUIListElementProvider, 0xFFFFFFFF)
		void InitializeProvider(bool bIsEditor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIResourceDataProvider.InitializeProvider");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bIsEditor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
