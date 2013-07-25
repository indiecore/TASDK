#pragma once
#include "Core__Object.h"
#include "Engine__Texture.h"
#include "Engine__Texture2D.h"
#include "Engine__Font.h"
#include "Engine__MaterialInterface.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.Canvas." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.Canvas." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.Canvas." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class Canvas : public Object
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'DrawColor'!
		ADD_OBJECT(Font, Font)
		ADD_OBJECT(Texture2D, DefaultTexture)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Plane' for the property named 'ColorModulate'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'SceneView'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'Canvas'!
		ADD_VAR(::IntProperty, SizeY, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SizeX, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bNoSmooth, 0x2)
		ADD_VAR(::BoolProperty, bCenter, 0x1)
		ADD_VAR(::FloatProperty, CurYL, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CurZ, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CurY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CurX, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ClipY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ClipX, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OrgY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OrgX, 0xFFFFFFFF)
		void SetPos(float PosX, float PosY, float PosZ)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Canvas.SetPos");
			byte* params = (byte*)malloc(12);
			*(float*)params = PosX;
			*(float*)(params + 4) = PosY;
			*(float*)(params + 8) = PosZ;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetDrawColor(byte R, byte G, byte B, byte A)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Canvas.SetDrawColor");
			byte* params = (byte*)malloc(4);
			*params = R;
			*(params + 1) = G;
			*(params + 2) = B;
			*(params + 3) = A;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DrawText(ScriptArray<wchar_t> Text, bool CR, float XScale, float YScale, 
// WARNING: Unknown structure type 'ScriptStruct Engine.Canvas.FontRenderInfo'!
void*& RenderInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Canvas.DrawText");
			byte* params = (byte*)malloc(64);
			*(ScriptArray<wchar_t>*)params = Text;
			*(bool*)(params + 12) = CR;
			*(float*)(params + 16) = XScale;
			*(float*)(params + 20) = YScale;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Canvas.FontRenderInfo'!
void**)(params + 24) = RenderInfo;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			RenderInfo = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.Canvas.FontRenderInfo'!
void**)(params + 24);
			free(params);
		}
		Vector Project(Vector Location)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Canvas.Project");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = Location;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 12);
			free(params);
			return returnVal;
		}
		void StrLen(ScriptArray<wchar_t> String, float& XL, float& YL)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Canvas.StrLen");
			byte* params = (byte*)malloc(20);
			*(ScriptArray<wchar_t>*)params = String;
			*(float*)(params + 12) = XL;
			*(float*)(params + 16) = YL;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			XL = *(float*)(params + 12);
			YL = *(float*)(params + 16);
			free(params);
		}
		void DrawTile(class Texture* Tex, float XL, float YL, float U, float V, float UL, float VL, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor'!
void* LColor, bool ClipTile, byte Blend)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Canvas.DrawTile");
			byte* params = (byte*)malloc(49);
			*(class Texture**)params = Tex;
			*(float*)(params + 4) = XL;
			*(float*)(params + 8) = YL;
			*(float*)(params + 12) = U;
			*(float*)(params + 16) = V;
			*(float*)(params + 20) = UL;
			*(float*)(params + 24) = VL;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor'!
void**)(params + 28) = LColor;
			*(bool*)(params + 44) = ClipTile;
			*(params + 48) = Blend;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PreOptimizeDrawTiles(int Num, class Texture* Tex, byte Blend)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Canvas.PreOptimizeDrawTiles");
			byte* params = (byte*)malloc(9);
			*(int*)params = Num;
			*(class Texture**)(params + 4) = Tex;
			*(params + 8) = Blend;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DrawMaterialTile(class MaterialInterface* Mat, float XL, float YL, float U, float V, float UL, float VL, bool bClipTile)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Canvas.DrawMaterialTile");
			byte* params = (byte*)malloc(32);
			*(class MaterialInterface**)params = Mat;
			*(float*)(params + 4) = XL;
			*(float*)(params + 8) = YL;
			*(float*)(params + 12) = U;
			*(float*)(params + 16) = V;
			*(float*)(params + 20) = UL;
			*(float*)(params + 24) = VL;
			*(bool*)(params + 28) = bClipTile;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DrawRotatedTile(class Texture* Tex, Rotator Rotation, float XL, float YL, float U, float V, float UL, float VL, float AnchorX, float AnchorY)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Canvas.DrawRotatedTile");
			byte* params = (byte*)malloc(48);
			*(class Texture**)params = Tex;
			*(Rotator*)(params + 4) = Rotation;
			*(float*)(params + 16) = XL;
			*(float*)(params + 20) = YL;
			*(float*)(params + 24) = U;
			*(float*)(params + 28) = V;
			*(float*)(params + 32) = UL;
			*(float*)(params + 36) = VL;
			*(float*)(params + 40) = AnchorX;
			*(float*)(params + 44) = AnchorY;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DrawRotatedMaterialTile(class MaterialInterface* Mat, Rotator Rotation, float XL, float YL, float U, float V, float UL, float VL, float AnchorX, float AnchorY)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Canvas.DrawRotatedMaterialTile");
			byte* params = (byte*)malloc(48);
			*(class MaterialInterface**)params = Mat;
			*(Rotator*)(params + 4) = Rotation;
			*(float*)(params + 16) = XL;
			*(float*)(params + 20) = YL;
			*(float*)(params + 24) = U;
			*(float*)(params + 28) = V;
			*(float*)(params + 32) = UL;
			*(float*)(params + 36) = VL;
			*(float*)(params + 40) = AnchorX;
			*(float*)(params + 44) = AnchorY;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DrawTileStretched(class Texture* Tex, float XL, float YL, float U, float V, float UL, float VL, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor'!
void* LColor, bool bStretchHorizontally, bool bStretchVertically, float ScalingFactor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Canvas.DrawTileStretched");
			byte* params = (byte*)malloc(56);
			*(class Texture**)params = Tex;
			*(float*)(params + 4) = XL;
			*(float*)(params + 8) = YL;
			*(float*)(params + 12) = U;
			*(float*)(params + 16) = V;
			*(float*)(params + 20) = UL;
			*(float*)(params + 24) = VL;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor'!
void**)(params + 28) = LColor;
			*(bool*)(params + 44) = bStretchHorizontally;
			*(bool*)(params + 48) = bStretchVertically;
			*(float*)(params + 52) = ScalingFactor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DrawTris(class Texture* Tex, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void* Triangles)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Canvas.DrawTris");
			byte* params = (byte*)malloc(16);
			*(class Texture**)params = Tex;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4) = Triangles;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		
// WARNING: Unknown structure type 'ScriptStruct Engine.Canvas.FontRenderInfo'!
void* CreateFontRenderInfo(bool bClipText, bool bEnableShadow, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor'!
void* GlowColor, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void* GlowOuterRadius, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void* GlowInnerRadius)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Canvas.CreateFontRenderInfo");
			byte* params = (byte*)malloc(80);
			*(bool*)params = bClipText;
			*(bool*)(params + 4) = bEnableShadow;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor'!
void**)(params + 8) = GlowColor;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void**)(params + 24) = GlowOuterRadius;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void**)(params + 32) = GlowInnerRadius;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.Canvas.FontRenderInfo'!
void**)(params + 40);
			free(params);
			return returnVal;
		}
		void TextSize(ScriptArray<wchar_t> String, float& XL, float& YL)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Canvas.TextSize");
			byte* params = (byte*)malloc(20);
			*(ScriptArray<wchar_t>*)params = String;
			*(float*)(params + 12) = XL;
			*(float*)(params + 16) = YL;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			XL = *(float*)(params + 12);
			YL = *(float*)(params + 16);
			free(params);
		}
		void DeProject(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void* ScreenPos, Vector& WorldOrigin, Vector& WorldDirection)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Canvas.DeProject");
			byte* params = (byte*)malloc(32);
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void**)params = ScreenPos;
			*(Vector*)(params + 8) = WorldOrigin;
			*(Vector*)(params + 20) = WorldDirection;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			WorldOrigin = *(Vector*)(params + 8);
			WorldDirection = *(Vector*)(params + 20);
			free(params);
		}
		void PushTranslationMatrix(Vector TranslationVector)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Canvas.PushTranslationMatrix");
			byte* params = (byte*)malloc(12);
			*(Vector*)params = TranslationVector;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PopTransform()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Canvas.PopTransform");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Reset(bool bKeepOrigin)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Canvas.Reset");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bKeepOrigin;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetOrigin(float X, float Y)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Canvas.SetOrigin");
			byte* params = (byte*)malloc(8);
			*(float*)params = X;
			*(float*)(params + 4) = Y;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetClip(float X, float Y)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Canvas.SetClip");
			byte* params = (byte*)malloc(8);
			*(float*)params = X;
			*(float*)(params + 4) = Y;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DrawTexture(class Texture* Tex, float Scale)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Canvas.DrawTexture");
			byte* params = (byte*)malloc(8);
			*(class Texture**)params = Tex;
			*(float*)(params + 4) = Scale;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DrawTextureBlended(class Texture* Tex, float Scale, byte Blend)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Canvas.DrawTextureBlended");
			byte* params = (byte*)malloc(9);
			*(class Texture**)params = Tex;
			*(float*)(params + 4) = Scale;
			*(params + 8) = Blend;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		
// WARNING: Unknown structure type 'ScriptStruct Engine.Canvas.CanvasIcon'!
void* MakeIcon(class Texture* Texture, float U, float V, float UL, float VL)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Canvas.MakeIcon");
			byte* params = (byte*)malloc(40);
			*(class Texture**)params = Texture;
			*(float*)(params + 4) = U;
			*(float*)(params + 8) = V;
			*(float*)(params + 12) = UL;
			*(float*)(params + 16) = VL;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.Canvas.CanvasIcon'!
void**)(params + 20);
			free(params);
			return returnVal;
		}
		void DrawIcon(
// WARNING: Unknown structure type 'ScriptStruct Engine.Canvas.CanvasIcon'!
void* Icon, float X, float Y, float Scale)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Canvas.DrawIcon");
			byte* params = (byte*)malloc(32);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Canvas.CanvasIcon'!
void**)params = Icon;
			*(float*)(params + 20) = X;
			*(float*)(params + 24) = Y;
			*(float*)(params + 28) = Scale;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DrawRect(float RectX, float RectY, class Texture* Tex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Canvas.DrawRect");
			byte* params = (byte*)malloc(12);
			*(float*)params = RectX;
			*(float*)(params + 4) = RectY;
			*(class Texture**)(params + 8) = Tex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DrawBox(float Width, float Height)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Canvas.DrawBox");
			byte* params = (byte*)malloc(8);
			*(float*)params = Width;
			*(float*)(params + 4) = Height;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetDrawColorStruct(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Canvas.SetDrawColorStruct");
			byte* params = (byte*)malloc(4);
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Draw2DLine(float X1, float Y1, float X2, float Y2, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void* LineColor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Canvas.Draw2DLine");
			byte* params = (byte*)malloc(20);
			*(float*)params = X1;
			*(float*)(params + 4) = Y1;
			*(float*)(params + 8) = X2;
			*(float*)(params + 12) = Y2;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void**)(params + 16) = LineColor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DrawTextureLine(Vector StartPoint, Vector EndPoint, float Perc, float Width, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void* LineColor, class Texture* LineTexture, float U, float V, float UL, float VL)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Canvas.DrawTextureLine");
			byte* params = (byte*)malloc(56);
			*(Vector*)params = StartPoint;
			*(Vector*)(params + 12) = EndPoint;
			*(float*)(params + 24) = Perc;
			*(float*)(params + 28) = Width;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void**)(params + 32) = LineColor;
			*(class Texture**)(params + 36) = LineTexture;
			*(float*)(params + 40) = U;
			*(float*)(params + 44) = V;
			*(float*)(params + 48) = UL;
			*(float*)(params + 52) = VL;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DrawTextureDoubleLine(Vector StartPoint, Vector EndPoint, float Perc, float Spacing, float Width, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void* LineColor, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void* AltLineColor, class Texture* Tex, float U, float V, float UL, float VL)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Canvas.DrawTextureDoubleLine");
			byte* params = (byte*)malloc(64);
			*(Vector*)params = StartPoint;
			*(Vector*)(params + 12) = EndPoint;
			*(float*)(params + 24) = Perc;
			*(float*)(params + 28) = Spacing;
			*(float*)(params + 32) = Width;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void**)(params + 36) = LineColor;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void**)(params + 40) = AltLineColor;
			*(class Texture**)(params + 44) = Tex;
			*(float*)(params + 48) = U;
			*(float*)(params + 52) = V;
			*(float*)(params + 56) = UL;
			*(float*)(params + 60) = VL;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DrawDebugGraph(ScriptArray<wchar_t> Title, float ValueX, float ValueY, float UL_X, float UL_Y, float W, float H, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void* RangeX, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void* RangeY)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Canvas.DrawDebugGraph");
			byte* params = (byte*)malloc(52);
			*(ScriptArray<wchar_t>*)params = Title;
			*(float*)(params + 12) = ValueX;
			*(float*)(params + 16) = ValueY;
			*(float*)(params + 20) = UL_X;
			*(float*)(params + 24) = UL_Y;
			*(float*)(params + 28) = W;
			*(float*)(params + 32) = H;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void**)(params + 36) = RangeX;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void**)(params + 44) = RangeY;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
