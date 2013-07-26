#pragma once
#include "Engine.Interaction.h"
#include "Core.Object.Pointer.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty PlatformCommon.TgBrowserInteraction." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TgBrowserInteraction : public Interaction
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, VfTable_FCallbackEventDevice, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT
