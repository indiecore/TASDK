#pragma once
#include "TribesGame.TrDeployable_BaseTurret.h"
#include "TribesGame.TrHelpTextManager.h"
#include "Engine.Texture2D.h"
namespace UnrealScript
{
	class TrBaseTurret_Neutral : public TrDeployable_BaseTurret
	{
	public:
		bool ShouldShowHelpText(TrHelpTextManager::EHelpTextType HelpTextType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrBaseTurret_Neutral.ShouldShowHelpText");
			byte params[5] = { NULL };
			*(TrHelpTextManager::EHelpTextType*)&params[0] = HelpTextType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		class Texture2D* GetMarker()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrBaseTurret_Neutral.GetMarker");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Texture2D**)&params[0];
		}
	};
}
