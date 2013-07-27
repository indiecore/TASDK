#pragma once
#include "Engine.OnlineGameSettings.h"
namespace UnrealScript
{
	class UDKGameSettingsCommon : public OnlineGameSettings
	{
	public:
		bool StringToBlob(ScriptString*& InString, ScriptString*& OutBlob)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKGameSettingsCommon.StringToBlob");
			byte params[28] = { NULL };
			*(ScriptString**)&params[0] = InString;
			*(ScriptString**)&params[12] = OutBlob;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			InString = *(ScriptString**)&params[0];
			OutBlob = *(ScriptString**)&params[12];
			return *(bool*)&params[24];
		}
		ScriptString* BlobToString(ScriptString*& InBlob)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKGameSettingsCommon.BlobToString");
			byte params[24] = { NULL };
			*(ScriptString**)&params[0] = InBlob;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			InBlob = *(ScriptString**)&params[0];
			return *(ScriptString**)&params[12];
		}
	};
}
