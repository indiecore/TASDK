#pragma once
#include "Engine__GameEngine.h"
#include "Engine__PlayerController.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty PlatformCommon.TgGameEngine." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TgGameEngine : public GameEngine
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'pEventMarshal'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'pOutgoingMarshal'!
		// Here lies the not-yet-implemented method 'OnMarshalEvent'
		// Here lies the not-yet-implemented method 'SetFunction'
		// Here lies the not-yet-implemented method 'SetFieldInt'
		// Here lies the not-yet-implemented method 'SetFieldFloat'
		// Here lies the not-yet-implemented method 'SetFieldString'
		// Here lies the not-yet-implemented method 'ClearMarshal'
		// Here lies the not-yet-implemented method 'SendMarshal'
		// Here lies the not-yet-implemented method 'SendMarshalAll'
		// Here lies the not-yet-implemented method 'GetFieldInt'
		// Here lies the not-yet-implemented method 'GetFieldFloat'
		// Here lies the not-yet-implemented method 'GetFieldString'
		// Here lies the not-yet-implemented method 'AddMarshalEventDelegate'
		// Here lies the not-yet-implemented method 'ClearMarshalEventDelegate'
		// Here lies the not-yet-implemented method 'SendCtrlRequest'
		// Here lies the not-yet-implemented method 'SendGameRequest'
		// Here lies the not-yet-implemented method 'HandlePlayerCommandInput'
	};
}
#undef ADD_STRUCT
