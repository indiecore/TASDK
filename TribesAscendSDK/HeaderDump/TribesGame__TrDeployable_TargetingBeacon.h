#pragma once
#include "Engine__Texture2D.h"
#include "Engine__Canvas.h"
#include "Engine__PlayerController.h"
#include "TribesGame__TrDeployable_RadarSensor.h"
namespace UnrealScript
{
	class TrDeployable_TargetingBeacon : public TrDeployable_RadarSensor
	{
	public:
		void PostRenderFor(class PlayerController* PC, class Canvas* Canvas, Vector CameraPosition, Vector CameraDir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_TargetingBeacon.PostRenderFor");
			byte* params = (byte*)malloc(32);
			*(class PlayerController**)params = PC;
			*(class Canvas**)(params + 4) = Canvas;
			*(Vector*)(params + 8) = CameraPosition;
			*(Vector*)(params + 20) = CameraDir;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RenderForTeammate(class PlayerController* PC, class Canvas* Canvas, Vector CameraPosition, Vector CameraDir, float Distance)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_TargetingBeacon.RenderForTeammate");
			byte* params = (byte*)malloc(36);
			*(class PlayerController**)params = PC;
			*(class Canvas**)(params + 4) = Canvas;
			*(Vector*)(params + 8) = CameraPosition;
			*(Vector*)(params + 20) = CameraDir;
			*(float*)(params + 32) = Distance;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class Texture2D* GetMarker()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDeployable_TargetingBeacon.GetMarker");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Texture2D**)params;
			free(params);
			return returnVal;
		}
	};
}
