#pragma once
#include "Engine.Texture.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.Texture2DComposite." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class Texture2DComposite : public Texture
	{
	public:
		ADD_VAR(::IntProperty, MaxTextureSize, 0xFFFFFFFF)
		bool SourceTexturesFullyStreamedIn()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Texture2DComposite.SourceTexturesFullyStreamedIn");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void UpdateCompositeTexture(int NumMipsToGenerate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Texture2DComposite.UpdateCompositeTexture");
			byte* params = (byte*)malloc(4);
			*(int*)params = NumMipsToGenerate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ResetSourceRegions()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Texture2DComposite.ResetSourceRegions");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
