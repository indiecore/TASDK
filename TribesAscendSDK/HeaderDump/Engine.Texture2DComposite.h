#pragma once
#include "Engine.Texture.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class Texture2DComposite : public Texture
	{
	public:
		class SourceTexture2DRegion
		{
		public:
			ADD_OBJECT(Texture2D, Texture2D, 16)
			ADD_STRUCT(int, SizeY, 12)
			ADD_STRUCT(int, SizeX, 8)
			ADD_STRUCT(int, OffsetY, 4)
			ADD_STRUCT(int, OffsetX, 0)
		};
		ADD_STRUCT(ScriptArray<Texture2DComposite::SourceTexture2DRegion>, SourceRegions, 236)
		ADD_STRUCT(int, MaxTextureSize, 248)
		bool SourceTexturesFullyStreamedIn()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Texture2DComposite.SourceTexturesFullyStreamedIn");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void UpdateCompositeTexture(int NumMipsToGenerate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Texture2DComposite.UpdateCompositeTexture");
			byte params[4] = { NULL };
			*(int*)&params[0] = NumMipsToGenerate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ResetSourceRegions()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Texture2DComposite.ResetSourceRegions");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
