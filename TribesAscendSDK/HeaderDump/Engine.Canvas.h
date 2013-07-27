#pragma once
#include "Core.Object.h"
#include "Engine.Texture2D.h"
#include "Engine.Font.h"
#include "Engine.Texture.h"
#include "Engine.MaterialInterface.h"
#include "Engine.EngineTypes.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
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
	class Canvas : public Object
	{
	public:
		class CanvasIcon
		{
		public:
			ADD_STRUCT(float, VL, 16)
			ADD_STRUCT(float, UL, 12)
			ADD_STRUCT(float, V, 8)
			ADD_STRUCT(float, U, 4)
			ADD_OBJECT(Texture, Texture, 0)
		};
		class DepthFieldGlowInfo
		{
		public:
			ADD_STRUCT(Object::Vector2D, GlowInnerRadius, 28)
			ADD_STRUCT(Object::Vector2D, GlowOuterRadius, 20)
			ADD_STRUCT(Object::LinearColor, GlowColor, 4)
			ADD_BOOL(bEnableGlow, 0, 0x1)
		};
		class FontRenderInfo
		{
		public:
			ADD_STRUCT(Canvas::DepthFieldGlowInfo, GlowInfo, 4)
			ADD_BOOL(bEnableShadow, 0, 0x2)
			ADD_BOOL(bClipText, 0, 0x1)
		};
		class CanvasUVTri
		{
		public:
			ADD_STRUCT(Object::Vector2D, V2_UV, 40)
			ADD_STRUCT(Object::Vector2D, V2_Pos, 32)
			ADD_STRUCT(Object::Vector2D, V1_UV, 24)
			ADD_STRUCT(Object::Vector2D, V1_Pos, 16)
			ADD_STRUCT(Object::Vector2D, V0_UV, 8)
			ADD_STRUCT(Object::Vector2D, V0_Pos, 0)
		};
		class TextSizingParameters
		{
		public:
			ADD_STRUCT(float, ViewportHeight, 36)
			ADD_STRUCT(Object::Vector2D, SpacingAdjust, 28)
			ADD_OBJECT(Font, DrawFont, 24)
			ADD_STRUCT(Object::Vector2D, Scaling, 16)
			ADD_STRUCT(float, DrawYL, 12)
			ADD_STRUCT(float, DrawXL, 8)
			ADD_STRUCT(float, DrawY, 4)
			ADD_STRUCT(float, DrawX, 0)
		};
		class WrappedStringElement
		{
		public:
			ADD_STRUCT(Object::Vector2D, LineExtent, 12)
			ADD_STRUCT(ScriptString*, Value, 0)
		};
		ADD_STRUCT(Object::Color, DrawColor, 96)
		ADD_OBJECT(Font, Font, 60)
		ADD_OBJECT(Texture2D, DefaultTexture, 144)
		ADD_STRUCT(Object::Plane, ColorModulate, 128)
		ADD_STRUCT(Object::Pointer, SceneView, 116)
		ADD_STRUCT(Object::Pointer, Canvas, 112)
		ADD_STRUCT(int, SizeY, 108)
		ADD_STRUCT(int, SizeX, 104)
		ADD_BOOL(bNoSmooth, 100, 0x2)
		ADD_BOOL(bCenter, 100, 0x1)
		ADD_STRUCT(float, CurYL, 92)
		ADD_STRUCT(float, CurZ, 88)
		ADD_STRUCT(float, CurY, 84)
		ADD_STRUCT(float, CurX, 80)
		ADD_STRUCT(float, ClipY, 76)
		ADD_STRUCT(float, ClipX, 72)
		ADD_STRUCT(float, OrgY, 68)
		ADD_STRUCT(float, OrgX, 64)
		void SetPos(float PosX, float PosY, float PosZ)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Canvas.SetPos");
			byte params[12] = { NULL };
			*(float*)&params[0] = PosX;
			*(float*)&params[4] = PosY;
			*(float*)&params[8] = PosZ;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetDrawColor(byte R, byte G, byte B, byte A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Canvas.SetDrawColor");
			byte params[4] = { NULL };
			params[0] = R;
			params[1] = G;
			params[2] = B;
			params[3] = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawText(ScriptString* Text, bool CR, float XScale, float YScale, Canvas::FontRenderInfo& RenderInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Canvas.DrawText");
			byte params[64] = { NULL };
			*(ScriptString**)&params[0] = Text;
			*(bool*)&params[12] = CR;
			*(float*)&params[16] = XScale;
			*(float*)&params[20] = YScale;
			*(Canvas::FontRenderInfo*)&params[24] = RenderInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			RenderInfo = *(Canvas::FontRenderInfo*)&params[24];
		}
		Object::Vector Project(Object::Vector Location)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Canvas.Project");
			byte params[24] = { NULL };
			*(Object::Vector*)&params[0] = Location;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[12];
		}
		void StrLen(ScriptString* String, float& XL, float& YL)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Canvas.StrLen");
			byte params[20] = { NULL };
			*(ScriptString**)&params[0] = String;
			*(float*)&params[12] = XL;
			*(float*)&params[16] = YL;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			XL = *(float*)&params[12];
			YL = *(float*)&params[16];
		}
		void DrawTile(class Texture* Tex, float XL, float YL, float U, float V, float UL, float VL, Object::LinearColor LColor, bool ClipTile, EngineTypes::EBlendMode Blend)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Canvas.DrawTile");
			byte params[49] = { NULL };
			*(class Texture**)&params[0] = Tex;
			*(float*)&params[4] = XL;
			*(float*)&params[8] = YL;
			*(float*)&params[12] = U;
			*(float*)&params[16] = V;
			*(float*)&params[20] = UL;
			*(float*)&params[24] = VL;
			*(Object::LinearColor*)&params[28] = LColor;
			*(bool*)&params[44] = ClipTile;
			*(EngineTypes::EBlendMode*)&params[48] = Blend;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PreOptimizeDrawTiles(int Num, class Texture* Tex, EngineTypes::EBlendMode Blend)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Canvas.PreOptimizeDrawTiles");
			byte params[9] = { NULL };
			*(int*)&params[0] = Num;
			*(class Texture**)&params[4] = Tex;
			*(EngineTypes::EBlendMode*)&params[8] = Blend;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawMaterialTile(class MaterialInterface* Mat, float XL, float YL, float U, float V, float UL, float VL, bool bClipTile)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Canvas.DrawMaterialTile");
			byte params[32] = { NULL };
			*(class MaterialInterface**)&params[0] = Mat;
			*(float*)&params[4] = XL;
			*(float*)&params[8] = YL;
			*(float*)&params[12] = U;
			*(float*)&params[16] = V;
			*(float*)&params[20] = UL;
			*(float*)&params[24] = VL;
			*(bool*)&params[28] = bClipTile;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawRotatedTile(class Texture* Tex, Object::Rotator Rotation, float XL, float YL, float U, float V, float UL, float VL, float AnchorX, float AnchorY)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Canvas.DrawRotatedTile");
			byte params[48] = { NULL };
			*(class Texture**)&params[0] = Tex;
			*(Object::Rotator*)&params[4] = Rotation;
			*(float*)&params[16] = XL;
			*(float*)&params[20] = YL;
			*(float*)&params[24] = U;
			*(float*)&params[28] = V;
			*(float*)&params[32] = UL;
			*(float*)&params[36] = VL;
			*(float*)&params[40] = AnchorX;
			*(float*)&params[44] = AnchorY;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawRotatedMaterialTile(class MaterialInterface* Mat, Object::Rotator Rotation, float XL, float YL, float U, float V, float UL, float VL, float AnchorX, float AnchorY)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Canvas.DrawRotatedMaterialTile");
			byte params[48] = { NULL };
			*(class MaterialInterface**)&params[0] = Mat;
			*(Object::Rotator*)&params[4] = Rotation;
			*(float*)&params[16] = XL;
			*(float*)&params[20] = YL;
			*(float*)&params[24] = U;
			*(float*)&params[28] = V;
			*(float*)&params[32] = UL;
			*(float*)&params[36] = VL;
			*(float*)&params[40] = AnchorX;
			*(float*)&params[44] = AnchorY;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawTileStretched(class Texture* Tex, float XL, float YL, float U, float V, float UL, float VL, Object::LinearColor LColor, bool bStretchHorizontally, bool bStretchVertically, float ScalingFactor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Canvas.DrawTileStretched");
			byte params[56] = { NULL };
			*(class Texture**)&params[0] = Tex;
			*(float*)&params[4] = XL;
			*(float*)&params[8] = YL;
			*(float*)&params[12] = U;
			*(float*)&params[16] = V;
			*(float*)&params[20] = UL;
			*(float*)&params[24] = VL;
			*(Object::LinearColor*)&params[28] = LColor;
			*(bool*)&params[44] = bStretchHorizontally;
			*(bool*)&params[48] = bStretchVertically;
			*(float*)&params[52] = ScalingFactor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawTris(class Texture* Tex, ScriptArray<Canvas::CanvasUVTri> Triangles)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Canvas.DrawTris");
			byte params[16] = { NULL };
			*(class Texture**)&params[0] = Tex;
			*(ScriptArray<Canvas::CanvasUVTri>*)&params[4] = Triangles;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		Canvas::FontRenderInfo CreateFontRenderInfo(bool bClipText, bool bEnableShadow, Object::LinearColor GlowColor, Object::Vector2D GlowOuterRadius, Object::Vector2D GlowInnerRadius)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Canvas.CreateFontRenderInfo");
			byte params[80] = { NULL };
			*(bool*)&params[0] = bClipText;
			*(bool*)&params[4] = bEnableShadow;
			*(Object::LinearColor*)&params[8] = GlowColor;
			*(Object::Vector2D*)&params[24] = GlowOuterRadius;
			*(Object::Vector2D*)&params[32] = GlowInnerRadius;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Canvas::FontRenderInfo*)&params[40];
		}
		void TextSize(ScriptString* String, float& XL, float& YL)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Canvas.TextSize");
			byte params[20] = { NULL };
			*(ScriptString**)&params[0] = String;
			*(float*)&params[12] = XL;
			*(float*)&params[16] = YL;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			XL = *(float*)&params[12];
			YL = *(float*)&params[16];
		}
		void DeProject(Object::Vector2D ScreenPos, Object::Vector& WorldOrigin, Object::Vector& WorldDirection)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Canvas.DeProject");
			byte params[32] = { NULL };
			*(Object::Vector2D*)&params[0] = ScreenPos;
			*(Object::Vector*)&params[8] = WorldOrigin;
			*(Object::Vector*)&params[20] = WorldDirection;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			WorldOrigin = *(Object::Vector*)&params[8];
			WorldDirection = *(Object::Vector*)&params[20];
		}
		void PushTranslationMatrix(Object::Vector TranslationVector)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Canvas.PushTranslationMatrix");
			byte params[12] = { NULL };
			*(Object::Vector*)&params[0] = TranslationVector;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PopTransform()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Canvas.PopTransform");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Reset(bool bKeepOrigin)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Canvas.Reset");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bKeepOrigin;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetOrigin(float X, float Y)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Canvas.SetOrigin");
			byte params[8] = { NULL };
			*(float*)&params[0] = X;
			*(float*)&params[4] = Y;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetClip(float X, float Y)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Canvas.SetClip");
			byte params[8] = { NULL };
			*(float*)&params[0] = X;
			*(float*)&params[4] = Y;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawTexture(class Texture* Tex, float Scale)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Canvas.DrawTexture");
			byte params[8] = { NULL };
			*(class Texture**)&params[0] = Tex;
			*(float*)&params[4] = Scale;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawTextureBlended(class Texture* Tex, float Scale, EngineTypes::EBlendMode Blend)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Canvas.DrawTextureBlended");
			byte params[9] = { NULL };
			*(class Texture**)&params[0] = Tex;
			*(float*)&params[4] = Scale;
			*(EngineTypes::EBlendMode*)&params[8] = Blend;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		Canvas::CanvasIcon MakeIcon(class Texture* Texture, float U, float V, float UL, float VL)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Canvas.MakeIcon");
			byte params[40] = { NULL };
			*(class Texture**)&params[0] = Texture;
			*(float*)&params[4] = U;
			*(float*)&params[8] = V;
			*(float*)&params[12] = UL;
			*(float*)&params[16] = VL;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Canvas::CanvasIcon*)&params[20];
		}
		void DrawIcon(Canvas::CanvasIcon Icon, float X, float Y, float Scale)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Canvas.DrawIcon");
			byte params[32] = { NULL };
			*(Canvas::CanvasIcon*)&params[0] = Icon;
			*(float*)&params[20] = X;
			*(float*)&params[24] = Y;
			*(float*)&params[28] = Scale;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawRect(float RectX, float RectY, class Texture* Tex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Canvas.DrawRect");
			byte params[12] = { NULL };
			*(float*)&params[0] = RectX;
			*(float*)&params[4] = RectY;
			*(class Texture**)&params[8] = Tex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawBox(float Width, float Height)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Canvas.DrawBox");
			byte params[8] = { NULL };
			*(float*)&params[0] = Width;
			*(float*)&params[4] = Height;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetDrawColorStruct(Object::Color C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Canvas.SetDrawColorStruct");
			byte params[4] = { NULL };
			*(Object::Color*)&params[0] = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Draw2DLine(float X1, float Y1, float X2, float Y2, Object::Color LineColor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Canvas.Draw2DLine");
			byte params[20] = { NULL };
			*(float*)&params[0] = X1;
			*(float*)&params[4] = Y1;
			*(float*)&params[8] = X2;
			*(float*)&params[12] = Y2;
			*(Object::Color*)&params[16] = LineColor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawTextureLine(Object::Vector StartPoint, Object::Vector EndPoint, float Perc, float Width, Object::Color LineColor, class Texture* LineTexture, float U, float V, float UL, float VL)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Canvas.DrawTextureLine");
			byte params[56] = { NULL };
			*(Object::Vector*)&params[0] = StartPoint;
			*(Object::Vector*)&params[12] = EndPoint;
			*(float*)&params[24] = Perc;
			*(float*)&params[28] = Width;
			*(Object::Color*)&params[32] = LineColor;
			*(class Texture**)&params[36] = LineTexture;
			*(float*)&params[40] = U;
			*(float*)&params[44] = V;
			*(float*)&params[48] = UL;
			*(float*)&params[52] = VL;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawTextureDoubleLine(Object::Vector StartPoint, Object::Vector EndPoint, float Perc, float Spacing, float Width, Object::Color LineColor, Object::Color AltLineColor, class Texture* Tex, float U, float V, float UL, float VL)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Canvas.DrawTextureDoubleLine");
			byte params[64] = { NULL };
			*(Object::Vector*)&params[0] = StartPoint;
			*(Object::Vector*)&params[12] = EndPoint;
			*(float*)&params[24] = Perc;
			*(float*)&params[28] = Spacing;
			*(float*)&params[32] = Width;
			*(Object::Color*)&params[36] = LineColor;
			*(Object::Color*)&params[40] = AltLineColor;
			*(class Texture**)&params[44] = Tex;
			*(float*)&params[48] = U;
			*(float*)&params[52] = V;
			*(float*)&params[56] = UL;
			*(float*)&params[60] = VL;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawDebugGraph(ScriptString* Title, float ValueX, float ValueY, float UL_X, float UL_Y, float W, float H, Object::Vector2D RangeX, Object::Vector2D RangeY)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Canvas.DrawDebugGraph");
			byte params[52] = { NULL };
			*(ScriptString**)&params[0] = Title;
			*(float*)&params[12] = ValueX;
			*(float*)&params[16] = ValueY;
			*(float*)&params[20] = UL_X;
			*(float*)&params[24] = UL_Y;
			*(float*)&params[28] = W;
			*(float*)&params[32] = H;
			*(Object::Vector2D*)&params[36] = RangeX;
			*(Object::Vector2D*)&params[44] = RangeY;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
