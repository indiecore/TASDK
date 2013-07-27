#pragma once
#include "Engine.HUD.h"
namespace UnrealScript
{
	class DebugCameraHUD : public HUD
	{
	public:
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DebugCameraHUD.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool DisplayMaterials(float X, float& Y, float DY, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* MeshComp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DebugCameraHUD.DisplayMaterials");
			byte params[20] = { NULL };
			*(float*)&params[0] = X;
			*(float*)&params[4] = Y;
			*(float*)&params[8] = DY;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[12] = MeshComp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Y = *(float*)&params[4];
			return *(bool*)&params[16];
		}
		void PostRender()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DebugCameraHUD.PostRender");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
