#pragma once
#include "Core.Object.h"
#include "Engine.Texture2D.h"
#include "Engine.FontImportOptions.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class Font : public Object
	{
	public:
		static const auto NULLCHARACTER = 127;
		struct FontCharacter
		{
		public:
			ADD_STRUCT(int, VerticalOffset, 20)
			ADD_STRUCT(byte, TextureIndex, 16)
			ADD_STRUCT(int, VSize, 12)
			ADD_STRUCT(int, USize, 8)
			ADD_STRUCT(int, StartV, 4)
			ADD_STRUCT(int, StartU, 0)
		};
		ADD_STRUCT(ScriptArray<Font::FontCharacter>, Characters, 60)
		ADD_STRUCT(ScriptArray<class Texture2D*>, Textures, 72)
		ADD_STRUCT(ScriptArray<int>, MaxCharHeight, 320)
		ADD_STRUCT(int, NumCharacters, 316)
		ADD_STRUCT(FontImportOptions::FontImportOptionsData, ImportOptions, 168)
		ADD_STRUCT(int, Kerning, 164)
		ADD_STRUCT(float, Leading, 160)
		ADD_STRUCT(float, Descent, 156)
		ADD_STRUCT(float, Ascent, 152)
		ADD_STRUCT(float, EmScale, 148)
		ADD_STRUCT(int, IsRemapped, 144)
		int GetResolutionPageIndex(float HeightTest)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12378);
			byte params[8] = { NULL };
			*(float*)params = HeightTest;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		float GetScalingFactor(float HeightTest)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12381);
			byte params[8] = { NULL };
			*(float*)params = HeightTest;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		float GetAuthoredViewportHeight(float ViewportHeight)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12384);
			byte params[8] = { NULL };
			*(float*)params = ViewportHeight;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		float GetMaxCharHeight()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12387);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		void GetStringHeightAndWidth(ScriptString*& InString, int& Height, int& Width)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12389);
			byte params[20] = { NULL };
			*(ScriptString**)params = InString;
			*(int*)&params[12] = Height;
			*(int*)&params[16] = Width;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			InString = *(ScriptString**)params;
			Height = *(int*)&params[12];
			Width = *(int*)&params[16];
		}
	};
}
#undef ADD_STRUCT
