#pragma once
#include "Engine.OnlineGameSettings.h"
namespace UnrealScript
{
	class UDKGameSettingsCommon : public OnlineGameSettings
	{
	public:
		bool StringToBlob(ScriptString*& InString, ScriptString*& OutBlob)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34897);
			byte params[28] = { NULL };
			*(ScriptString**)params = InString;
			*(ScriptString**)&params[12] = OutBlob;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			InString = *(ScriptString**)params;
			OutBlob = *(ScriptString**)&params[12];
			return *(bool*)&params[24];
		}
		ScriptString* BlobToString(ScriptString*& InBlob)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34901);
			byte params[24] = { NULL };
			*(ScriptString**)params = InBlob;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			InBlob = *(ScriptString**)params;
			return *(ScriptString**)&params[12];
		}
	};
}
