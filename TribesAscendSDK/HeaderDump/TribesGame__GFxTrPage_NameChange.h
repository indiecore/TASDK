#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrPage_NameChange." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GFxTrPage_NameChange : public GFxTrPage_VendorTable
	{
	public:
		ADD_VAR(::BoolProperty, bWaitingForNewNameInput, 0x1)
		ADD_VAR(::StrProperty, NamePopupTitle, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
