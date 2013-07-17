#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.Canvas." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.Canvas." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.Canvas." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class Canvas : public Object
	{
	public:
			void SetPos( float PosX, float PosY, float PosZ )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Canvas.SetPos" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( float* )( params + 0 ) = PosX;
				*( float* )( params + 4 ) = PosY;
				*( float* )( params + 8 ) = PosZ;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetDrawColor( byte R, byte G, byte B, byte A )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Canvas.SetDrawColor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( byte* )( params + 0 ) = R;
				*( byte* )( params + 1 ) = G;
				*( byte* )( params + 2 ) = B;
				*( byte* )( params + 3 ) = A;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DrawText( ScriptArray< wchar_t > Text, bool CR, float XScale, float YScale, void* &RenderInfo )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Canvas.DrawText" );
				byte *params = ( byte* )( malloc( 64 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = Text;
				*( bool* )( params + 12 ) = CR;
				*( float* )( params + 16 ) = XScale;
				*( float* )( params + 20 ) = YScale;
				*( void** )( params + 24 ) = RenderInfo;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				RenderInfo = *( void** )( params + 24 );
			}

			ADD_OBJECT( Font, Font )
			Vector Project( Vector Location )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Canvas.Project" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )( params + 0 ) = Location;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			void StrLen( ScriptArray< wchar_t > String, float &XL, float &YL )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Canvas.StrLen" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = String;
				*( float* )( params + 12 ) = XL;
				*( float* )( params + 16 ) = YL;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				XL = *( float* )( params + 12 );
				YL = *( float* )( params + 16 );
			}

			ADD_OBJECT( Texture2D, DefaultTexture )
			ADD_VAR( ::IntProperty, SizeY, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, SizeX, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bNoSmooth, 0x2 )
			ADD_VAR( ::BoolProperty, bCenter, 0x1 )
			ADD_VAR( ::FloatProperty, CurYL, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CurZ, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CurY, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CurX, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ClipY, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ClipX, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, OrgY, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, OrgX, 0xFFFFFFFF )
			void DrawTile( class Texture* Tex, float XL, float YL, float U, float V, float UL, float VL, void* LColor, bool ClipTile, byte Blend )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Canvas.DrawTile" );
				byte *params = ( byte* )( malloc( 49 ) );
				*( class Texture** )( params + 0 ) = Tex;
				*( float* )( params + 4 ) = XL;
				*( float* )( params + 8 ) = YL;
				*( float* )( params + 12 ) = U;
				*( float* )( params + 16 ) = V;
				*( float* )( params + 20 ) = UL;
				*( float* )( params + 24 ) = VL;
				*( void** )( params + 28 ) = LColor;
				*( bool* )( params + 44 ) = ClipTile;
				*( byte* )( params + 48 ) = Blend;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PreOptimizeDrawTiles( int Num, class Texture* Tex, byte Blend )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Canvas.PreOptimizeDrawTiles" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( int* )( params + 0 ) = Num;
				*( class Texture** )( params + 4 ) = Tex;
				*( byte* )( params + 8 ) = Blend;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DrawMaterialTile( class MaterialInterface* Mat, float XL, float YL, float U, float V, float UL, float VL, bool bClipTile )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Canvas.DrawMaterialTile" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( class MaterialInterface** )( params + 0 ) = Mat;
				*( float* )( params + 4 ) = XL;
				*( float* )( params + 8 ) = YL;
				*( float* )( params + 12 ) = U;
				*( float* )( params + 16 ) = V;
				*( float* )( params + 20 ) = UL;
				*( float* )( params + 24 ) = VL;
				*( bool* )( params + 28 ) = bClipTile;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DrawRotatedTile( class Texture* Tex, Rotator Rotation, float XL, float YL, float U, float V, float UL, float VL, float AnchorX, float AnchorY )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Canvas.DrawRotatedTile" );
				byte *params = ( byte* )( malloc( 48 ) );
				*( class Texture** )( params + 0 ) = Tex;
				*( Rotator* )( params + 4 ) = Rotation;
				*( float* )( params + 16 ) = XL;
				*( float* )( params + 20 ) = YL;
				*( float* )( params + 24 ) = U;
				*( float* )( params + 28 ) = V;
				*( float* )( params + 32 ) = UL;
				*( float* )( params + 36 ) = VL;
				*( float* )( params + 40 ) = AnchorX;
				*( float* )( params + 44 ) = AnchorY;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DrawRotatedMaterialTile( class MaterialInterface* Mat, Rotator Rotation, float XL, float YL, float U, float V, float UL, float VL, float AnchorX, float AnchorY )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Canvas.DrawRotatedMaterialTile" );
				byte *params = ( byte* )( malloc( 48 ) );
				*( class MaterialInterface** )( params + 0 ) = Mat;
				*( Rotator* )( params + 4 ) = Rotation;
				*( float* )( params + 16 ) = XL;
				*( float* )( params + 20 ) = YL;
				*( float* )( params + 24 ) = U;
				*( float* )( params + 28 ) = V;
				*( float* )( params + 32 ) = UL;
				*( float* )( params + 36 ) = VL;
				*( float* )( params + 40 ) = AnchorX;
				*( float* )( params + 44 ) = AnchorY;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DrawTileStretched( class Texture* Tex, float XL, float YL, float U, float V, float UL, float VL, void* LColor, bool bStretchHorizontally, bool bStretchVertically, float ScalingFactor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Canvas.DrawTileStretched" );
				byte *params = ( byte* )( malloc( 56 ) );
				*( class Texture** )( params + 0 ) = Tex;
				*( float* )( params + 4 ) = XL;
				*( float* )( params + 8 ) = YL;
				*( float* )( params + 12 ) = U;
				*( float* )( params + 16 ) = V;
				*( float* )( params + 20 ) = UL;
				*( float* )( params + 24 ) = VL;
				*( void** )( params + 28 ) = LColor;
				*( bool* )( params + 44 ) = bStretchHorizontally;
				*( bool* )( params + 48 ) = bStretchVertically;
				*( float* )( params + 52 ) = ScalingFactor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DrawTris( class Texture* Tex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Canvas.DrawTris" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class Texture** )( params + 0 ) = Tex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void* CreateFontRenderInfo( bool bClipText, bool bEnableShadow, void* GlowColor, void* GlowOuterRadius, void* GlowInnerRadius )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Canvas.CreateFontRenderInfo" );
				byte *params = ( byte* )( malloc( 40 ) );
				*( bool* )( params + 0 ) = bClipText;
				*( bool* )( params + 4 ) = bEnableShadow;
				*( void** )( params + 8 ) = GlowColor;
				*( void** )( params + 24 ) = GlowOuterRadius;
				*( void** )( params + 32 ) = GlowInnerRadius;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			void TextSize( ScriptArray< wchar_t > String, float &XL, float &YL )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Canvas.TextSize" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = String;
				*( float* )( params + 12 ) = XL;
				*( float* )( params + 16 ) = YL;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				XL = *( float* )( params + 12 );
				YL = *( float* )( params + 16 );
			}

			void DeProject( void* ScreenPos, Vector &WorldOrigin, Vector &WorldDirection )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Canvas.DeProject" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( void** )( params + 0 ) = ScreenPos;
				*( Vector* )( params + 8 ) = WorldOrigin;
				*( Vector* )( params + 20 ) = WorldDirection;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				WorldOrigin = *( Vector* )( params + 8 );
				WorldDirection = *( Vector* )( params + 20 );
			}

			void PushTranslationMatrix( Vector TranslationVector )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Canvas.PushTranslationMatrix" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )( params + 0 ) = TranslationVector;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PopTransform(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Canvas.PopTransform" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Reset( bool bKeepOrigin )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Canvas.Reset" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bKeepOrigin;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetOrigin( float X, float Y )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Canvas.SetOrigin" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( float* )( params + 0 ) = X;
				*( float* )( params + 4 ) = Y;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetClip( float X, float Y )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Canvas.SetClip" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( float* )( params + 0 ) = X;
				*( float* )( params + 4 ) = Y;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DrawTexture( class Texture* Tex, float Scale )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Canvas.DrawTexture" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Texture** )( params + 0 ) = Tex;
				*( float* )( params + 4 ) = Scale;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DrawTextureBlended( class Texture* Tex, float Scale, byte Blend )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Canvas.DrawTextureBlended" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( class Texture** )( params + 0 ) = Tex;
				*( float* )( params + 4 ) = Scale;
				*( byte* )( params + 8 ) = Blend;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void* MakeIcon( class Texture* Texture, float U, float V, float UL, float VL )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Canvas.MakeIcon" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( class Texture** )( params + 0 ) = Texture;
				*( float* )( params + 4 ) = U;
				*( float* )( params + 8 ) = V;
				*( float* )( params + 12 ) = UL;
				*( float* )( params + 16 ) = VL;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			void DrawIcon( void* Icon, float X, float Y, float Scale )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Canvas.DrawIcon" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( void** )( params + 0 ) = Icon;
				*( float* )( params + 20 ) = X;
				*( float* )( params + 24 ) = Y;
				*( float* )( params + 28 ) = Scale;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DrawRect( float RectX, float RectY, class Texture* Tex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Canvas.DrawRect" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( float* )( params + 0 ) = RectX;
				*( float* )( params + 4 ) = RectY;
				*( class Texture** )( params + 8 ) = Tex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DrawBox( float Width, float Height )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Canvas.DrawBox" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( float* )( params + 0 ) = Width;
				*( float* )( params + 4 ) = Height;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetDrawColorStruct( void* C )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Canvas.SetDrawColorStruct" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( void** )( params + 0 ) = C;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Draw2DLine( float X1, float Y1, float X2, float Y2, void* LineColor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Canvas.Draw2DLine" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( float* )( params + 0 ) = X1;
				*( float* )( params + 4 ) = Y1;
				*( float* )( params + 8 ) = X2;
				*( float* )( params + 12 ) = Y2;
				*( void** )( params + 16 ) = LineColor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DrawTextureLine( Vector StartPoint, Vector EndPoint, float Perc, float Width, void* LineColor, class Texture* LineTexture, float U, float V, float UL, float VL )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Canvas.DrawTextureLine" );
				byte *params = ( byte* )( malloc( 56 ) );
				*( Vector* )( params + 0 ) = StartPoint;
				*( Vector* )( params + 12 ) = EndPoint;
				*( float* )( params + 24 ) = Perc;
				*( float* )( params + 28 ) = Width;
				*( void** )( params + 32 ) = LineColor;
				*( class Texture** )( params + 36 ) = LineTexture;
				*( float* )( params + 40 ) = U;
				*( float* )( params + 44 ) = V;
				*( float* )( params + 48 ) = UL;
				*( float* )( params + 52 ) = VL;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DrawTextureDoubleLine( Vector StartPoint, Vector EndPoint, float Perc, float Spacing, float Width, void* LineColor, void* AltLineColor, class Texture* Tex, float U, float V, float UL, float VL )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Canvas.DrawTextureDoubleLine" );
				byte *params = ( byte* )( malloc( 64 ) );
				*( Vector* )( params + 0 ) = StartPoint;
				*( Vector* )( params + 12 ) = EndPoint;
				*( float* )( params + 24 ) = Perc;
				*( float* )( params + 28 ) = Spacing;
				*( float* )( params + 32 ) = Width;
				*( void** )( params + 36 ) = LineColor;
				*( void** )( params + 40 ) = AltLineColor;
				*( class Texture** )( params + 44 ) = Tex;
				*( float* )( params + 48 ) = U;
				*( float* )( params + 52 ) = V;
				*( float* )( params + 56 ) = UL;
				*( float* )( params + 60 ) = VL;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DrawDebugGraph( ScriptArray< wchar_t > Title, float ValueX, float ValueY, float UL_X, float UL_Y, float W, float H, void* RangeX, void* RangeY )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Canvas.DrawDebugGraph" );
				byte *params = ( byte* )( malloc( 52 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = Title;
				*( float* )( params + 12 ) = ValueX;
				*( float* )( params + 16 ) = ValueY;
				*( float* )( params + 20 ) = UL_X;
				*( float* )( params + 24 ) = UL_Y;
				*( float* )( params + 28 ) = W;
				*( float* )( params + 32 ) = H;
				*( void** )( params + 36 ) = RangeX;
				*( void** )( params + 44 ) = RangeY;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
