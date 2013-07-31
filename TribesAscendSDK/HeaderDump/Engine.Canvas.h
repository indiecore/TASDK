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
		struct CanvasIcon
		{
		public:
			ADD_STRUCT(float, VL, 16)
			ADD_STRUCT(float, UL, 12)
			ADD_STRUCT(float, V, 8)
			ADD_STRUCT(float, U, 4)
			ADD_OBJECT(Texture, Texture, 0)
		};
		struct DepthFieldGlowInfo
		{
		public:
			ADD_STRUCT(Object::Vector2D, GlowInnerRadius, 28)
			ADD_STRUCT(Object::Vector2D, GlowOuterRadius, 20)
			ADD_STRUCT(Object::LinearColor, GlowColor, 4)
			ADD_BOOL(bEnableGlow, 0, 0x1)
		};
		struct FontRenderInfo
		{
		public:
			ADD_STRUCT(Canvas::DepthFieldGlowInfo, GlowInfo, 4)
			ADD_BOOL(bEnableShadow, 0, 0x2)
			ADD_BOOL(bClipText, 0, 0x1)
		};
		struct CanvasUVTri
		{
		public:
			ADD_STRUCT(Object::Vector2D, V2_UV, 40)
			ADD_STRUCT(Object::Vector2D, V2_Pos, 32)
			ADD_STRUCT(Object::Vector2D, V1_UV, 24)
			ADD_STRUCT(Object::Vector2D, V1_Pos, 16)
			ADD_STRUCT(Object::Vector2D, V0_UV, 8)
			ADD_STRUCT(Object::Vector2D, V0_Pos, 0)
		};
		struct TextSizingParameters
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
		struct WrappedStringElement
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4180);
			byte params[12] = { NULL };
			*(float*)params = PosX;
			*(float*)&params[4] = PosY;
			*(float*)&params[8] = PosZ;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetDrawColor(byte R, byte G, byte B, byte A)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4181);
			byte params[4] = { NULL };
			*params = R;
			params[1] = G;
			params[2] = B;
			params[3] = A;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawText(ScriptString* Text, bool CR, float XScale, float YScale, Canvas::FontRenderInfo& RenderInfo)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4183);
			byte params[64] = { NULL };
			*(ScriptString**)params = Text;
			*(bool*)&params[12] = CR;
			*(float*)&params[16] = XScale;
			*(float*)&params[20] = YScale;
			*(Canvas::FontRenderInfo*)&params[24] = RenderInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			RenderInfo = *(Canvas::FontRenderInfo*)&params[24];
		}
		Vector Project(Vector Location)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9338);
			byte params[24] = { NULL };
			*(Vector*)params = Location;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[12];
		}
		void StrLen(ScriptString* String, float& XL, float& YL)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12128);
			byte params[20] = { NULL };
			*(ScriptString**)params = String;
			*(float*)&params[12] = XL;
			*(float*)&params[16] = YL;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			XL = *(float*)&params[12];
			YL = *(float*)&params[16];
		}
		void DrawTile(class Texture* Tex, float XL, float YL, float U, float V, float UL, float VL, Object::LinearColor LColor, bool ClipTile, EngineTypes::EBlendMode Blend)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12443);
			byte params[49] = { NULL };
			*(class Texture**)params = Tex;
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12454);
			byte params[9] = { NULL };
			*(int*)params = Num;
			*(class Texture**)&params[4] = Tex;
			*(EngineTypes::EBlendMode*)&params[8] = Blend;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawMaterialTile(class MaterialInterface* Mat, float XL, float YL, float U, float V, float UL, float VL, bool bClipTile)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12458);
			byte params[32] = { NULL };
			*(class MaterialInterface**)params = Mat;
			*(float*)&params[4] = XL;
			*(float*)&params[8] = YL;
			*(float*)&params[12] = U;
			*(float*)&params[16] = V;
			*(float*)&params[20] = UL;
			*(float*)&params[24] = VL;
			*(bool*)&params[28] = bClipTile;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawRotatedTile(class Texture* Tex, Rotator Rotation, float XL, float YL, float U, float V, float UL, float VL, float AnchorX, float AnchorY)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12467);
			byte params[48] = { NULL };
			*(class Texture**)params = Tex;
			*(Rotator*)&params[4] = Rotation;
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
		void DrawRotatedMaterialTile(class MaterialInterface* Mat, Rotator Rotation, float XL, float YL, float U, float V, float UL, float VL, float AnchorX, float AnchorY)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12478);
			byte params[48] = { NULL };
			*(class MaterialInterface**)params = Mat;
			*(Rotator*)&params[4] = Rotation;
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12489);
			byte params[56] = { NULL };
			*(class Texture**)params = Tex;
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12501);
			byte params[16] = { NULL };
			*(class Texture**)params = Tex;
			*(ScriptArray<Canvas::CanvasUVTri>*)&params[4] = Triangles;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		Canvas::FontRenderInfo CreateFontRenderInfo(bool bClipText, bool bEnableShadow, Object::LinearColor GlowColor, Object::Vector2D GlowOuterRadius, Object::Vector2D GlowInnerRadius)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12505);
			byte params[80] = { NULL };
			*(bool*)params = bClipText;
			*(bool*)&params[4] = bEnableShadow;
			*(Object::LinearColor*)&params[8] = GlowColor;
			*(Object::Vector2D*)&params[24] = GlowOuterRadius;
			*(Object::Vector2D*)&params[32] = GlowInnerRadius;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Canvas::FontRenderInfo*)&params[40];
		}
		void TextSize(ScriptString* String, float& XL, float& YL)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12516);
			byte params[20] = { NULL };
			*(ScriptString**)params = String;
			*(float*)&params[12] = XL;
			*(float*)&params[16] = YL;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			XL = *(float*)&params[12];
			YL = *(float*)&params[16];
		}
		void DeProject(Object::Vector2D ScreenPos, Vector& WorldOrigin, Vector& WorldDirection)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12526);
			byte params[32] = { NULL };
			*(Object::Vector2D*)params = ScreenPos;
			*(Vector*)&params[8] = WorldOrigin;
			*(Vector*)&params[20] = WorldDirection;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			WorldOrigin = *(Vector*)&params[8];
			WorldDirection = *(Vector*)&params[20];
		}
		void PushTranslationMatrix(Vector TranslationVector)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12530);
			byte params[12] = { NULL };
			*(Vector*)params = TranslationVector;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PopTransform()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12532);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Reset(bool bKeepOrigin)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12533);
			byte params[4] = { NULL };
			*(bool*)params = bKeepOrigin;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetOrigin(float X, float Y)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12538);
			byte params[8] = { NULL };
			*(float*)params = X;
			*(float*)&params[4] = Y;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetClip(float X, float Y)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12541);
			byte params[8] = { NULL };
			*(float*)params = X;
			*(float*)&params[4] = Y;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawTexture(class Texture* Tex, float Scale)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12544);
			byte params[8] = { NULL };
			*(class Texture**)params = Tex;
			*(float*)&params[4] = Scale;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawTextureBlended(class Texture* Tex, float Scale, EngineTypes::EBlendMode Blend)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12547);
			byte params[9] = { NULL };
			*(class Texture**)params = Tex;
			*(float*)&params[4] = Scale;
			*(EngineTypes::EBlendMode*)&params[8] = Blend;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		Canvas::CanvasIcon MakeIcon(class Texture* Texture, float U, float V, float UL, float VL)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12552);
			byte params[40] = { NULL };
			*(class Texture**)params = Texture;
			*(float*)&params[4] = U;
			*(float*)&params[8] = V;
			*(float*)&params[12] = UL;
			*(float*)&params[16] = VL;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Canvas::CanvasIcon*)&params[20];
		}
		void DrawIcon(Canvas::CanvasIcon Icon, float X, float Y, float Scale)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12560);
			byte params[32] = { NULL };
			*(Canvas::CanvasIcon*)params = Icon;
			*(float*)&params[20] = X;
			*(float*)&params[24] = Y;
			*(float*)&params[28] = Scale;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawRect(float RectX, float RectY, class Texture* Tex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12565);
			byte params[12] = { NULL };
			*(float*)params = RectX;
			*(float*)&params[4] = RectY;
			*(class Texture**)&params[8] = Tex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawBox(float Width, float Height)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12569);
			byte params[8] = { NULL };
			*(float*)params = Width;
			*(float*)&params[4] = Height;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetDrawColorStruct(Object::Color C)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12578);
			byte params[4] = { NULL };
			*(Object::Color*)params = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Draw2DLine(float X1, float Y1, float X2, float Y2, Object::Color LineColor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12580);
			byte params[20] = { NULL };
			*(float*)params = X1;
			*(float*)&params[4] = Y1;
			*(float*)&params[8] = X2;
			*(float*)&params[12] = Y2;
			*(Object::Color*)&params[16] = LineColor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawTextureLine(Vector StartPoint, Vector EndPoint, float Perc, float Width, Object::Color LineColor, class Texture* LineTexture, float U, float V, float UL, float VL)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12586);
			byte params[56] = { NULL };
			*(Vector*)params = StartPoint;
			*(Vector*)&params[12] = EndPoint;
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
		void DrawTextureDoubleLine(Vector StartPoint, Vector EndPoint, float Perc, float Spacing, float Width, Object::Color LineColor, Object::Color AltLineColor, class Texture* Tex, float U, float V, float UL, float VL)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12597);
			byte params[64] = { NULL };
			*(Vector*)params = StartPoint;
			*(Vector*)&params[12] = EndPoint;
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12610);
			byte params[52] = { NULL };
			*(ScriptString**)params = Title;
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
