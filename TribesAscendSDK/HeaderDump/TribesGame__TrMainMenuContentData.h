#pragma once
#include "Core__Object.h"
#include "TribesGame__TrPaperDollMainMenu.h"
namespace UnrealScript
{
	class TrMainMenuContentData : public Object
	{
	public:
		void SendPaperDollANewMesh(class TrPaperDollMainMenu* MainMenuPaperDoll, byte ContentDataType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrMainMenuContentData.SendPaperDollANewMesh");
			byte* params = (byte*)malloc(5);
			*(class TrPaperDollMainMenu**)params = MainMenuPaperDoll;
			*(params + 4) = ContentDataType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PreloadTextures(float ForceDuration)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrMainMenuContentData.PreloadTextures");
			byte* params = (byte*)malloc(4);
			*(float*)params = ForceDuration;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
