#pragma once
#include "Engine__Interaction.h"
#include "GFxUI__GFxMoviePlayer.h"
#include "Engine__LocalPlayer.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty GFxUI.GFxInteraction." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GFxInteraction : public Interaction
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTable_FCallbackEventDevice'!
		// Here lies the not-yet-implemented method 'GetFocusMovie'
		// Here lies the not-yet-implemented method 'NotifyGameSessionEnded'
		// Here lies the not-yet-implemented method 'NotifyPlayerAdded'
		// Here lies the not-yet-implemented method 'NotifyPlayerRemoved'
		// Here lies the not-yet-implemented method 'CloseAllMoviePlayers'
	};
}
#undef ADD_STRUCT
